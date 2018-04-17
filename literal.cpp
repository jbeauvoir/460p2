int literal()
{
	static set<string> firsts = {NUMLIT_T,STRLIT_T,QUOTE_T};
	static set<string> follows = {LPAREN_T,IDENT_T,NUMLIT_T,STRLIT_T,CONS_T,IF_T,DISPLAY_T,NEWLINE_T,LISTOP_T,
				      AND_T,OR_T,NOT_T,DEFINE_T,NUMBERP_T,SYMBOLP_T,LISTP_T,ZEROP_T,NULLP_T,STRINGP_T,
				      PLUS_T,MINUS_T,DIV_T,MULT_T,MODULO_T,EQUALTO_T,GT_T,LT_T,GTE_T,LTE_T,QUOTE_T,COND_T,
	                              ELSE_T};
	return 0; 
}
