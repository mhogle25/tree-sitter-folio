// External scanner for the folio grammar.
//
// Produces two tokens that folio's context-sensitive lexing needs and a regex
// cannot express:
//
//   TEXT       - a run of dialogue, mirroring folio/src/lexer.zig's
//                `scanPlainText`: a `#`/`%`/`@` is only a sigil when it
//                prefixes a block/string, and `::`/`;;` are structural only at
//                the start of a run (i.e. line start, since runs begin after
//                whitespace extras).
//
//   BLOCK_BODY - the lish inside a `{...}` block, found by the same boundary
//                logic as lish/src/boundary.zig (open='{'): depth-tracked over
//                nested `{`/`}`, skipping a `}` that sits inside a lish string
//                or a `##` comment. Stops at (without consuming) the block's
//                own closing `}`.
//
// A streaming tree-sitter scanner cannot call lish's shared boundary finder
// (no buffer; ships as C/WASM, can't link Zig), so it keeps its own scan, held
// to the shared corpus at lish/src/scanner_corpus/.

#include "tree_sitter/parser.h"
#include "../common/constants.h"

enum TokenType {
    TEXT,
    BLOCK_BODY,
};

// Structural characters come from folio's token.zig via the generated header
// (`FOLIO_*`), so they cannot drift from the language's real lexer. Aliased to
// shorter names to keep the scan code readable.
#define BLOCK_OPEN     FOLIO_BLOCK_OPEN
#define BLOCK_CLOSE    FOLIO_BLOCK_CLOSE
#define QUOTE_DOUBLE   FOLIO_QUOTE_DOUBLE
#define QUOTE_SINGLE   FOLIO_QUOTE_SINGLE
#define BACKSLASH      FOLIO_BACKSLASH
#define INSTANT_SIGIL  FOLIO_INSTANT_SIGIL
#define DEFER_SIGIL    FOLIO_DEFER_SIGIL
#define CHAR_SIGIL     FOLIO_CHAR_SIGIL
#define SCENE_SIGIL    FOLIO_SCENE_SIGIL
#define BEAT_SIGIL     FOLIO_BEAT_SIGIL
// Newlines are universal (not part of folio's structural set). Inside a block
// the content is lish, whose comment opener `##` is the instant-sigil byte.
#define NEWLINE_LF     '\n'
#define NEWLINE_CR     '\r'
#define LISH_COMMENT   FOLIO_INSTANT_SIGIL
// folio's line comment is the 2-char string `//` (token.COMMENT). Its opener is
// not in the generated single-char set, so name the byte here.
#define COMMENT_OPEN   '/'

static inline bool is_inline_space(int32_t c) {
    return c == ' ' || c == '\t' || c == NEWLINE_LF || c == NEWLINE_CR;
}

// Skip a lish string whose opening quote has just been consumed (handles `\X`
// escapes the same way lish's lexer does). Returns after the close quote or EOF.
static void skip_lish_string(TSLexer *lexer, int32_t quote) {
    while (!lexer->eof(lexer)) {
        int32_t c = lexer->lookahead;
        if (c == BACKSLASH) {
            lexer->advance(lexer, false);
            if (lexer->eof(lexer)) return;
            lexer->advance(lexer, false);
            continue;
        }
        if (c == quote) {
            lexer->advance(lexer, false);
            return;
        }
        lexer->advance(lexer, false);
    }
}

// Skip a lish comment whose opening `##` has just been consumed. Ends at a
// matching `##`, a newline, or EOF.
static void skip_lish_comment(TSLexer *lexer) {
    while (!lexer->eof(lexer)) {
        int32_t c = lexer->lookahead;
        if (c == NEWLINE_LF || c == NEWLINE_CR) return;
        if (c == LISH_COMMENT) {
            lexer->advance(lexer, false);
            if (lexer->eof(lexer)) return;
            if (lexer->lookahead == LISH_COMMENT) {
                lexer->advance(lexer, false);
                return;
            }
            continue;
        }
        lexer->advance(lexer, false);
    }
}

