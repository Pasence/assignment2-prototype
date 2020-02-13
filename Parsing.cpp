#ifndef PARSING_CPP
#define PARSING_CPP

#include "Parsing.h"
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void Parsing::Parsetoken(vector <string>& CmdTkns,
	vector <string>& ArgTkns,
	vector <string>& SepTkns,
	//vector <string>& qouted,
	string& mystring)
{
	vector<string> tokens; // vector where tokenized input string will be placed
	istringstream line(mystring);
	for (mystring; getline(line, mystring, ' ');) // tokenizes input string based on spaces
	{
		if (!mystring.empty())
		{
			tokens.push_back(mystring); // push tokens in to vector tokens
		}
	}
	string newString;
	string checkString;
	string Semiword;
	int k = 0; // k is a counter, resets after finding a connector 
	int z = 0;
	int a = 0;
	for (unsigned int i = 0; i < tokens.size(); i++) {

		// SEMICOLON PARSER **incomplete**, SEMICOLON PARSER COMPLETE!! AS OF 2/10 POG
		checkString = tokens[i]; // used for checking each letter of a token, used for #  and ; search
		
		if (checkString[0] == '#') // if token value starts with a # stop parsing
		{
			i = tokens.size() - 1 ;
		}
		/* if (checkString[0] == '"') // if first character of token has ", then is a qouted argument
		{
			for (unsigned int w = 1; w < checkString.length; w++) // put the first qouted word together without the '"'
			{

			}
			// add the next tokens together till a token with a ending qoute is found
			// add found word with ending qoute, then add to the added tokens, and push into arg vector
			// should add a counter to offset i to actual place
		} */
		else {
			if (checkString[checkString.length() - 1] == ';')
			{
				for (unsigned int p = 0; p < checkString.length() - 1; p++)
				{
					Semiword = Semiword + checkString[p];
				}
				ArgTkns.push_back(Semiword);
				SepTkns.push_back(";");
				Semiword.clear();
				i++;
				k = 0;
			}
			if (tokens[i] == "&&")
			{
				i++;
				SepTkns.push_back("&&");
				k = 0;
			}
			if (tokens[i] == "||")
			{
				i++;
				SepTkns.push_back("||");
				k = 0;
			}
			if (k == 0)
			{
				CmdTkns.push_back(tokens[i]);

			}
			else if (k != 0)
			{
				ArgTkns.push_back(tokens[i]);
			}
			k++;
			newString += tokens[i] + " ";
		}
	}


};

#endif // !PARSING_CPP
