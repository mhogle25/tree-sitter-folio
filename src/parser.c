#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 33
#define LARGE_STATE_COUNT 7
#define SYMBOL_COUNT 31
#define ALIAS_COUNT 0
#define TOKEN_COUNT 16
#define EXTERNAL_TOKEN_COUNT 2
#define FIELD_COUNT 1
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 2

enum ts_symbol_identifiers {
  sym_comment = 1,
  anon_sym_COLON_COLON = 2,
  sym_scene_name = 3,
  sym_beat_break = 4,
  anon_sym_LBRACE = 5,
  anon_sym_RBRACE = 6,
  anon_sym_POUND_LBRACE = 7,
  anon_sym_PERCENT_LBRACE = 8,
  anon_sym_AT_LBRACE = 9,
  anon_sym_POUND = 10,
  anon_sym_AT = 11,
  sym_double_string = 12,
  sym_single_string = 13,
  sym_text = 14,
  sym_block_body = 15,
  sym_source_file = 16,
  sym_scene = 17,
  sym_scene_header = 18,
  sym_beat = 19,
  sym__node = 20,
  sym_block = 21,
  sym_instant_block = 22,
  sym_defer_block = 23,
  sym_char_block = 24,
  sym_instant_string = 25,
  sym_char_string = 26,
  sym__string = 27,
  aux_sym_source_file_repeat1 = 28,
  aux_sym_scene_repeat1 = 29,
  aux_sym_beat_repeat1 = 30,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_comment] = "comment",
  [anon_sym_COLON_COLON] = "::",
  [sym_scene_name] = "scene_name",
  [sym_beat_break] = "beat_break",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_POUND_LBRACE] = "#{",
  [anon_sym_PERCENT_LBRACE] = "%{",
  [anon_sym_AT_LBRACE] = "@{",
  [anon_sym_POUND] = "#",
  [anon_sym_AT] = "@",
  [sym_double_string] = "double_string",
  [sym_single_string] = "single_string",
  [sym_text] = "text",
  [sym_block_body] = "block_body",
  [sym_source_file] = "source_file",
  [sym_scene] = "scene",
  [sym_scene_header] = "scene_header",
  [sym_beat] = "beat",
  [sym__node] = "_node",
  [sym_block] = "block",
  [sym_instant_block] = "instant_block",
  [sym_defer_block] = "defer_block",
  [sym_char_block] = "char_block",
  [sym_instant_string] = "instant_string",
  [sym_char_string] = "char_string",
  [sym__string] = "_string",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_scene_repeat1] = "scene_repeat1",
  [aux_sym_beat_repeat1] = "beat_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_comment] = sym_comment,
  [anon_sym_COLON_COLON] = anon_sym_COLON_COLON,
  [sym_scene_name] = sym_scene_name,
  [sym_beat_break] = sym_beat_break,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_POUND_LBRACE] = anon_sym_POUND_LBRACE,
  [anon_sym_PERCENT_LBRACE] = anon_sym_PERCENT_LBRACE,
  [anon_sym_AT_LBRACE] = anon_sym_AT_LBRACE,
  [anon_sym_POUND] = anon_sym_POUND,
  [anon_sym_AT] = anon_sym_AT,
  [sym_double_string] = sym_double_string,
  [sym_single_string] = sym_single_string,
  [sym_text] = sym_text,
  [sym_block_body] = sym_block_body,
  [sym_source_file] = sym_source_file,
  [sym_scene] = sym_scene,
  [sym_scene_header] = sym_scene_header,
  [sym_beat] = sym_beat,
  [sym__node] = sym__node,
  [sym_block] = sym_block,
  [sym_instant_block] = sym_instant_block,
  [sym_defer_block] = sym_defer_block,
  [sym_char_block] = sym_char_block,
  [sym_instant_string] = sym_instant_string,
  [sym_char_string] = sym_char_string,
  [sym__string] = sym__string,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_scene_repeat1] = aux_sym_scene_repeat1,
  [aux_sym_beat_repeat1] = aux_sym_beat_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_COLON_COLON] = {
    .visible = true,
    .named = false,
  },
  [sym_scene_name] = {
    .visible = true,
    .named = true,
  },
  [sym_beat_break] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_POUND_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PERCENT_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AT_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_POUND] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AT] = {
    .visible = true,
    .named = false,
  },
  [sym_double_string] = {
    .visible = true,
    .named = true,
  },
  [sym_single_string] = {
    .visible = true,
    .named = true,
  },
  [sym_text] = {
    .visible = true,
    .named = true,
  },
  [sym_block_body] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_scene] = {
    .visible = true,
    .named = true,
  },
  [sym_scene_header] = {
    .visible = true,
    .named = true,
  },
  [sym_beat] = {
    .visible = true,
    .named = true,
  },
  [sym__node] = {
    .visible = false,
    .named = true,
  },
  [sym_block] = {
    .visible = true,
    .named = true,
  },
  [sym_instant_block] = {
    .visible = true,
    .named = true,
  },
  [sym_defer_block] = {
    .visible = true,
    .named = true,
  },
  [sym_char_block] = {
    .visible = true,
    .named = true,
  },
  [sym_instant_string] = {
    .visible = true,
    .named = true,
  },
  [sym_char_string] = {
    .visible = true,
    .named = true,
  },
  [sym__string] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_scene_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_beat_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_name = 1,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_name] = "name",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_name, 1},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(10);
      ADVANCE_MAP(
        '"', 2,
        '#', 22,
        '%', 7,
        '\'', 3,
        '/', 4,
        ':', 5,
        ';', 6,
        '@', 23,
        '{', 17,
        '}', 18,
      );
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(1);
      if (lookahead == '/') ADVANCE(13);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(14);
      if (lookahead != 0) ADVANCE(15);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(24);
      if (lookahead == '\\') ADVANCE(8);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 3:
      if (lookahead == '\'') ADVANCE(25);
      if (lookahead == '\\') ADVANCE(9);
      if (lookahead != 0) ADVANCE(3);
      END_STATE();
    case 4:
      if (lookahead == '/') ADVANCE(11);
      END_STATE();
    case 5:
      if (lookahead == ':') ADVANCE(12);
      END_STATE();
    case 6:
      if (lookahead == ';') ADVANCE(16);
      END_STATE();
    case 7:
      if (lookahead == '{') ADVANCE(20);
      END_STATE();
    case 8:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(2);
      END_STATE();
    case 9:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(3);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(11);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_COLON_COLON);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym_scene_name);
      if (lookahead == '/') ADVANCE(11);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(15);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(sym_scene_name);
      if (lookahead == '/') ADVANCE(13);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(14);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(15);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(sym_scene_name);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(15);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym_beat_break);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(16);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_POUND_LBRACE);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_PERCENT_LBRACE);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_AT_LBRACE);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_POUND);
      if (lookahead == '{') ADVANCE(19);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_AT);
      if (lookahead == '{') ADVANCE(21);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym_double_string);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym_single_string);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0, .external_lex_state = 2},
  [3] = {.lex_state = 0, .external_lex_state = 2},
  [4] = {.lex_state = 0, .external_lex_state = 2},
  [5] = {.lex_state = 0, .external_lex_state = 2},
  [6] = {.lex_state = 0, .external_lex_state = 2},
  [7] = {.lex_state = 0, .external_lex_state = 2},
  [8] = {.lex_state = 0, .external_lex_state = 2},
  [9] = {.lex_state = 0, .external_lex_state = 2},
  [10] = {.lex_state = 0, .external_lex_state = 2},
  [11] = {.lex_state = 0, .external_lex_state = 2},
  [12] = {.lex_state = 0, .external_lex_state = 2},
  [13] = {.lex_state = 0, .external_lex_state = 2},
  [14] = {.lex_state = 0, .external_lex_state = 2},
  [15] = {.lex_state = 0, .external_lex_state = 2},
  [16] = {.lex_state = 0, .external_lex_state = 2},
  [17] = {.lex_state = 0, .external_lex_state = 2},
  [18] = {.lex_state = 0, .external_lex_state = 2},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0, .external_lex_state = 3},
  [24] = {.lex_state = 0, .external_lex_state = 3},
  [25] = {.lex_state = 0, .external_lex_state = 3},
  [26] = {.lex_state = 0, .external_lex_state = 3},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 1},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COLON_COLON] = ACTIONS(1),
    [sym_beat_break] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_POUND_LBRACE] = ACTIONS(1),
    [anon_sym_PERCENT_LBRACE] = ACTIONS(1),
    [anon_sym_AT_LBRACE] = ACTIONS(1),
    [anon_sym_POUND] = ACTIONS(1),
    [anon_sym_AT] = ACTIONS(1),
    [sym_double_string] = ACTIONS(1),
    [sym_single_string] = ACTIONS(1),
    [sym_text] = ACTIONS(1),
    [sym_block_body] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(27),
    [sym_scene] = STATE(20),
    [sym_scene_header] = STATE(2),
    [aux_sym_source_file_repeat1] = STATE(20),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COLON_COLON] = ACTIONS(7),
  },
  [2] = {
    [sym_beat] = STATE(3),
    [sym__node] = STATE(6),
    [sym_block] = STATE(6),
    [sym_instant_block] = STATE(6),
    [sym_defer_block] = STATE(6),
    [sym_char_block] = STATE(6),
    [sym_instant_string] = STATE(6),
    [sym_char_string] = STATE(6),
    [aux_sym_scene_repeat1] = STATE(3),
    [aux_sym_beat_repeat1] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(9),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COLON_COLON] = ACTIONS(9),
    [anon_sym_LBRACE] = ACTIONS(11),
    [anon_sym_POUND_LBRACE] = ACTIONS(13),
    [anon_sym_PERCENT_LBRACE] = ACTIONS(15),
    [anon_sym_AT_LBRACE] = ACTIONS(17),
    [anon_sym_POUND] = ACTIONS(19),
    [anon_sym_AT] = ACTIONS(21),
    [sym_text] = ACTIONS(23),
  },
  [3] = {
    [sym_beat] = STATE(4),
    [sym__node] = STATE(6),
    [sym_block] = STATE(6),
    [sym_instant_block] = STATE(6),
    [sym_defer_block] = STATE(6),
    [sym_char_block] = STATE(6),
    [sym_instant_string] = STATE(6),
    [sym_char_string] = STATE(6),
    [aux_sym_scene_repeat1] = STATE(4),
    [aux_sym_beat_repeat1] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(25),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COLON_COLON] = ACTIONS(25),
    [anon_sym_LBRACE] = ACTIONS(11),
    [anon_sym_POUND_LBRACE] = ACTIONS(13),
    [anon_sym_PERCENT_LBRACE] = ACTIONS(15),
    [anon_sym_AT_LBRACE] = ACTIONS(17),
    [anon_sym_POUND] = ACTIONS(19),
    [anon_sym_AT] = ACTIONS(21),
    [sym_text] = ACTIONS(23),
  },
  [4] = {
    [sym_beat] = STATE(4),
    [sym__node] = STATE(6),
    [sym_block] = STATE(6),
    [sym_instant_block] = STATE(6),
    [sym_defer_block] = STATE(6),
    [sym_char_block] = STATE(6),
    [sym_instant_string] = STATE(6),
    [sym_char_string] = STATE(6),
    [aux_sym_scene_repeat1] = STATE(4),
    [aux_sym_beat_repeat1] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(27),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COLON_COLON] = ACTIONS(27),
    [anon_sym_LBRACE] = ACTIONS(29),
    [anon_sym_POUND_LBRACE] = ACTIONS(32),
    [anon_sym_PERCENT_LBRACE] = ACTIONS(35),
    [anon_sym_AT_LBRACE] = ACTIONS(38),
    [anon_sym_POUND] = ACTIONS(41),
    [anon_sym_AT] = ACTIONS(44),
    [sym_text] = ACTIONS(47),
  },
  [5] = {
    [sym__node] = STATE(5),
    [sym_block] = STATE(5),
    [sym_instant_block] = STATE(5),
    [sym_defer_block] = STATE(5),
    [sym_char_block] = STATE(5),
    [sym_instant_string] = STATE(5),
    [sym_char_string] = STATE(5),
    [aux_sym_beat_repeat1] = STATE(5),
    [sym_comment] = ACTIONS(3),
    [sym_beat_break] = ACTIONS(50),
    [anon_sym_LBRACE] = ACTIONS(52),
    [anon_sym_POUND_LBRACE] = ACTIONS(55),
    [anon_sym_PERCENT_LBRACE] = ACTIONS(58),
    [anon_sym_AT_LBRACE] = ACTIONS(61),
    [anon_sym_POUND] = ACTIONS(64),
    [anon_sym_AT] = ACTIONS(67),
    [sym_text] = ACTIONS(70),
  },
  [6] = {
    [sym__node] = STATE(5),
    [sym_block] = STATE(5),
    [sym_instant_block] = STATE(5),
    [sym_defer_block] = STATE(5),
    [sym_char_block] = STATE(5),
    [sym_instant_string] = STATE(5),
    [sym_char_string] = STATE(5),
    [aux_sym_beat_repeat1] = STATE(5),
    [sym_comment] = ACTIONS(3),
    [sym_beat_break] = ACTIONS(73),
    [anon_sym_LBRACE] = ACTIONS(11),
    [anon_sym_POUND_LBRACE] = ACTIONS(13),
    [anon_sym_PERCENT_LBRACE] = ACTIONS(15),
    [anon_sym_AT_LBRACE] = ACTIONS(17),
    [anon_sym_POUND] = ACTIONS(19),
    [anon_sym_AT] = ACTIONS(21),
    [sym_text] = ACTIONS(75),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(79), 2,
      anon_sym_POUND,
      anon_sym_AT,
    ACTIONS(77), 7,
      sym_text,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_LBRACE,
      anon_sym_POUND_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_AT_LBRACE,
  [17] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(83), 2,
      anon_sym_POUND,
      anon_sym_AT,
    ACTIONS(81), 7,
      sym_text,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_LBRACE,
      anon_sym_POUND_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_AT_LBRACE,
  [34] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(87), 2,
      anon_sym_POUND,
      anon_sym_AT,
    ACTIONS(85), 6,
      sym_text,
      sym_beat_break,
      anon_sym_LBRACE,
      anon_sym_POUND_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_AT_LBRACE,
  [50] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(91), 2,
      anon_sym_POUND,
      anon_sym_AT,
    ACTIONS(89), 6,
      sym_text,
      sym_beat_break,
      anon_sym_LBRACE,
      anon_sym_POUND_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_AT_LBRACE,
  [66] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(95), 2,
      anon_sym_POUND,
      anon_sym_AT,
    ACTIONS(93), 6,
      sym_text,
      sym_beat_break,
      anon_sym_LBRACE,
      anon_sym_POUND_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_AT_LBRACE,
  [82] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(99), 2,
      anon_sym_POUND,
      anon_sym_AT,
    ACTIONS(97), 6,
      sym_text,
      sym_beat_break,
      anon_sym_LBRACE,
      anon_sym_POUND_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_AT_LBRACE,
  [98] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(103), 2,
      anon_sym_POUND,
      anon_sym_AT,
    ACTIONS(101), 6,
      sym_text,
      sym_beat_break,
      anon_sym_LBRACE,
      anon_sym_POUND_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_AT_LBRACE,
  [114] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(107), 2,
      anon_sym_POUND,
      anon_sym_AT,
    ACTIONS(105), 6,
      sym_text,
      sym_beat_break,
      anon_sym_LBRACE,
      anon_sym_POUND_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_AT_LBRACE,
  [130] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(111), 2,
      anon_sym_POUND,
      anon_sym_AT,
    ACTIONS(109), 6,
      sym_text,
      sym_beat_break,
      anon_sym_LBRACE,
      anon_sym_POUND_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_AT_LBRACE,
  [146] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(115), 2,
      anon_sym_POUND,
      anon_sym_AT,
    ACTIONS(113), 6,
      sym_text,
      sym_beat_break,
      anon_sym_LBRACE,
      anon_sym_POUND_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_AT_LBRACE,
  [162] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(119), 2,
      anon_sym_POUND,
      anon_sym_AT,
    ACTIONS(117), 6,
      sym_text,
      sym_beat_break,
      anon_sym_LBRACE,
      anon_sym_POUND_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_AT_LBRACE,
  [178] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(123), 2,
      anon_sym_POUND,
      anon_sym_AT,
    ACTIONS(121), 6,
      sym_text,
      sym_beat_break,
      anon_sym_LBRACE,
      anon_sym_POUND_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_AT_LBRACE,
  [194] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(125), 1,
      ts_builtin_sym_end,
    ACTIONS(127), 1,
      anon_sym_COLON_COLON,
    STATE(2), 1,
      sym_scene_header,
    STATE(19), 2,
      sym_scene,
      aux_sym_source_file_repeat1,
  [211] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_COLON_COLON,
    ACTIONS(130), 1,
      ts_builtin_sym_end,
    STATE(2), 1,
      sym_scene_header,
    STATE(19), 2,
      sym_scene,
      aux_sym_source_file_repeat1,
  [228] = 3,
    ACTIONS(3), 1,
      sym_comment,
    STATE(14), 1,
      sym__string,
    ACTIONS(132), 2,
      sym_double_string,
      sym_single_string,
  [239] = 3,
    ACTIONS(3), 1,
      sym_comment,
    STATE(16), 1,
      sym__string,
    ACTIONS(134), 2,
      sym_double_string,
      sym_single_string,
  [250] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(136), 1,
      anon_sym_RBRACE,
    ACTIONS(138), 1,
      sym_block_body,
  [260] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(140), 1,
      anon_sym_RBRACE,
    ACTIONS(142), 1,
      sym_block_body,
  [270] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(144), 1,
      anon_sym_RBRACE,
    ACTIONS(146), 1,
      sym_block_body,
  [280] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(148), 1,
      anon_sym_RBRACE,
    ACTIONS(150), 1,
      sym_block_body,
  [290] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(152), 1,
      ts_builtin_sym_end,
  [297] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(154), 1,
      anon_sym_RBRACE,
  [304] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(156), 1,
      anon_sym_RBRACE,
  [311] = 2,
    ACTIONS(158), 1,
      sym_comment,
    ACTIONS(160), 1,
      sym_scene_name,
  [318] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(162), 1,
      anon_sym_RBRACE,
  [325] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(164), 1,
      anon_sym_RBRACE,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(7)] = 0,
  [SMALL_STATE(8)] = 17,
  [SMALL_STATE(9)] = 34,
  [SMALL_STATE(10)] = 50,
  [SMALL_STATE(11)] = 66,
  [SMALL_STATE(12)] = 82,
  [SMALL_STATE(13)] = 98,
  [SMALL_STATE(14)] = 114,
  [SMALL_STATE(15)] = 130,
  [SMALL_STATE(16)] = 146,
  [SMALL_STATE(17)] = 162,
  [SMALL_STATE(18)] = 178,
  [SMALL_STATE(19)] = 194,
  [SMALL_STATE(20)] = 211,
  [SMALL_STATE(21)] = 228,
  [SMALL_STATE(22)] = 239,
  [SMALL_STATE(23)] = 250,
  [SMALL_STATE(24)] = 260,
  [SMALL_STATE(25)] = 270,
  [SMALL_STATE(26)] = 280,
  [SMALL_STATE(27)] = 290,
  [SMALL_STATE(28)] = 297,
  [SMALL_STATE(29)] = 304,
  [SMALL_STATE(30)] = 311,
  [SMALL_STATE(31)] = 318,
  [SMALL_STATE(32)] = 325,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [9] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene, 1, 0, 0),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene, 2, 0, 0),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_scene_repeat1, 2, 0, 0),
  [29] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_scene_repeat1, 2, 0, 0), SHIFT_REPEAT(24),
  [32] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_scene_repeat1, 2, 0, 0), SHIFT_REPEAT(25),
  [35] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_scene_repeat1, 2, 0, 0), SHIFT_REPEAT(23),
  [38] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_scene_repeat1, 2, 0, 0), SHIFT_REPEAT(26),
  [41] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_scene_repeat1, 2, 0, 0), SHIFT_REPEAT(21),
  [44] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_scene_repeat1, 2, 0, 0), SHIFT_REPEAT(22),
  [47] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_scene_repeat1, 2, 0, 0), SHIFT_REPEAT(6),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_beat_repeat1, 2, 0, 0),
  [52] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_beat_repeat1, 2, 0, 0), SHIFT_REPEAT(24),
  [55] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_beat_repeat1, 2, 0, 0), SHIFT_REPEAT(25),
  [58] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_beat_repeat1, 2, 0, 0), SHIFT_REPEAT(23),
  [61] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_beat_repeat1, 2, 0, 0), SHIFT_REPEAT(26),
  [64] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_beat_repeat1, 2, 0, 0), SHIFT_REPEAT(21),
  [67] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_beat_repeat1, 2, 0, 0), SHIFT_REPEAT(22),
  [70] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_beat_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [75] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scene_header, 2, 0, 1),
  [79] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scene_header, 2, 0, 1),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_beat, 2, 0, 0),
  [83] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_beat, 2, 0, 0),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2, 0, 0),
  [87] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 2, 0, 0),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_instant_block, 2, 0, 0),
  [91] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_instant_block, 2, 0, 0),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_defer_block, 2, 0, 0),
  [95] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_defer_block, 2, 0, 0),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 3, 0, 0),
  [99] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 3, 0, 0),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_char_block, 2, 0, 0),
  [103] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_char_block, 2, 0, 0),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_instant_string, 2, 0, 0),
  [107] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_instant_string, 2, 0, 0),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_defer_block, 3, 0, 0),
  [111] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_defer_block, 3, 0, 0),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_char_string, 2, 0, 0),
  [115] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_char_string, 2, 0, 0),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_instant_block, 3, 0, 0),
  [119] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_instant_block, 3, 0, 0),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_char_block, 3, 0, 0),
  [123] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_char_block, 3, 0, 0),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [127] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(30),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [138] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [140] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [142] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [144] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [146] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [150] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [152] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [158] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [160] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [162] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token_text = 0,
  ts_external_token_block_body = 1,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token_text] = sym_text,
  [ts_external_token_block_body] = sym_block_body,
};

static const bool ts_external_scanner_states[4][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token_text] = true,
    [ts_external_token_block_body] = true,
  },
  [2] = {
    [ts_external_token_text] = true,
  },
  [3] = {
    [ts_external_token_block_body] = true,
  },
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_folio_external_scanner_create(void);
void tree_sitter_folio_external_scanner_destroy(void *);
bool tree_sitter_folio_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_folio_external_scanner_serialize(void *, char *);
void tree_sitter_folio_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_folio(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_folio_external_scanner_create,
      tree_sitter_folio_external_scanner_destroy,
      tree_sitter_folio_external_scanner_scan,
      tree_sitter_folio_external_scanner_serialize,
      tree_sitter_folio_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
