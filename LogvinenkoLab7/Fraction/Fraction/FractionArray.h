#pragma once
#include "./Fraction.h"

class FractionArray {
public:

	static void addToEvenElementOddElement(Fraction* fractionArray, int size);
	static bool isEven(int number);
	static int checkForNumber(istream& cin, int temp);

};