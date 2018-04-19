/*******************************************************************************
* Assignment: Project 2 - Syntactic Analyzer for Scheme to C++ Translator      *
* Author:                                                                      *
* Date: Spring 2018                                                            *
* File: SyntacticalAnalyzer.cpp                                                *
*                                                                              *
* Description: This file contains the                                          *
*******************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "SyntacticalAnalyzer.h"

using namespace std;

/*******************************************************************************
* Function:                                                                    *
*                                                                              *
* Parameters:                                                                  *
* Return value:                                                                *
* Description: This function will                                              *
*******************************************************************************/
SyntacticalAnalyzer::SyntacticalAnalyzer (char * filename)
{
	lex = new LexicalAnalyzer (filename);
	string name = filename;
	string p2name = name.substr (0, name.length()-3) + ".p2"; 
	p2file.open (p2name.c_str());
	token = lex->GetToken();
	int errors = Program ();
}

/*******************************************************************************
* Function:                                                                    *
*                                                                              *
* Parameters:                                                                  *
* Return value:                                                                *
* Description: This function will                                              *
*******************************************************************************/
SyntacticalAnalyzer::~SyntacticalAnalyzer ()
{
	delete lex;
	p2file.close ();
}

/*******************************************************************************
* Function:                                                                    *
*                                                                              *
* Parameters:                                                                  *
* Return value:                                                                *
* Description: This function will                                              *
*******************************************************************************/
int SyntacticalAnalyzer::Program ()
{
	p2file << "Entering Program function; current token is: "
					<< lex->GetTokenName (token) << endl;
	int errors = 0;
	// token should be in firsts of Program
	
	// Body of function goes here.
	p2file << "Using Rule 1" << endl;
	
	if(token == LPAREN_T){
		errors += define ();
		errors += more_defines ();
	}
	if (token != EOF_T)
	{
		errors++;
		lex->ReportError ("Missing end of file at end of program");
	}
	// token should be in follows of Program
	p2file << "Exiting Program function; current token is: "
					<< lex->GetTokenName (token) << endl;
	
	return errors;
}

/************************************************************
File: Define.cpp
Author: Jacques Beauvoir & Aaron Pineda
Description: This file has the define 
non-terminal function assoc. with rule 2.

<define> -> LPAREN_T DEFINE_T LPAREN_T IDENT_T <param_list> 
RPAREN_T <stmt> <stmt_list> RPAREN_T
************************************************************/
//#include "SyntacticalAnalyzer.h"

int SyntacticalAnalyzer::define()
{
        // VARIABLE DECLARATION
	int errors = 0;	
	static set<token_type> firsts = {LPAREN_T};
	static set<token_type> follows = {LPAREN_T,EOF_T};
	
	set<token_type>::iterator itr1 = firsts.find(token);
	set<token_type>::iterator itr2 = follows.find(token);
	
	p2file << "Entering define function; current token is: " 
	       << lex->GetTokenName (token) << endl;

	p2file << "Using Rule 2" << endl;
	// DEFINE_T check
	if ( token == DEFINE_T ) {
	  token = lex->GetToken();
	  p2file << "Exiting DEFINE_T check; current token is: "
		 << lex->GetTokenName (token) << endl;
	}
	else {
	  cout << "no define" << endl;
	}
	
	// LPAREN_T
	if ( token == LPAREN_T ) {
	  token = lex->GetToken();
	  p2file << "Exiting LPAREN_T check; current token is: "
		 << lex->GetTokenName (token) << endl;
	}
	else {
	  cout << "no LPAREN" << endl;
	}

	// IDENT_T 
	if ( token == IDENT_T ) {
	  token = lex->GetToken();
	  p2file << "Exiting IDENT_T check; current token is: "
		 << lex->GetTokenName (token) << endl;
	}
	else {
	  cout << "no ident_T" << endl;
	}

	// <param_list>
	errors += param_list();
	
	// RPAREN_T 
	if ( token == RPAREN_T ) {
	  token = lex->GetToken();
	  p2file << "Exiting RPAREN_T check; current token is: "
		 << lex->GetTokenName (token) << endl;
	}
	else {
	  cout << "no RPAREN_T" << endl;
	}
	// nonterminals
	errors += stmt();
	errors += stmt_list();
	
	// RPAREN_T
	if ( token == RPAREN_T ) {
	  token = lex->GetToken();
	  p2file << "Exiting RPAREN_T check; current token is: "
		 << lex->GetTokenName (token) << endl;
	}
	else {
	  cout << "no RPAREN_T" << endl;
	}
	

	p2file << "Exiting define function; current token is: " 
		<< lex->GetTokenName (token) << endl;
	return errors;
}


