#include "SyntacticalAnalyzer.h"

int SyntacticalAnalyzer::literal()
{

	int errors = 0;
	p2file << "Entering literal function; current token is: " 
		<< lex->GetTokenName (token) << endl;

	p2file << "Using Rule 10,11,12" << endl;

	static set<string> firsts = {NUMLIT_T,STRLIT_T,QUOTE_T};
	static set<string> follows = {IDENT_T,LPAREN_T,NUMLIT_T,STRLIT_T,QUOTE_T,RPAREN_T};

	p2file << "Exiting literal function; current token is: " 
		<< lex->GetTokenName (token) << endl;
	return errors;
}
