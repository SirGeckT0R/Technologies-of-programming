#include "./FractionArray.h"
#include "./ConsoleFractionHelper.h"

void FractionArray::addToEvenElementOddElement(Fraction* fractionArray, int size) {
	for (int i = 0; i < size; i++) {
		int indexOfOdd = i + 1;
		if (isEven(i) && indexOfOdd < size) {
			fractionArray[i] = fractionArray[i] + fractionArray[indexOfOdd];
		}
	}
}

bool FractionArray::isEven(int number) {
	return !(number % 2);
}


int FractionArray::checkForNumber(istream& cin, int temp) {
	while (cin.fail()) {
		ConsoleFractionHelper::ignoreAll(cin);
		cout << "Please, enter the number:";
		cin >> temp;
	}
	return temp;
}