/*******************************************************************************
Function: more_defines
Parameters: none
Return value: integer named "errors"
Description: This is rule number 3 and 4.
3. <more_defines> -> <define> <more_defines>
4. <more_defines> -> lambda 
Notes: 
- wherever there are **** that means there's a note 
at that specific area
- else statments were added with comment if the code is wrong, this means
there is a logic error because all input should be valid 
eventually we will have to delete the elses for submission
********************************************************************************/
int SyntacticalAnalyzer::more_defines()
{

	int errors = 0;
	static set<token_type> firsts = {LPAREN_T,EOF_T};
	static set<token_type> follows = {EOF_T};

	set<token_type>::iterator itr1 = firsts.find(token);
        set<token_type>::iterator itr2 = follows.find(token);

	// this should be a LPAREN
	p2file << "Entering more_defines function; current token is: " 
		<< lex->GetTokenName (token) << endl;
	
	// LPAREN_T check
	// **** note: check logic here
	// I didn't do next token because we need it for 
	// the define() firsts

	// RULE 3
	if ( token == LPAREN_T ) {
	  p2file << "Using Rule 3" << endl;

	  token = lex->GetToken();
	  
    	  // Non-terminal check
	  errors += define();
	  errors += more_defines();
	  
	  p2file << "Exiting LPAREN_T check; current token is: "
		 << lex->GetTokenName (token) << endl;
	}
	// RULE 4
	else if ( token == EOF_T ) {
	  p2file << "Using Rule 4" << endl;

	  token = lex->GetToken();
		
	  p2file << "Exiting EOF_T check; current token is: "
                 << lex->GetTokenName (token) << endl;

	  return errors;
	}
	// SOL
	else { 
	  cout << "no EOF_T or LPAREN" << endl;
	}
	
	// Should be EOF_T
	p2file << "Exiting more_defines function; current token is: " 
		<< lex->GetTokenName (token) << endl;
	return errors;
}


/**************************************************
File: action.cpp
Author: Jacques Beauvoir & Aaron Pineda
Description: This file has the action 
tag function assoc. with rules 24-49
24. <action> -> IF_T <stmt> <stmt> <else_part>
25. <action> -> COND_T LPAREN_T <stmt_pair_body>
26. <action> -> LISTOP_T <stmt>
27. <action> -> CONS_T <stmt> <stmt>
28. <action> -> AND_T <stmt_list>
29. <action> -> OR_T <stmt_list>
30. <action> -> NOT_T <stmt>
31. <action> -> NUMBERP_T <stmt>
32. <action> -> SYMBOLP_T <stmt>
33. <action> -> LISTP_T <stmt>
34. <action> -> ZEROP_T <stmt>
35. <action> -> NULLP_T <stmt>
36. <action> -> STRINGP_T <stmt>
37. <action> -> PLUS_T <stmt_list>
38. <action> -> MINUS_T <stmt> <stmt_list>
39. <action> -> DIV_T <stmt> <stmt_list>
40. <action> -> MULT_T <stmt_list>
41. <action> -> MODULO_T <stmt> <stmt>
42. <action> -> EQUALTO_T <stmt_list>
43. <action> -> GT_T <stmt_list>
44. <action> -> LT_T <stmt_list>
45. <action> -> GTE_T <stmt_list>
46. <action> -> LTE_T <stmt_list>
47. <action> -> IDENT_T <stmt_list>
48. <action> -> DISPLAY_T <stmt>
49. <action> -> NEWLINE_T
************************************************************/


