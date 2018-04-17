int action()
{
  static set<string> firsts = {COND_T,LISTOP_T,CONS_T,AND_T,OR_T,NOT_T,NUMBERP_T,SMYBOL_T,LISTP_T,ZEROP_T,NULLP_T,STRINGP_T,
			       PLUS_T,MINUS_T,DIV_T,MULT_T,MODULO_T,EQUALTO_T,GT_T,LT_T,GTE_T,LTE_T,IDENT_T,DISPLAY_T,NEWLINE_T};
  static set<string> follows = {RPAREN_T};
  return 0;
}
