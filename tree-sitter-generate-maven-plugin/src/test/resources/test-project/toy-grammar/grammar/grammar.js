module.exports = grammar({
  name: 'toy',

  rules: {
    sourceFile: $ => seq($.stmt),

    stmt: $ => choice($.ifstmt, $.assignstmt),

    ifstmt: $ => prec.right(seq("if", $.arith, $.stmt, optional(seq("else", $.stmt)))),
    assignstmt: $ => seq($.id, "=", $.arith),

    arith: $ => choice($.plus, $.mult, $.num, $.id),

    plus: $ => prec.left(1, seq($.arith, '+', $.arith)),
    mult: $ => prec.left(2, seq($.arith, '*', $.arith)),
    num: $ => /[0-9]+/,
    id: $ => /[A-Za-z_][0-9A-Za-z_]*/,
  }
});