int SyntacticalAnalyzer::action()
{

	int errors = 0;
	static set<token_type> firsts = {IF_T,COND_T,LISTOP_T,CONS_T,AND_T,
				     OR_T,NOT_T,NUMBERP_T,SYMBOLP_T,LISTP_T,ZEROP_T,
				     NULLP_T,STRINGP_T,PLUS_T,MINUS_T,DIV_T,MULT_T,
				     MODULO_T,EQUALTO_T,GT_T,LT_T,LTE_T,GTE_T,IDENT_T,
				     DISPLAY_T,NEWLINE_T};
	static set<token_type> follows = {RPAREN_T};


	p2file << "Entering action function; current token is: " 
		<< lex->GetTokenName (token) << endl;
	if(token == IF_T){
		p2file << "Using rule 24" << endl;
		token = lex->GetToken();
		errors += stmt();
		errors += stmt();
		errors += else_part();
	}
	else if(token == COND_T){
		p2file << "Using rule 25" << endl;
		token = lex->GetToken();
		lex->GetTokenName(token);
		if(token == LPAREN_T){
			p2file << "Using rule 25" << endl;
			token = lex->GetToken();
			errors += stmt_pair_body();
		}
	}
	else if(token == LISTOP_T){
		p2file << "Using rule 26" << endl;
		errors += stmt();
	}
	else if(token == CONS_T){
		p2file << "Using rule 27" << endl;
		errors += stmt();
		errors += stmt();
	}
	else if(token == AND_T){
		p2file << "Using rule 28" << endl;
		errors += stmt_list();
	}
	else if(token == OR_T){
		p2file << "Using rule 29" << endl;
		errors += stmt_list();
	}
	else if(token == NOT_T){
		p2file << "Using rule 30" << endl;
		errors += stmt();
	}
	else if(token == NUMBERP_T){
		p2file << "Using rule 31" << endl;
		errors += stmt();
	}
	else if(token == SYMBOLP_T){
		p2file << "Using rule 32" << endl;
		errors += stmt();
	} 
	else if(token == LISTP_T){
		p2file << "Using rule 33" << endl;
		errors += stmt();
	}
	else if(token == ZEROP_T){
		p2file << "Using rule 34" << endl;
		errors += stmt();
	}
	else if(token == NULLP_T){
		p2file << "Using rule 35" << endl;
		errors += stmt();
	}
	else if(token == STRINGP_T){
		p2file << "Using rule 36" << endl;
		errors += stmt();
	}
	else if(token == PLUS_T){
		p2file << "Using rule 37" << endl;
		errors += stmt_list();
	}
	else if(token == MINUS_T){
		p2file << "Using rule 38" << endl;
		errors += stmt();
		errors += stmt_list();
	}
	else if(token == DIV_T){
		p2file << "Using rule 39" << endl;
		errors += stmt();
		errors += stmt_list();
	} 
	else if(token == MULT_T){
		p2file << "Using rule 40" << endl;
		errors += stmt_list();
	}
	else if(token == MODULO_T){
		p2file << "Using rule 41" << endl;
		errors += stmt();
		errors += stmt();
	}
	else if(token == EQUALTO_T){
		p2file << "Using rule 42" << endl;
		errors += stmt_list();
	}
	else if(token == GT_T){
		p2file << "Using rule 43" << endl;
		errors += stmt_list();
	}
	else if(token == LT_T){
		p2file << "Using rule 44" << endl;
		errors += stmt_list();
	}
	else if(token == GTE_T){
		p2file << "Using rule 45" << endl;
		errors += stmt_list();
	}
	else if(token == LTE_T){
		p2file << "Using rule 46" << endl;
		errors += stmt_list();
	}
	else if(token == IDENT_T){
		p2file << "Using rule 47" << endl;
		errors += stmt_list();
	}
	else if(token == DISPLAY_T){
		p2file << "Using rule 48" << endl;
		errors += stmt();
	} 
	else if{
		p2file << "Using rule 49" << endl;
		token = lex->GetToken();
	}

	p2file << "Exiting action function; current token is: " 
	       << lex->GetTokenName (token) << endl;
	return errors;
}


/**************************************************
File: any_other_token.cpp
Author: Jacques Beauvoir & Aaron Pineda
Description: This file has the any_other_token 
tag function assoc. with rules 50-81
50. <any_other_token> -> LPAREN_T <more_tokens> RPAREN_T
51. <any_other_token> -> IDENT_T
52. <any_other_token> -> NUMLIT_T
53. <any_other_token> -> STRLIT_T
54. <any_other_token> -> CONS_T
55. <any_other_token> -> IF_T
56. <any_other_token> -> DISPLAY_T
57. <any_other_token> -> NEWLINE_T
58. <any_other_token> -> LISTOP_T
59. <any_other_token> -> AND_T
60. <any_other_token> -> OR_T
61. <any_other_token> -> NOT_T
62. <any_other_token> -> DEFINE_T
63. <any_other_token> -> NUMBERP_T
64. <any_other_token> -> SYMBOLP_T
65. <any_other_token> -> LISTP_T
66. <any_other_token> -> ZEROP_T
67. <any_other_token> -> NULLP_T
68. <any_other_token> -> STRINGP_T
69. <any_other_token> -> PLUS_T
70. <any_other_token> -> MINUS_T
71. <any_other_token> -> DIV_T
72. <any_other_token> -> MULT_T
73. <any_other_token> -> MODULO_T
74. <any_other_token> -> EQUALTO_T
75. <any_other_token> -> GT_T
76. <any_other_token> -> LT_T
77. <any_other_token> -> GTE_T
78. <any_other_token> -> LTE_T
79. <any_other_token> -> QUOTE_T <any_other_token>
80. <any_other_token> -> COND_T
81. <any_other_token> -> ELSE_T
************************************************************/


