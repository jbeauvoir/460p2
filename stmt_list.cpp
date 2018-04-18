#include "SyntacticalAnalyzer.h"


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

********************************************************************************/

int SyntacticalAnalyzer::stmt_list()
{
  
        // VARIABLE DECLARATIONS 
	int errors = 0;
	static set<string> firsts = {IDENT_T,LPAREN_T,NUMLIT_T,STRLIT_T,QUOTE_T};
	static set<string> follows = {RPAREN_T};
	set<string>::iterator itr1 = firsts.find(token);
        set<string>::iterator itr2 = follows.find(token);

	p2file << "Entering stmt_list function; current token is: " 
		<< lex->GetTokenName (token) << endl;

	// accepts if token is in firsts
	if ( itr1 != firsts.end() ) {

	  token = lex->GetToken();
        }
	else {
	  cout << "not in firsts" << endl;
	}

	// check which first it is
	


	// how can I use the set to solve my problem  
	p2file << "Using Rule 5,6" << endl;



	p2file << "Exiting stmt_list function; current token is: " 
		<< lex->GetTokenName (token) << endl;
	return errors;
}
