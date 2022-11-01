#include <iostream>
#include "./Fraction.h"
#include "./FractionException.h"
#include "./Validator.h"
#include "./ConsoleFractionHelper.h"
#include "./FractionHandler.h"
#include "./FractionArray.h"
#include <fstream>
#include <conio.h>

using namespace std;

int main() {
	try {
		Fraction fr1 = Fraction(4,6);
		Fraction fr2 = Fraction(8,12);

		fr1 = fr2;

		
		int size;
		do {
			cout << "Enter size of the array: ";
			cin >> size;
			size = FractionArray::checkForNumber(cin, size);
		} while (size <= 0);

		bool fromConsole=false;
		cout << "How do you want to enter the array: from console or from file?(c,f)";
		if (_getche() == 'c') {
			fromConsole = true;
		}

		
		Fraction* fractionArray = fromConsole ? FractionHandler::fractionArrayFromConsole(size) : FractionHandler::fractionArrayFromFile(size);

		FractionArray::addToEvenElementOddElement(fractionArray, size);

		cout <<"\nArray, where odd elements are added to even elements:"<< endl;
		for (int i = 0; i < size; i++) {
			fractionArray[i].simplifyFraction();
			cout <<fractionArray[i] << endl;
		}


	
	}
	catch (FractionException& e) {
		cout << "Exception caught: " << e.what() << endl;
	}
	return 0;
}