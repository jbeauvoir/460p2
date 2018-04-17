#include <Lex.h>

int program()
{
  // L_PAREN_T
  static set<string> firsts = {LPAREN_T};
  // lamda, L_PAREN_T
  // how do you include lamda?
  static set<string> follows = {LPAREN_T};
  
}
