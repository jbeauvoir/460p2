#include "SyntacticalAnalyzer.h"

int SyntacticalAnalyzer::stmt_pair_body()
{

	int errors = 0;
	p2file << "Entering stmt_pair_body function; current token is: " 
		<< lex->GetTokenName (token) << endl;

	p2file << "Using Rule 22,23" << endl;

	static set<string> firsts = {ELSE_T,IDENT_T,LPAREN_T,NUMLIT_T,STRLIT_T,QUOTE_T};
	static set<string> follows = {RPAREN_T};

	p2file << "Exiting stmt_pair_body function; current token is: " 
		<< lex->GetTokenName (token) << endl;
	return errors;
}
