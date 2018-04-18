#include "SyntacticalAnalyzer.h"

int SyntacticalAnalyzer::param_list()
{

	int errors = 0;
	p2file << "Entering param_list function; current token is: " 
		<< lex->GetTokenName (token) << endl;

	p2file << "Using Rule 16,17" << endl;

	static set<string> firsts = {IDENT_T,RPAREN_T};
	static set<string> follows = {RPAREN_T};

	p2file << "Exiting param_list function; current token is: " 
		<< lex->GetTokenName (token) << endl;
	return errors;
}
