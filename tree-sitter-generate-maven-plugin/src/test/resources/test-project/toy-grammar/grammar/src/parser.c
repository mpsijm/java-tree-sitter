#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 12
#define STATE_COUNT 23
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 15
#define ALIAS_COUNT 0
#define TOKEN_COUNT 8
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 5

enum {
  anon_sym_if = 1,
  anon_sym_else = 2,
  anon_sym_EQ = 3,
  anon_sym_PLUS = 4,
  anon_sym_STAR = 5,
  sym_num = 6,
  sym_id = 7,
  sym_sourceFile = 8,
  sym_stmt = 9,
  sym_ifstmt = 10,
  sym_assignstmt = 11,
  sym_arith = 12,
  sym_plus = 13,
  sym_mult = 14,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_if] = "if",
  [anon_sym_else] = "else",
  [anon_sym_EQ] = "=",
  [anon_sym_PLUS] = "+",
  [anon_sym_STAR] = "*",
  [sym_num] = "num",
  [sym_id] = "id",
  [sym_sourceFile] = "sourceFile",
  [sym_stmt] = "stmt",
  [sym_ifstmt] = "ifstmt",
  [sym_assignstmt] = "assignstmt",
  [sym_arith] = "arith",
  [sym_plus] = "plus",
  [sym_mult] = "mult",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_if] = anon_sym_if,
  [anon_sym_else] = anon_sym_else,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_STAR] = anon_sym_STAR,
  [sym_num] = sym_num,
  [sym_id] = sym_id,
  [sym_sourceFile] = sym_sourceFile,
  [sym_stmt] = sym_stmt,
  [sym_ifstmt] = sym_ifstmt,
  [sym_assignstmt] = sym_assignstmt,
  [sym_arith] = sym_arith,
  [sym_plus] = sym_plus,
  [sym_mult] = sym_mult,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_if] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_else] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [sym_num] = {
    .visible = true,
    .named = true,
  },
  [sym_id] = {
    .visible = true,
    .named = true,
  },
  [sym_sourceFile] = {
    .visible = true,
    .named = true,
  },
  [sym_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_ifstmt] = {
    .visible = true,
    .named = true,
  },
  [sym_assignstmt] = {
    .visible = true,
    .named = true,
  },
  [sym_arith] = {
    .visible = true,
    .named = true,
  },
  [sym_plus] = {
    .visible = true,
    .named = true,
  },
  [sym_mult] = {
    .visible = true,
    .named = true,
  },
};

