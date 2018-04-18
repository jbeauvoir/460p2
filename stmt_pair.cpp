#include "SyntacticalAnalyzer.h"

int SyntacticalAnalyzer::stmt_pair()
{

	int errors = 0;
	p2file << "Entering stmt_pair function; current token is: " 
		<< lex->GetTokenName (token) << endl;

	p2file << "Using Rule 20,21" << endl;

	static set<string> firsts = {LPAREN_T,RPAREN_T};
	static set<string> follows = {RPAREN_T};

	p2file << "Exiting stmt_pair function; current token is: " 
		<< lex->GetTokenName (token) << endl;
	return errors;
}
