#include "SyntacticalAnalyzer.h"

int SyntacticalAnalyzer::else_part()
{

	int errors = 0;
	p2file << "Entering else_part function; current token is: " 
		<< lex->GetTokenName (token) << endl;

	p2file << "Using Rule 18,19" << endl;

	static set<string> firsts = {IDENT_T,LPAREN_T,NUMLIT_T,STRLIT_T,QUOTE_T,RPAREN_T};
	static set<string> follows = {RPAREN_T};

	p2file << "Exiting else_part function; current token is: " 
		<< lex->GetTokenName (token) << endl;
	return errors;
}