static TSSymbol ts_alias_sequences[1][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(7);
      if (lookahead == '*') ADVANCE(13);
      if (lookahead == '+') ADVANCE(12);
      if (lookahead == '=') ADVANCE(11);
      if (lookahead == 'e') ADVANCE(4);
      if (lookahead == 'i') ADVANCE(3);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(14);
      END_STATE();
    case 1:
      if (lookahead == '*') ADVANCE(13);
      if (lookahead == '+') ADVANCE(12);
      if (lookahead == 'i') ADVANCE(15);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(16);
      END_STATE();
    case 2:
      if (lookahead == 'e') ADVANCE(10);
      END_STATE();
    case 3:
      if (lookahead == 'f') ADVANCE(8);
      END_STATE();
    case 4:
      if (lookahead == 'l') ADVANCE(5);
      END_STATE();
    case 5:
      if (lookahead == 's') ADVANCE(2);
      END_STATE();
    case 6:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(6)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(14);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(16);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(anon_sym_if);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(16);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(anon_sym_else);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(sym_num);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(14);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == 'f') ADVANCE(9);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(16);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym_id);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(16);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 1},
  [2] = {.lex_state = 1},
  [3] = {.lex_state = 6},
  [4] = {.lex_state = 6},
  [5] = {.lex_state = 6},
  [6] = {.lex_state = 6},
  [7] = {.lex_state = 1},
  [8] = {.lex_state = 6},
  [9] = {.lex_state = 6},
  [10] = {.lex_state = 1},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 1},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_if] = ACTIONS(1),
    [anon_sym_else] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [sym_num] = ACTIONS(1),
  },
  [1] = {
    [sym_sourceFile] = STATE(22),
    [sym_stmt] = STATE(21),
    [sym_ifstmt] = STATE(18),
    [sym_assignstmt] = STATE(18),
    [anon_sym_if] = ACTIONS(3),
    [sym_id] = ACTIONS(5),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 6,
    ACTIONS(3), 1,
      anon_sym_if,
    ACTIONS(5), 1,
      sym_id,
    ACTIONS(7), 1,
      anon_sym_PLUS,
    ACTIONS(9), 1,
      anon_sym_STAR,
    STATE(17), 1,
      sym_stmt,
    STATE(18), 2,
      sym_ifstmt,
      sym_assignstmt,
  [20] = 3,
    STATE(13), 1,
      sym_arith,
    ACTIONS(11), 2,
      sym_num,
      sym_id,
    STATE(11), 2,
      sym_plus,
      sym_mult,
  [32] = 3,
    STATE(2), 1,
      sym_arith,
    ACTIONS(11), 2,
      sym_num,
      sym_id,
    STATE(11), 2,
      sym_plus,
      sym_mult,
  [44] = 3,
    STATE(16), 1,
      sym_arith,
    ACTIONS(13), 2,
      sym_num,
      sym_id,
    STATE(14), 2,
      sym_plus,
      sym_mult,
  [56] = 3,
    STATE(15), 1,
      sym_arith,
    ACTIONS(13), 2,
      sym_num,
      sym_id,
    STATE(14), 2,
      sym_plus,
      sym_mult,
  [68] = 4,
    ACTIONS(3), 1,
      anon_sym_if,
    ACTIONS(5), 1,
      sym_id,
    STATE(19), 1,
      sym_stmt,
    STATE(18), 2,
      sym_ifstmt,
      sym_assignstmt,
  [82] = 3,
    STATE(10), 1,
      sym_arith,
    ACTIONS(11), 2,
      sym_num,
      sym_id,
    STATE(11), 2,
      sym_plus,
      sym_mult,
  [94] = 3,
    STATE(12), 1,
      sym_arith,
    ACTIONS(13), 2,
      sym_num,
      sym_id,
    STATE(14), 2,
      sym_plus,
      sym_mult,
  [106] = 2,
    ACTIONS(15), 2,
      anon_sym_if,
      sym_id,
    ACTIONS(17), 2,
      anon_sym_PLUS,
      anon_sym_STAR,
  [115] = 2,
    ACTIONS(19), 2,
      anon_sym_if,
      sym_id,
    ACTIONS(21), 2,
      anon_sym_PLUS,
      anon_sym_STAR,
  [124] = 3,
    ACTIONS(25), 1,
      anon_sym_PLUS,
    ACTIONS(27), 1,
      anon_sym_STAR,
    ACTIONS(23), 2,
      ts_builtin_sym_end,
      anon_sym_else,
  [135] = 3,
    ACTIONS(9), 1,
      anon_sym_STAR,
    ACTIONS(31), 1,
      anon_sym_PLUS,
    ACTIONS(29), 2,
      anon_sym_if,
      sym_id,
  [146] = 1,
    ACTIONS(21), 4,
      ts_builtin_sym_end,
      anon_sym_else,
      anon_sym_PLUS,
      anon_sym_STAR,
  [153] = 2,
    ACTIONS(27), 1,
      anon_sym_STAR,
    ACTIONS(31), 3,
      ts_builtin_sym_end,
      anon_sym_else,
      anon_sym_PLUS,
  [162] = 1,
    ACTIONS(17), 4,
      ts_builtin_sym_end,
      anon_sym_else,
      anon_sym_PLUS,
      anon_sym_STAR,
  [169] = 2,
    ACTIONS(33), 1,
      ts_builtin_sym_end,
    ACTIONS(35), 1,
      anon_sym_else,
  [176] = 1,
    ACTIONS(37), 2,
      ts_builtin_sym_end,
      anon_sym_else,
  [181] = 1,
    ACTIONS(39), 2,
      ts_builtin_sym_end,
      anon_sym_else,
  [186] = 1,
    ACTIONS(41), 1,
      anon_sym_EQ,
  [190] = 1,
    ACTIONS(43), 1,
      ts_builtin_sym_end,
  [194] = 1,
    ACTIONS(45), 1,
      ts_builtin_sym_end,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 20,
  [SMALL_STATE(4)] = 32,
  [SMALL_STATE(5)] = 44,
  [SMALL_STATE(6)] = 56,
  [SMALL_STATE(7)] = 68,
  [SMALL_STATE(8)] = 82,
  [SMALL_STATE(9)] = 94,
  [SMALL_STATE(10)] = 106,
  [SMALL_STATE(11)] = 115,
  [SMALL_STATE(12)] = 124,
  [SMALL_STATE(13)] = 135,
  [SMALL_STATE(14)] = 146,
  [SMALL_STATE(15)] = 153,
  [SMALL_STATE(16)] = 162,
  [SMALL_STATE(17)] = 169,
  [SMALL_STATE(18)] = 176,
  [SMALL_STATE(19)] = 181,
  [SMALL_STATE(20)] = 186,
  [SMALL_STATE(21)] = 190,
  [SMALL_STATE(22)] = 194,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [15] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_mult, 3),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_mult, 3),
  [19] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arith, 1),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arith, 1),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignstmt, 3),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [29] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_plus, 3),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_plus, 3),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ifstmt, 3),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_stmt, 1),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ifstmt, 5),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_sourceFile, 1),
  [45] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_toy(void) {
  static TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .parse_table = (const uint16_t *)ts_parse_table,
    .parse_actions = ts_parse_actions,
    .lex_modes = ts_lex_modes,
    .alias_sequences = (const TSSymbol *)ts_alias_sequences,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .lex_fn = ts_lex,
    .field_count = FIELD_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .small_parse_table = (const uint16_t *)ts_small_parse_table,
    .small_parse_table_map = (const uint32_t *)ts_small_parse_table_map,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .state_count = STATE_COUNT,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
