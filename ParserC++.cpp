

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Parsing.h"


using namespace std;

int main()
{
	string newString;
	string checkString;
	string Semiword;
	int k = 0;
	int z = 0;
	int a = 0;
	string mystring1;
	cout << "$ ";
	getline(cin, mystring1);
	vector<string> tokens1;
	vector<string> SepTkns1;
	vector<string> CmdTkns1;
	vector<string> ArgTkns1;
	Parsing ParseString;
	ParseString.Parsetoken(CmdTkns1,
		ArgTkns1,
		SepTkns1,
		//vector <string>& qouted,
		mystring1);

	//checks if all words are properly tokenized
	cout << newString << endl;
	cout << "SepTkns:";
	for (unsigned int b = 0; b < SepTkns1.size(); b++)
	{
		cout << SepTkns1[b] << " | ";
	}cout << endl;
	cout << "ArgTkns:";
	for (unsigned int c = 0; c < ArgTkns1.size(); c++)
	{
		cout << ArgTkns1[c] << " | ";
	}cout << endl;
	cout << "CmdTkns:";
	for (unsigned int b = 0; b < CmdTkns1.size(); b++)
	{
		cout << CmdTkns1[b] << " | ";
	}cout << endl;
	return 0;
}

