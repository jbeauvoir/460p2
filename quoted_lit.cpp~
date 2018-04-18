#include "SyntacticalAnalyzer.h"

int SyntacticalAnalyzer::quoted_lit()
{

	int errors = 0;
	p2file << "Entering quoted_lit function; current token is: " 
		<< lex->GetTokenName (token) << endl;

	p2file << "Using Rule 13" << endl;

	static set<string> firsts = {LPAREN_T,IDENT_T,NUMLIT_T,STRLIT_T,CONS_T,IF_T,DISPLAY_T,
				     NEWLINE_T,LISTOP_T,AND_T,OR_T,NOT_T,DEFINE_T,NUMBERP_T,
				     SYMBOLP_T,LISTP_T,STRINGP_T,ZEROP_T,NULLP_T,PLUS_T,MINUS_T,
				     MULT_T,DIV_T,MODULO_T,EQUALTO_T,LT_T,GT_T,LTE_T,GTE_T,QUOTE_T,
				     COND_T,ELSE_T,RPAREN_T};
	static set<string> follows = {IDENT_T,LPAREN_T,NUMLIT_T,STRLIT_T,QUOTE_T,RPAREN_T};

	p2file << "Exiting quoted_lit function; current token is: " 
		<< lex->GetTokenName (token) << endl;
	return errors;
}
