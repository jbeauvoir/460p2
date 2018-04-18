#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
  //  string non_terminal;
  string ruleNum;
  string sentence;
  string mysent;
  string mysent2;
  string fileName;

  cout << "Enter the filename w/o .cpp : ";
  cin >> fileName;
  cout << "Enter the rule number(s): ";
  cin >> ruleNum;

/******************************************
Program file structure:

line 1 : comments
line 2 : File: <non_terminal> + .cpp
line 3 : Author: Aaron Pineda & Jacques L. Beauvoir
line 4 : Date: Spring 2018
line 5 : Description: <descript>
line 6 : comments
line 7 : endl
line 8 : #include <header_file> + h
line 9 : endl
line 10: int <header_file>::<non_terminal>()
line 11: {
line 13: int errors = 0;
line 14: static set<string> firsts = { <firsts> };
line 15: static set<string> follows = { <follows> };
line 16: endl
line 17: static set<string>::iterator itr1 = firsts.find(ct);
line 18: static set<string>::iterator itr2 = follows.find(ct);
line 19: while(itr1 == firsts.end() && itr2 == follows.end()) {
line 20: lex->ReportError("unexpected '" + ct + "' found at beginning of + <non_terminal>.");
line 21: errors++;
line 22: ct = lex->NextTerminal();
line 23: itr1 = firsts.find(ct);
line 24: itr2 = follows.find(ct);
line 25: }
line 26: return errors;
line 27: }
******************************************/
  //Creates an instance of ofstream, and opens example.txt
  ofstream a_file ( fileName+".cpp", ios::app );
  cout << "Enter Firsts" << endl;
  cin >> mysent;
  cout << "Enter Follows" << endl;
  cin >> mysent2;

  // Outputs to example.txt through a_file
  a_file << "#include \"SyntacticalAnalyzer.h\"" << "\n" << "\n"
	 << "int SyntacticalAnalyzer::" + fileName + "()" << "\n"
	 << "{" << "\n" << "\n" 
	 << "\t" << "int errors = 0;" << "\n" 
	 << "\t" << "p2file << \"Entering " << fileName 
	 << " function; current token is: \" " << "\n"
	 << "\t" << "\t" << "<< lex->GetTokenName (token) << endl;" << "\n" << "\n"
    
	 << "\t" << "p2file << \"Using Rule " << ruleNum
	 << "\" << endl;" << "\n" << "\n"  

	 << "\t" << "static set<string> firsts = {" << mysent << "};" << "\n"
	 << "\t" << "static set<string> follows = {" << mysent2 << "};" << "\n" << "\n"
	 << "\t" << "p2file << \"Exiting " << fileName 
	 << " function; current token is: \" " << "\n"
	 << "\t" << "\t" << "<< lex->GetTokenName (token) << endl;" << "\n"
	 << "\t" << "return errors;" << "\n"
	 << "}" << "\n";

  // Close the file stream explicitly
  a_file.close();
  return 0;
}
