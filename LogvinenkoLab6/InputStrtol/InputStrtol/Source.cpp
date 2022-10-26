#include <iostream>
#include <iomanip>
#include <fstream>
#include "Parser.h"

using namespace std;

int main()
{
	ifstream fin;
	int resInt;
	double resDouble;

	resInt = Parser::ParseIntConsole();
	resDouble = Parser::ParseDoubleConsole();

	cout << "resInt from console=" << resInt << endl;
	cout << "resDouble from console=" << setprecision(NUM_LEN)<<resDouble << endl<<endl;

	resInt = Parser::ParseIntString("12412");
	resDouble = Parser::ParseDoubleString("12412.6343");
	cout << "resInt from string=" << resInt << endl;
	cout << "resDouble from a string=" << setprecision(NUM_LEN) << resDouble << endl<<endl;

	fin.open("./int.txt");
	if (fin.is_open()) {
		resInt = Parser::ParseIntFile(fin);
	}
	else {
		cout << "Can't open file."<<endl;
	}
	fin.close();

	fin.open("./double.txt");
	if (fin.is_open()) {
		resDouble = Parser::ParseDoubleFile(fin);
	}
	else {
		cout << "Can't open file." << endl;
	}
	fin.close();
	cout << "resInt from file=" << resInt << endl;
	cout << "resDouble from file=" << setprecision(NUM_LEN) << resDouble << endl << endl;
	system("pause");
}


