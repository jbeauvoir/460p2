#include "SyntacticalAnalyzer.h"



/*
  Put in p2file rule notificaiton in proprt place

*/
int SyntacticalAnalyzer::stmt()
{
        int errors = 0;
  	static set<string> firsts = {IDENT_T,LPAREN_T,NUMLIT_T,STRLIT_T,QUOTE_T};
	static set<string> follows = {IDENT_T,LPAREN_T,NUMLIT_T,STRLIT_T,QUOTE_T,
				      RPAREN_T};
	set<string>::iterator itr1 = firsts.find(token);
        set<string>::iterator itr2 = follows.find(token);

	p2file << "Entering stmt function; current token is: " 
		<< lex->GetTokenName (token) << endl;

	// accepts if the token is in firsts 
	// then moves to next token
	if ( itr1 != firsts.end() ) {
	  token = lex->GetToken();
	}
	else {
	  cout << "not in firsts" << endl;
	}
	
	if ( token == NUMLIT_T || token == QUOTE_T || token == STRLIT_T ) {
	  errors += literal();
	}
	else if ( token == IDENT_T ) {
	  return errors;
	}
	// ****** note 
	// check the rule to see if a nested loop is necessary 
	else if ( token == LPAREN_T ) {
	  errors += action();
	}

	p2file << "Using Rule 7,8,9" << endl;



	p2file << "Exiting stmt function; current token is: " 
		<< lex->GetTokenName (token) << endl;
	return errors;
}