int SyntacticalAnalyzer::any_other_token()
{

	int errors = 0;
	p2file << "Entering any_other_token function; current token is: " 
		<< lex->GetTokenName (token) << endl;


	static set<token_type> firsts = {LPAREN_T,IDENT_T,NUMLIT_T,STRLIT_T,CONS_T,IF_T,DISPLAY_T,
				     NEWLINE_T,LISTOP_T,AND_T,OR_T,NOT_T,DEFINE_T,NUMBERP_T,
				     SYMBOLP_T,LISTP_T,ZEROP_T,NULLP_T,STRINGP_T,PLUS_T,MINUS_T,
				     DIV_T,MULT_T,MODULO_T,EQUALTO_T,GT_T,LT_T,GTE_T,LTE_T,
				     QUOTE_T,COND_T,ELSE_T};
	static set<token_type> follows = {LPAREN_T,IDENT_T,NUMLIT_T,STRLIT_T,CONS_T,IF_T,DISPLAY_T,
				      NEWLINE_T,LISTOP_T,AND_T,OR_T,NOT_T,DEFINE_T,NUMBERP_T,
				      SYMBOLP_T,LISTP_T,STRINGP_T,ZEROP_T,NULLP_T,PLUS_T,MINUS_T,
				      MULT_T,DIV_T,MODULO_T,EQUALTO_T,LT_T,GT_T,LTE_T,GTE_T,QUOTE_T,
				      COND_T,ELSE_T,RPAREN_T};

	if(token == LPAREN_T){//type1
	
	p2file << "Using Rule 50" << endl;
	token = lex->GetToken();
	errors += more_tokens();
	if(token == RPAREN_T){
		token = lex->GetToken();
	}else{
		errors++;
		lex->ReportError("Expected first of any_other_token; found: " + lex->GetTokenName(token));
	}
}
	else if(token == IDENT_T){
		p2file << "Using rule 51" << endl;
		
	}
	else if(token == NUMLIT_T){
		p2file << "Using rule 52" << endl;
		
	}
	else if(token == STRLIT_T){
		p2file << "Using rule 53" << endl;
		
	}
	else if(token == CONS_T){
		p2file << "Using rule 54" << endl;
		
	}
	else if(token == IF_T){
		p2file << "Using rule 55" << endl;
		
	}
	else if(token == DISPLAY_T){
		p2file << "Using rule 56" << endl;
		
	}
	else if(token == NEWLINE_T){
		p2file << "Using rule 57" << endl;
		
	}
	else if(token == LISTOP_T){
		p2file << "Using rule 58" << endl;
		
	}
	else if(token == AND_T){
		p2file << "Using rule 59" << endl;
		
	}
	else if(token == OR_T) {
		p2file << "Using rule 60" << endl;
		
	}
	else if(token == NOT_T){
		p2file << "Using rule 61" << endl;
		
	}
	else if(token == DEFINE_T){
		p2file << "Using rule 62" << endl;
		
	} 
	else if(token == NUMBERP_T){
		p2file << "Using rule 63" << endl;
		
	}
	else if(token == SYMBOLP_T){
		p2file << "Using rule 64" << endl;
		
	}
	else if(token == LISTP_T){
		p2file << "Using rule 65" << endl;
		
	}
	else if(token == ZEROP_T){
		p2file << "Using rule 66" << endl;
		
	}
	else if(token == NULLP_T){
		p2file << "Using rule 67" << endl;
		
	}
	else if(token == STRINGP_T){
		p2file << "Using rule 68" << endl;
		
	}
	else if(token == PLUS_T){
		p2file << "Using rule 69" << endl;
		
	} 
	else if(token == MINUS_T){
		p2file << "Using rule 70" << endl;
		
	}
	else if(token == DIV_T){
		p2file << "Using rule 71" << endl;
		
	}
	else if(token == MULT_T){
		p2file << "Using rule 72" << endl;
		
	}
	else if(token == MODULO_T){
		p2file << "Using rule 73" << endl;
		
	} 
	else if(token == EQUALTO_T){
		p2file << "Using rule 74" << endl;
		
	}
	else if(token == GT_T){
		p2file << "Using rule 75" << endl;
		
	}
	else if(token == LT_T){
		p2file << "Using rule 76" << endl;
		
	}
	else if(token == GTE_T){
		p2file << "Using rule 77" << endl;
		
	}
	else if(token == LTE_T){
		p2file << "Using rule 78" << endl;
	
	}
	else if(token == QUOTE_T){
		p2file << "Using rule 79" << endl;
		token = lex->GetToken();
		errors += any_other_token();
	}
	else if(token == COND_T){
		p2file << "Using rule 80" << endl;
		
	}
	else if(token == ELSE_T){
		p2file << "Using rule 81" << endl;
	
	}
	token = lex->GetToken();
	p2file << "Exiting any_other_token function; current token is: " 
		<< lex->GetTokenName (token) << endl;


	return errors;
}


