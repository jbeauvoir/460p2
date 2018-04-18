/***********************************************************
File: stmt.cpp
Author: Jacques Beauvoir & Aaron Pineda
Description: Contains the stmt non-terminal assoc. with 
rules 7, 8, and 9.

notes:
  - Put in p2file rule notificaiton in proper place
  - check nested loop for rule 9 
  - check if statement check for firsts 
************************************************************/
#include "SyntacticalAnalyzer.h"

int SyntacticalAnalyzer::stmt()
{
        // Variable Declaration 
        int errors = 0;
  	static set<string> firsts = {IDENT_T,LPAREN_T,NUMLIT_T,STRLIT_T,QUOTE_T};
	static set<string> follows = {IDENT_T,LPAREN_T,NUMLIT_T,STRLIT_T,QUOTE_T,
				      RPAREN_T};
	set<string>::iterator itr1 = firsts.find(token);
        set<string>::iterator itr2 = follows.find(token);

	p2file << "Entering stmt function; current token is: " 
		<< lex->GetTokenName (token) << endl;


	// RULE 7
	if ( token == NUMLIT_T || token == QUOTE_T || token == STRLIT_T ) {
	  p2file << "Using Rule 7" << endl;
	  errors += literal();
	}
	// RULE 8
	else if ( token == IDENT_T ) {
	  p2file << "Using Rule 8" << endl;
	  return errors;
	}
	// ****** note 
	// check the rule to see if a nested loop is necessary 
	// RULE 9
	else if ( token == LPAREN_T ) {
	  p2file << "Using Rule 9" << endl;

	  errors += action();

	  if ( token == RPAREN_T ) {
	    lex->GetTokenName (token);
	    p2file << "Exiting RPAREN_T check in stmt function; current token is: "
		   << lex->GetTokenName (token) << endl;
	  }
	  else {
	    cout << "no RPAREN_T" << endl;
	  }
	}
	else {
	  cout << "no firsts" << endl;
	}

	p2file << "Exiting stmt function; current token is: " 
		<< lex->GetTokenName (token) << endl;
	return errors;
}
