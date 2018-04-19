/************************************************************
File: stmt_pair_body.cpp
Author: Jacques Beauvoir & Aaron Pineda
Description: This file has the  stmt_pair_body
non-terminal function assoc. with rule 22 and 23.

22. <stmt_pair_body> -> <stmt> <stmt> RPAREN_T <stmt_pair> 
23. <stmt_pair_body> -> ELSE_T <stmt> RPAREN_T
************************************************************/
#include "SyntacticalAnalyzer.h"

int SyntacticalAnalyzer::stmt_pair_body()
{
        // Variable Declaration
	int errors = 0;
	static set<string> firsts = {ELSE_T,IDENT_T,LPAREN_T,NUMLIT_T,STRLIT_T,QUOTE_T};
	static set<string> follows = {RPAREN_T};
	set<string>::iterator itr1 = firsts.find(token);

	p2file << "Entering stmt_pair_body function; current token is: " 
	       << lex->GetTokenName (token) << endl;
	

	// So for the next few if-else blocks you'll notice
	// that rule 23 precedes 22. I did this because I 
	// didn't want to type out a long OR ||  statement. By 
	// checking for ELSE_T first, I can simply do a set check
	// with stmt_pair_body's firsts.

	// RULE 23
	if( token == ELSE_T ) {
	  
	  p2file << "Using Rule 23" << endl;
	  errors += stmt();
	  // terminal after <stmt>
	  if( token == RPAREN_T ) {
	    return errors++;
	  }
	  else {
	    cout << "error in stmt_pair_body for RPAREN" << endl;
	  }
	  
	}
	// RULE 22 
	else if ( itr1 != firsts.end() ) {
	  p2file << "Using Rule 22" << endl;
	  
	  errors += stmt();
	  errors += stmt();
	  
	  // Non-terminal check after <stmt>
	  if ( token == RPAREN_T ) {
	    errors += stmt_pair();
	  }
	  else{
	    cout << "error in error in stmt_pair_body for RPAREN rule 23" << endl;
	    return errors++;
	  }
	}
	// error stuff
	else {
	  cout << "neither rule 22 or 23 called" << endl;
	}


	p2file << "Exiting stmt_pair_body function; current token is: " 
		<< lex->GetTokenName (token) << endl;
	return errors;
}
