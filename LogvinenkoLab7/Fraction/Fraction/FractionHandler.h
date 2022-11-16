#pragma once
#include "./Fraction.h"

class FractionHandler {
public:
	static Fraction fractionFromFile(istream& fin);
	static Fraction* fractionArrayFromConsole(int size);
	static Fraction* fractionArrayFromFile(char* filename,int size);
};