/************************************************************
File: else_part.cpp
Author: Jacques Beauvoir & Aaron Pineda
Description: This file has the else_part 
non-terminal function assoc. with rule 18 and 19.
18. <else_part> -> <stmt>
19. <else_part> -> lambda
Note: check rule 19 for lambda rule 
************************************************************/

int SyntacticalAnalyzer::else_part()
{
        // Variable Declaration
 	int errors = 0;
	static set<token_type> firsts = {IDENT_T,LPAREN_T,NUMLIT_T,STRLIT_T,QUOTE_T,RPAREN_T};
	static set<token_type> follows = {RPAREN_T};
	set<token_type>::iterator itr1 = firsts.find(token);
	set<token_type>::iterator itr2 = follows.find(token);

	p2file << "Entering else_part function; current token is: " 
		<< lex->GetTokenName (token) << endl;
	
	// RULE 18
	// one of the firsts terminals is present
	if ( itr1 != firsts.end() ) {
	  p2file << "Using Rule 18" << endl;
	  errors += stmt(); 
	}
	// RULE 19 
	else if() {
	  p2file << "Using Rule 19" << endl; 
	}
	

	p2file << "Exiting else_part function; current token is: " 
		<< lex->GetTokenName (token) << endl;
	return errors;
}


/***********************************************************
File: literal.cpp
Author: Jacques Beauvoir & Aaron Pineda
Description: This file has the literal 
non-terminal function assoc. with rule 10, 11, 12
10. <literal> -> NUMLIT_T
11. <literal> -> STRLIT_T
12. <literal> -> QUOTE_T <quoted_lit>
************************************************************/


int SyntacticalAnalyzer::literal()
{
        // Variable Declarations
        int errors = 0;
	static set<token_type> firsts = {NUMLIT_T,STRLIT_T,QUOTE_T};
	static set<token_type> follows = {IDENT_T,LPAREN_T,NUMLIT_T,STRLIT_T,QUOTE_T,
				      RPAREN_T};
	  
	p2file << "Entering literal function; current token is: " 
		<< lex->GetTokenName (token) << endl;

	// RULE 10 
	if ( token == NUMLIT_T ) {
	  p2file << "Using Rule 10" << endl;

	  token = lex->GetToken();
	  
          p2file << "Exiting NUMLIT_T check in stmt function; current token is: "
	         << lex->GetTokenName (token) << endl;
	}
	// RULE 11
	else if ( token == STRLIT_T ) {
		
	  p2file << "Using Rule 11" << endl;

	  token = lex->GetToken();
	  
          p2file << "Exiting STRLIT_T check in stmt function; current token is: "
	         << lex->GetTokenName (token) << endl;
	}
	// RULE 12 
	else if ( token == QUOTE_T ) {
	  p2file << "Using Rule 12" << endl;
	  
	  token = lex->GetToken();
	  
	  errors += quoted_lit();
	} 
	// no valid first
	else {
	  cout << "problem in literal firsts" << endl;
	}
	 
	p2file << "Exiting literal function; current token is: " 
		<< lex->GetTokenName (token) << endl;
	return errors;
}


/************************************************************
File: more_tokens.cpp
Author: Jacques Beauvoir & Aaron Pineda
Description: This file has the more_tokens.cpp 
non-terminal function assoc. with rule 14 and 15.
14. <more_tokens> -> <any_other_tokens> <more_tokens>
15. <more_tokens> -> lambda
note: Check my logic for the lambda
************************************************************/