static bool scan_text(TSLexer *lexer) {
    // Skip leading whitespace (including newlines) ourselves, like the other
    // scanners. tree-sitter calls the scanner positioned on the whitespace that
    // separates lines; without this it would break immediately, hand back to the
    // internal lexer, and the first char of the next line would be errored.
    while (!lexer->eof(lexer)
           && (lexer->lookahead == ' ' || lexer->lookahead == '\t'
               || lexer->lookahead == NEWLINE_LF || lexer->lookahead == NEWLINE_CR)) {
        lexer->advance(lexer, true);
    }

    bool consumed = false;

    while (!lexer->eof(lexer)) {
        int32_t c = lexer->lookahead;

        if (c == NEWLINE_LF || c == NEWLINE_CR) break;  // a line ends the run
        if (c == BLOCK_OPEN) break;                     // `{` begins a block

        if (c == SCENE_SIGIL || c == BEAT_SIGIL || c == COMMENT_OPEN) {
            // A doubled `::` / `;;` / `//` at the *start* of the run is
            // structural (scene header, beat break, line comment); hand it back
            // so the grammar / comment extra can take it. Mid-run it is text.
            lexer->advance(lexer, false);
            if (!consumed && lexer->lookahead == c) return false;
            lexer->mark_end(lexer);
            consumed = true;
            continue;
        }

        if (c == INSTANT_SIGIL || c == CHAR_SIGIL || c == DEFER_SIGIL) {
            lexer->advance(lexer, false);
            int32_t n = lexer->lookahead;
            bool starts_form = (c == DEFER_SIGIL)
                ? (n == BLOCK_OPEN)
                : (n == BLOCK_OPEN || n == QUOTE_DOUBLE || n == QUOTE_SINGLE);
            if (starts_form) break;   // hand the sigil to the grammar; text ends before it
            lexer->mark_end(lexer);   // a lone sigil is plain text
            consumed = true;
            continue;
        }

        lexer->advance(lexer, false);
        lexer->mark_end(lexer);
        consumed = true;
    }

    if (!consumed) return false;
    lexer->result_symbol = TEXT;
    return true;
}

static bool scan_block_body(TSLexer *lexer) {
    while (!lexer->eof(lexer) && is_inline_space(lexer->lookahead)) {
        lexer->advance(lexer, true);
    }
    if (lexer->eof(lexer) || lexer->lookahead == BLOCK_CLOSE) return false; // empty block

    int depth = 0;
    bool consumed = false;

    while (!lexer->eof(lexer)) {
        int32_t c = lexer->lookahead;

        if (c == QUOTE_DOUBLE || c == QUOTE_SINGLE) {
            lexer->advance(lexer, false);
            skip_lish_string(lexer, c);
            lexer->mark_end(lexer);
            consumed = true;
            continue;
        }

        if (c == LISH_COMMENT) {
            lexer->advance(lexer, false);
            if (!lexer->eof(lexer) && lexer->lookahead == LISH_COMMENT) {
                lexer->advance(lexer, false);
                skip_lish_comment(lexer);
                consumed = true;
                continue;
            }
            lexer->mark_end(lexer);  // stray `#`
            consumed = true;
            continue;
        }

        if (c == BLOCK_OPEN) {
            depth++;
            lexer->advance(lexer, false);
            lexer->mark_end(lexer);
            consumed = true;
            continue;
        }

        if (c == BLOCK_CLOSE) {
            if (depth == 0) break;   // the block's own closing brace
            depth--;
            lexer->advance(lexer, false);
            lexer->mark_end(lexer);
            consumed = true;
            continue;
        }

        lexer->advance(lexer, false);
        if (!is_inline_space(c)) lexer->mark_end(lexer);  // trim trailing space
        consumed = true;
    }

    if (!consumed) return false;
    lexer->result_symbol = BLOCK_BODY;
    return true;
}

bool tree_sitter_folio_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
    (void)payload;
    // TEXT is checked first: `block_body` is only ever valid inside `{...}`,
    // where TEXT is not a valid node, so preferring TEXT keeps `block_body` from
    // firing (and greedily eating to EOF) at an ordinary dialogue position where
    // the parser speculatively marks both valid.
    if (valid_symbols[TEXT]) return scan_text(lexer);
    if (valid_symbols[BLOCK_BODY]) return scan_block_body(lexer);
    return false;
}

void *tree_sitter_folio_external_scanner_create(void) { return NULL; }
void tree_sitter_folio_external_scanner_destroy(void *payload) { (void)payload; }
unsigned tree_sitter_folio_external_scanner_serialize(void *payload, char *buffer) {
    (void)payload;
    (void)buffer;
    return 0;
}
void tree_sitter_folio_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {
    (void)payload;
    (void)buffer;
    (void)length;
}
