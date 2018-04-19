#include "SyntacticalAnalyzer.h"

int SyntacticalAnalyzer::action()
{

	int errors = 0;
	p2file << "Entering action function; current token is: " 
		<< lex->GetTokenName (token) << endl;

	p2file << "Using Rule 24-49" << endl;

 	static set<string> firsts = {IF_T,COND_T,LISTOP_T,CONS_T,AND_T,
				     OR_T,NOT_T,NUMBERP_T,SYMBOLP_T,LISTP_T,ZEROP_T,
				     NULLP_T,STRINGP_T,PLUS_T,MINUS_T,DIV_T,MULT_T,
				     MODULO_T,EQUALTO_T,GT_T,LT_T,LTE_T,GTE_T,IDENT_T,
				     DISPLAY_T,NEWLINE_T};
	static set<string> follows = {RPAREN_T};

	p2file << "Exiting action function; current token is: " 
		<< lex->GetTokenName (token) << endl;
	return errors;
}