int SyntacticalAnalyzer::more_tokens()
{
     
        // Variable Declaration
	int errors = 0;
	static set<token_type> firsts = {LPAREN_T,IDENT_T,NUMLIT_T,STRLIT_T,CONS_T,IF_T,DISPLAY_T,
                                     NEWLINE_T,LISTOP_T,AND_T,OR_T,NOT_T,DEFINE_T,NUMBERP_T,
                                     SYMBOLP_T,LISTP_T,STRINGP_T,ZEROP_T,NULLP_T,PLUS_T,MINUS_T,
                                     MULT_T,DIV_T,MODULO_T,EQUALTO_T,LT_T,GT_T,LTE_T,GTE_T,QUOTE_T,
                                     COND_T,ELSE_T,RPAREN_T};
	static set<token_type> follows = {RPAREN_T};
	// set for any_other_token firsts
	static set<token_type> AOT = {LPAREN_T,IDENT_T,NUMLIT_T,STRLIT_T,CONS_T,IF_T,DISPLAY_T,
				     NEWLINE_T,LISTOP_T,AND_T,OR_T,NOT_T,DEFINE_T,NUMBERP_T,
				     SYMBOLP_T,LISTP_T,ZEROP_T,NULLP_T,STRINGP_T,PLUS_T,MINUS_T,
				     DIV_T,MULT_T,MODULO_T,EQUALTO_T,GT_T,LT_T,GTE_T,LTE_T,
				     QUOTE_T,COND_T,ELSE_T};

	set<string>::iterator itr1 = firsts.find(token);
	set<string>::iterator itr2 = follows.find(token);
	set<string>::iterator itr3 = AOT.find(token);

	p2file << "Entering more_tokens function; current token is: " 
		<< lex->GetTokenName (token) << endl;

	// RULE 14 
	if( itr3 != AOT.end() ) {
	  p2file << "Using Rule 14" << endl;

	  token = lex->GetToken();
	  p2file << "Inside Rule 14; current token is: " 
		 << lex->GetTokenName (token) << endl;	 
		
	  // Non-terminal checks
	  errors += any_other_token();
	  errors += more_tokens();
	}

	// RULE 15?
	

	p2file << "Exiting more_tokens function; current token is: " 
		<< lex->GetTokenName (token) << endl;
	return errors;
}


/************************************************************
File: param_list.cpp
Author: Jacques Beauvoir & Aaron Pineda
Description: This file has the param_list 
non-terminal function assoc. with rule 16 and 17.
16. <param_list> -> IDENT_T <param_lit>
17. <param_list> -> lamda
notes: check my lambda logic 
************************************************************/

int SyntacticalAnalyzer::param_list()
{

	int errors = 0;
	static set<token_type> firsts = {IDENT_T,RPAREN_T};
	static set<token_type> follows = {RPAREN_T};

	p2file << "Entering param_list function; current token is: " 
		<< lex->GetTokenName (token) << endl;

	// RULE 16
	if ( token == IDENT_T ) {
	  p2file << "Using Rule 16" << endl;

	  token = lex->GetToken();

	  p2file << "Exiting IDENT_T check in param_list function; current token is: "
		 << lex->GetTokenName (token) << endl;
	  
	  // Non-terminal check 
	  errors += param_list();
	}

	// RULE 17???

	p2file << "Exiting param_list function; current token is: " 
		<< lex->GetTokenName (token) << endl;
	return errors;
}


/************************************************************
File: quoted_lit.cpp
Author: Jacques Beauvoir & Aaron Pineda
Description: This file has the quoted_lit
non-terminal function assoc. with rule 13.
 
13. <quoted_lit> -> <any_other_token>
************************************************************/


