#pragma once
#include <fstream>

using namespace std;

#define NUM_LEN 10
class Parser
{
public:
	static int ParseIntConsole(); 
	static double ParseDoubleConsole();
	static int ParseIntFile(istream& fin);
	static double ParseDoubleFile(istream& fin);
	static int ParseIntString(const char* str);
	static double ParseDoubleString(const char* str);
};

