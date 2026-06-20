/**
 * tree-sitter grammar for folio (`.folio` dialogue scripts).
 *
 * folio's outer structure is modeled here: scenes (`::name`), beats (`;;`),
 * line comments (`//`), dialogue text, and the sigil forms (`#`/`%`/`@`). The
 * lish embedded in `{...}` blocks is left as an opaque `block_body` token, and
 * `queries/injections.scm` re-parses it with the `lish` grammar, so embedded
 * lish gets the same highlighting as a standalone `.lish` file.
 *
 * Structural characters come from `common/constants.js`, generated from
 * `folio/src/token.zig` by `zig build gen` and vendored by `scripts/sync.js`
 * (mirrors tree-sitter-lish), so the grammar never hand-mirrors folio's lexer.
 *
 * Two tokens come from the external scanner in `src/scanner.c`, because folio's
 * lexing is context sensitive in ways a regex cannot express:
 *   - `text`: a run of dialogue, mirroring `folio/src/lexer.zig`'s
 *     `scanPlainText` (a sigil is only a sigil when it prefixes a block/string;
 *     `::`/`;;` are structural only at line start).
 *   - `block_body`: the lish inside a `{...}` block, found by the same
 *     brace-boundary logic as `lish/src/boundary.zig` (depth-tracked, skipping
 *     `}` inside lish strings and `##` comments).
 */

const C = require('./common/constants');

const SCENE_MARKER = C.SCENE_SIGIL + C.SCENE_SIGIL; // `::`
const BEAT_MARKER = C.BEAT_SIGIL + C.BEAT_SIGIL;    // `;;`

module.exports = grammar({
  name: 'folio',

  externals: $ => [$.text, $.block_body],

  extras: $ => [/[ \t\r\n]+/, $.comment],

  rules: {
    source_file: $ => repeat($.scene),

    // folio line comment: `//` to end of line. (Distinct from lish's `##`.)
    comment: $ => token(seq('//', /[^\n]*/)),

    scene: $ => seq($.scene_header, repeat($.beat)),
    scene_header: $ => seq(SCENE_MARKER, field('name', $.scene_name)),
    scene_name: $ => /[^\n]+/,

    beat: $ => seq(repeat1($._node), $.beat_break),
    // `;;` ends a beat; any trailing content on its line is ignored.
    beat_break: $ => token(seq(BEAT_MARKER, /[^\n]*/)),

    _node: $ => choice(
      $.instant_block,
      $.defer_block,
      $.char_block,
      $.block,
      $.instant_string,
      $.char_string,
      $.text,
    ),

    // Embedded lish. `block_body` (the external token) is the injected lish.
    block:         $ => seq(C.BLOCK_OPEN,                   optional($.block_body), C.BLOCK_CLOSE),
    instant_block: $ => seq(C.INSTANT_SIGIL + C.BLOCK_OPEN, optional($.block_body), C.BLOCK_CLOSE),
    defer_block:   $ => seq(C.DEFER_SIGIL + C.BLOCK_OPEN,   optional($.block_body), C.BLOCK_CLOSE),
    char_block:    $ => seq(C.CHAR_SIGIL + C.BLOCK_OPEN,    optional($.block_body), C.BLOCK_CLOSE),

    // Sigil-prefixed strings: instant display / character label.
    instant_string: $ => seq(C.INSTANT_SIGIL, $._string),
    char_string:    $ => seq(C.CHAR_SIGIL, $._string),
    _string: $ => choice($.double_string, $.single_string),
    double_string: $ => token(seq('"', repeat(choice(/[^"\\]/, /\\./)), '"')),
    single_string: $ => token(seq("'", repeat(choice(/[^'\\]/, /\\./)), "'")),
  },
});