int SyntacticalAnalyzer::quoted_lit()
{
         // Variable Declrations 
	int errors = 0;
	static set<token_type> firsts = {LPAREN_T,IDENT_T,NUMLIT_T,STRLIT_T,CONS_T,IF_T,DISPLAY_T,
				     NEWLINE_T,LISTOP_T,AND_T,OR_T,NOT_T,DEFINE_T,NUMBERP_T,
				     SYMBOLP_T,LISTP_T,STRINGP_T,ZEROP_T,NULLP_T,PLUS_T,MINUS_T,
				     MULT_T,DIV_T,MODULO_T,EQUALTO_T,LT_T,GT_T,LTE_T,GTE_T,QUOTE_T,
				     COND_T,ELSE_T,RPAREN_T};
	static set<token_type> follows = {IDENT_T,LPAREN_T,NUMLIT_T,STRLIT_T,QUOTE_T,RPAREN_T};

	set<token_type>::iterator itr1 = firsts.find(token);
	set<token_type>::iterator itr2 = follows.find(token);

	p2file << "Entering quoted_lit function; current token is: " 
	       << lex->GetTokenName (token) << endl;

	// Singular rule means we can just use the set instead of the if-else blocks
	// RULE 13
	if( itr1 != firsts.end() ) {
	  p2file << "Using Rule 13" << endl;
	 
	  token = lex->GetToken();
		
	  p2file << "Exiting rule 13 function; current token is: " 
	       << lex->GetTokenName (token) << endl;

          // Non-terminal check
	  errors += any_other_token();
	}

	
	p2file << "Exiting quoted_lit function; current token is: " 
		<< lex->GetTokenName (token) << endl;
	return errors;
}


/***********************************************************
File: stmt.cpp
Author: Jacques Beauvoir & Aaron Pineda
Description: Contains the stmt non-terminal assoc. with 
rules 7, 8, and 9.
notes:
  - Put in p2file rule notificaiton in proper place
  - check nested loop for rule 9 
  - check if statement check for firsts 
************************************************************/


int SyntacticalAnalyzer::stmt()
{
        // Variable Declaration 
        int errors = 0;
  	static set<token_type> firsts = {IDENT_T,LPAREN_T,NUMLIT_T,STRLIT_T,QUOTE_T};
	static set<token_type> follows = {IDENT_T,LPAREN_T,NUMLIT_T,STRLIT_T,QUOTE_T,
				      RPAREN_T};
	set<token_type>::iterator itr1 = firsts.find(token);
        set<token_type>::iterator itr2 = follows.find(token);

	p2file << "Entering stmt function; current token is: " 
		<< lex->GetTokenName (token) << endl;


	// RULE 7
	if ( token == NUMLIT_T || token == QUOTE_T || token == STRLIT_T ) {
	  p2file << "Using Rule 7" << endl;
	
	  token = lex->GetToken();
		
	  p2file << "Exiting rule 8 IDENT_T in stmt; current token is: " 
		 << lex->GetTokenName (token) << endl;
	  
	  errors += literal();
	}
	// RULE 8
	else if ( token == IDENT_T ) {
	  p2file << "Using Rule 8" << endl;

	  token = lex->GetToken();
		
	  p2file << "Exiting rule 8 IDENT_T in stmt; current token is: " 
		 << lex->GetTokenName (token) << endl;

		
	}

	// RULE 9
	else if ( token == LPAREN_T ) {
	  p2file << "Using Rule 9" << endl;
	
	  token = lex->GetToken();
		
          // Non-terminal check
	  errors += action();

	  if ( token == RPAREN_T ) {
	    lex->GetTokenName (token);
	    p2file << "Exiting rule 9 RPAREN_T check in stmt function; current token is: "
		   << lex->GetTokenName (token) << endl;
	  }
	  else {
	    cout << "no RPAREN_T" << endl;
	  }
	}
	else {
	  cout << "no firsts" << endl;
	}

	p2file << "Exiting stmt function; current token is: " 
		<< lex->GetTokenName (token) << endl;
	return errors;
}


/*******************************************************************************
Function: stmt_list
Parameters: none 
Return value: an integer value called "errors"
Description: This is rule number 5 and 6
5. <stmt_list> -> <stmt> <stmt_list>
6. <stmt_list> -> lambda
Notes:                                                                                 
- wherever there are **** that means there's a note                                    
at that specific area                                                                 
- else statments were added with comment if the code is wrong, this means 
there is a logic error because all input should be valid  
eventually we will have to delete the elses for submission
- check my logic for the lambda
- what ways can we use sets to solve problems?
********************************************************************************/

int SyntacticalAnalyzer::stmt_list()
{
  
        // VARIABLE DECLARATIONS 
	int errors = 0;
	static set<token_type> firsts = {IDENT_T,LPAREN_T,NUMLIT_T,STRLIT_T,QUOTE_T};
	static set<token_type> follows = {RPAREN_T};
	set<token_type>::iterator itr1 = firsts.find(token);
        set<token_type>::iterator itr2 = follows.find(token);

	p2file << "Entering stmt_list function; current token is: " 
		<< lex->GetTokenName (token) << endl;
	
	// RULE 5
	if( itr1 != follows.end() ) {
	  p2file << "Using Rule 5" << endl;

	  errors += stmt();
	  errors += stmt_list();
	}
	else {
	  cout << "rule 5 no first" << endl;
	}
	
	// RULE 6???


	p2file << "Exiting stmt_list function; current token is: " 
		<< lex->GetTokenName (token) << endl;
	return errors;
}


