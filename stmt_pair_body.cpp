int stmt_pair_body()
{
	static set<string> firsts = {IDENT_T,LPAREN_T,NUMLIT,STR_LIT,QUOTE_T,ELSE_T};
	static set<string> follows = {IDENT_T,LPAREN_T,NUMLIT,STR_LIT,QUOTE_T};
	return 0;
}
