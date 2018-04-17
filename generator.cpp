#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
  string sentence;
  string mysent;
  string mysent2;
  string fileName;

  cout << "Enter the filename w/o .cpp : ";
  cin >> fileName;


  //Creates an instance of ofstream, and opens example.txt
  ofstream a_file ( fileName+".cpp", ios::app );
  cout << "Enter Firsts" << endl;
  cin >> mysent;
  cout << "Enter Follows" << endl;
  cin >> mysent2;

  // Outputs to example.txt through a_file
  a_file << "int " + fileName + "()" << "\n"
	 << "{" << "\n"
	 << "\t" << "static set<string> firsts = {" << mysent << "};" << "\n"
	 << "\t" << "static set<string> follows = {" << mysent2 << "};" << "\n"
	 << "\t" << "return 0;" << "\n"
	 << "}" << "\n";

  // Close the file stream explicitly
  a_file.close();
  return 0;
}