/************************************************************
File: stmt_pair.cpp
Author: Jacques Beauvoir & Aaron Pineda
Description: This file has the stmt_pair  
non-terminal function assoc. with rule 20 and 21.
20. <stmt_pair> -> LPAREN_T <stmt_pait_body>
21. <stmt_pair> -> lambda
Note: check rule 21 logic for the lambda 
************************************************************/

int SyntacticalAnalyzer::stmt_pair()
{
        // Variable Declaration
	int errors = 0;
	static set<token_type> firsts = {LPAREN_T,RPAREN_T};
	static set<token_type> follows = {RPAREN_T};
	
	p2file << "Entering stmt_pair function; current token is: " 
	       << lex->GetTokenName (token) << endl;

	// RULE 20
	if( token == LPAREN_T ) {
	  p2file << "Using Rule 20" << endl;
	  errors += stmt_pair_body();
	}
	// RULE 21
	else if () {

	}
	else {
	  cout << "error in stmt_pair no firsts" << endl;
	}

	p2file << "Exiting stmt_pair function; current token is: " 
		<< lex->GetTokenName (token) << endl;
	return errors;
}


/************************************************************
File: stmt_pair_body.cpp
Author: Jacques Beauvoir & Aaron Pineda
Description: This file has the  stmt_pair_body
non-terminal function assoc. with rule 22 and 23.
22. <stmt_pair_body> -> <stmt> <stmt> RPAREN_T <stmt_pair> 
23. <stmt_pair_body> -> ELSE_T <stmt> RPAREN_T
************************************************************/

int SyntacticalAnalyzer::stmt_pair_body()
{
        // Variable Declaration
	int errors = 0;
	static set<token_type> firsts = {ELSE_T,IDENT_T,LPAREN_T,NUMLIT_T,STRLIT_T,QUOTE_T};
	static set<token_type> follows = {RPAREN_T};
	set<token_type>::iterator itr1 = firsts.find(token);

	p2file << "Entering stmt_pair_body function; current token is: " 
	       << lex->GetTokenName (token) << endl;
	

	// So for the next few if-else blocks you'll notice
	// that rule 23 precedes 22. I did this because I 
	// didn't want to type out a long OR ||  statement. By 
	// checking for ELSE_T first, I can simply do a set check
	// with stmt_pair_body's firsts.

	// RULE 23
	if( token == ELSE_T ) {
	  
	  p2file << "Using Rule 23" << endl;
	  
	  token = lex->GetToken();
	  
	  p2file << "Exiting RPAREN_T check in stmt_pair_body function; current token is: "
		 << lex->GetTokenName (token) << endl;
	  
	  // Non-terminal checks
	  errors += stmt();

	  // Terminal after <stmt>
	  if( token == RPAREN_T ) {
	    ltoken = lex->GetToken();
	    
	    p2file << "Exiting RPAREN_T check in stmt_pair_body function; current token is: "
		   << lex->GetTokenName (token) << endl;
	    
	    // return errors++;
	  }
	  else {
	    cout << "error in stmt_pair_body for RPAREN" << endl;
	  }
	  
	}
	// RULE 22 
	else if ( itr1 != firsts.end() ) {
	  p2file << "Using Rule 22" << endl;
	  
	  // Non-terminal checks
	  errors += stmt();
	  errors += stmt();
	  
	  // Non-terminal check after <stmt>
	  if ( token == RPAREN_T ) {

	    token = lex->GetToken();
		  
	    p2file << "Exiting RPAREN_T check in stmt_pair_body function; current token is: "
		   << lex->GetTokenName (token) << endl;
	    
	    // Non-terminal check
	    errors += stmt_pair();
	  }
	  else{
	    cout << "error in error in stmt_pair_body for RPAREN rule 23" << endl;
	
	  }
	}
	// error stuff
	else {
	  cout << "neither rule 22 or 23 called" << endl;
	}


	p2file << "Exiting stmt_pair_body function; current token is: " 
		<< lex->GetTokenName (token) << endl;
	return errors;
}
