/*******************************************************************************
* Assignment: Project 2 - Syntactic Analyzer for Scheme to C++ Translator      *
* Author:                                                                      *
* Date: Spring 2018                                                            *
* File: SyntacticalAnalyzer.cpp                                                *
*                                                                              *
* Description: This file contains the                                          *
*******************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "SyntacticalAnalyzer.h"

using namespace std;

/*******************************************************************************
* Function:                                                                    *
*                                                                              *
* Parameters:                                                                  *
* Return value:                                                                *
* Description: This function will                                              *
*******************************************************************************/
SyntacticalAnalyzer::SyntacticalAnalyzer (char * filename)
{
	lex = new LexicalAnalyzer (filename);
	string name = filename;
	string p2name = name.substr (0, name.length()-3) + ".p2"; 
	p2file.open (p2name.c_str());
	token = lex->GetToken();
	Program ();
}

/*******************************************************************************
* Function:                                                                    *
*                                                                              *
* Parameters:                                                                  *
* Return value:                                                                *
* Description: This function will                                              *
*******************************************************************************/
SyntacticalAnalyzer::~SyntacticalAnalyzer ()
{
	delete lex;
	p2file.close ();
}

/*******************************************************************************
* Function:                                                                    *
*                                                                              *
* Parameters:                                                                  *
* Return value:                                                                *
* Description: This function will                                              *
*******************************************************************************/
int SyntacticalAnalyzer::Program()
{
	p2file << "Entering Program function; current token is: "
					<< lex->GetTokenName (token) << endl;
	int errors = 0;
	// token should be in firsts of Program
	if( token == LPAREN_T ) {
	// Body of function goes here.
	  p2file << "Using Rule 1" << endl;
	  errors += define();
	  errors += more_defines();

	
	  if (token != EOF_T) {
	    errors++;
	    lex->ReportError ("Missing end of file at end of program");
	  }
	}
	// token should be in follows of Program
	p2file << "Exiting Program function; current token is: "
					<< lex->GetTokenName (token) << endl;
	return errors;
}

/************************************************************
File: Define.cpp
Author: Jacques Beauvoir & Aaron Pineda
Description: This file has the define 
non-terminal function assoc. with rule 2.

<define> -> LPAREN_T DEFINE_T LPAREN_T IDENT_T <param_list> 
RPAREN_T <stmt> <stmt_list> RPAREN_T
************************************************************/


int SyntacticalAnalyzer::define()
{
        // VARIABLE DECLARATION
	int errors = 0;	
	static set<token_type> firsts = {LPAREN_T};
	static set<token_type> follows = {LPAREN_T,EOF_T};
	
	set<token_type>::iterator itr1 = firsts.find(token);
	set<token_type>::iterator itr2 = follows.find(token);
	
	p2file << "Entering define function; current token is: " 
	       << lex->GetTokenName (token) << endl;

	p2file << "Using Rule 2" << endl;
	// DEFINE_T check
	if ( token == DEFINE_T ) {
	  token = lex->GetToken();
	  p2file << "Exiting DEFINE_T check; current token is: "
		 << lex->GetTokenName (token) << endl;
	}
	else {
	  cout << "no define" << endl;
	}
	
	// LPAREN_T
	if ( token == LPAREN_T ) {
	  token = lex->GetToken();
	  p2file << "Exiting LPAREN_T check; current token is: "
		 << lex->GetTokenName (token) << endl;
	}
	else {
	  cout << "no LPAREN" << endl;
	}

	// IDENT_T 
	if ( token == IDENT_T ) {
	  token = lex->GetToken();
	  p2file << "Exiting IDENT_T check; current token is: "
		 << lex->GetTokenName (token) << endl;
	}
	else {
	  cout << "no ident_T" << endl;
	}

	// <param_list>
	errors += param_list();
	
	// RPAREN_T 
	if ( token == RPAREN_T ) {
	  token = lex->GetToken();
	  p2file << "Exiting RPAREN_T check; current token is: "
		 << lex->GetTokenName (token) << endl;
	}
	else {
	  cout << "no RPAREN_T" << endl;
	}
	// nonterminals
	errors += stmt();
	errors += stmt_list();
	
	// RPAREN_T
	if ( token == RPAREN_T ) {
	  token = lex->GetToken();
	  p2file << "Exiting RPAREN_T check; current token is: "
		 << lex->GetTokenName (token) << endl;
	}
	else {
	  cout << "no RPAREN_T" << endl;
	}
	

	p2file << "Exiting define function; current token is: " 
		<< lex->GetTokenName (token) << endl;
	return errors;
}


int SyntacticalAnalyzer::action()
{

}

int SyntacticalAnalyzer::any_other_token()
{

}


int SyntacticalAnalyzer::else_part()
{

}

int SyntacticalAnalyzer::literal()
{

}

int SyntacticalAnalyzer::more_defines()
{

}

int SyntacticalAnalyzer::more_tokens()
{

}

int SyntacticalAnalyzer::param_list()
{

}

int SyntacticalAnalyzer::quoted_lit()
{

}

int SyntacticalAnalyzer::stmt_list()
{

}

int SyntacticalAnalyzer::stmt_pair_body()
{

}

int SyntacticalAnalyzer::stmt_pair()
{

}

int SyntacticalAnalyzer::stmt()
{

}
