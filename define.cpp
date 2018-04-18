#include "SyntacticalAnalyzer.h"


/********(**************************************************
File: Define.cpp
Author: Jacques Beauvoir & Aaron Pineda
Description: This file has the define 
non-terminal function assoc. with rule 2.

<define> -> LPAREN_T DEFINE_T LPAREN_T IDENT_T <param_list> 
RPAREN_T <stmt> <stmt_list> RPAREN_T
************************************************************/
int SyntacticalAnalyzer::define()
  

	int errors = 0;
	p2file << "Entering define function; current token is: " 
		<< lex->GetTokenName (token) << endl;

	p2file << "Using Rule 2" << endl;

	static set<string> firsts = {LPAREN_T};
	static set<string> follows = {LPAREN_T,EOF_T};
	
	set<string>::iterator itr1 = firsts.find(token);
	set<string>::iterator itr2 = follows.find(token);
	
	// accepts if the token is in firsts
	if ( itr1 != firsts.end() ) {
	  //errors++;
	  token = lex->GetToken();
	}
	else {
	  cout << "not in firsts" << endl;
	}

	// DEFINE_T check
	if ( token == DEFINE_T ) {
	  token = lex->GetToken();
	}
	else {
	  cout << "no define" << endl;
	}
	
	// LPAREN_T
	if ( token == LPAREN_T ) {
	  token = lex->GetToken();
	}
	else {
	  cout << "no LPAREN" << endl;
	}

	// IDENT_T 
	if ( token == IDENT_T ) {
	  token = lex->GetToken();
	}
	else {
	  cout << "no ident_T" << endl;
	}

	// <param_list>
	errors += param_list();
	
	// RPAREN_T 
	if ( token == RPAREN_T ) {
	  token = lex->GetToken();
	}
	else {
	  cout << "no RPAREN_T" << endl;
	}
	// nonterminals
	errors += stmt();
	errors += stmt_list();
	
	if ( token == RPAREN_T ) {
	  token = lex->GetToken();
	}
	else {
	  cout << "no RPAREN_T" << endl;
	}
	// Not too sure if we need to use this YET since it's for error checking
	/*
	while(itr1 == firsts.end() && itr2 == follows.end()){
	  lex->ReportError("unexpected '" + ct + "' found at beginning of article.");
	  errors++;
	  ct = lex->NextTerminal();
	  itr1 = firsts.find(ct);
	  itr2 = follows.find(ct);
	}
	*/

	p2file << "Exiting define function; current token is: " 
		<< lex->GetTokenName (token) << endl;
	return errors;
}
