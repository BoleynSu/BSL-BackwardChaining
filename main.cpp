#include <fstream>
#include <iostream>

#include "expr.h"
#include "lex.h"
#include "parse.h"
#include "solver.h"

using namespace std;

int main(int argc, char* argv[]) {
  ifstream rules(argv[1]);
  Parser rules_parser(rules), quries_parser(cin);
  Solver solver(rules_parser.parse());
  while (quries_parser.match(CONST)) {
    auto expr = quries_parser.parse_expr();
    cout << (solver.solve(expr) ? "yes" : "no") << endl;
    quries_parser.expect(DOT);
  }
  quries_parser.expect(END);
}
