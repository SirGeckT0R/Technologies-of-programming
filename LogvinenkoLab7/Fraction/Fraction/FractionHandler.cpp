#include "./FractionHandler.h"
#include "./ConsoleFractionHelper.h"
#include "./Validator.h"
#include <fstream>

Fraction FractionHandler::fractionFromFile(istream& fin) {
	char fractionInStr[MAX_LEN];
	char* end = 0;
	long numerator = 0, denumenator=1;
	bool flag = true;

	fin.getline(fractionInStr, MAX_LEN,' ');


	numerator = strtol(fractionInStr, &end, 10);

	if (end[0] == '/') {
		denumenator = strtol(++end, &end, 10);
	}

	Fraction rezFraction = Fraction(numerator, denumenator);

	return rezFraction;
}

Fraction* FractionHandler::fractionArrayFromConsole(int size) {
	Fraction* rezArray = new Fraction[size];
	for (int i = 0; i < size; i++) {
		cin>>rezArray[i];
	}

	return rezArray;
}

Fraction* FractionHandler::fractionArrayFromFile(char* filename,int size) {
	Fraction* rezArray = new Fraction[size];
	ifstream fin;
	
	fin.open(filename);

	if (fin.is_open()) {
		for (int i = 0; i < size; i++) {
			if (!fin.eof()) {
				rezArray[i] = FractionHandler::fractionFromFile(fin);
			}
			else {
				rezArray[i] = Fraction();
			}
		}
	}
	else {
		cout << "Can't open file: filling array with 0/1 fractions..." << endl;
		for (int i = 0; i < size; i++) {
			rezArray[i] = Fraction();
		}
	}

	fin.close();


	return rezArray;
}