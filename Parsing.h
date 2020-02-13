
#ifndef PARSING_H
#define PARSING_H

#include <vector>
#include <string>


using namespace std;
class Parsing
{
public : 
	void Parsetoken(vector <string>& CmdTkns,
		vector <string>& ArgTkns,
		vector <string>& SepTkns,
		//vector <string>& qouted,
		string& mystring);

};
#endif // !PARSING_h
