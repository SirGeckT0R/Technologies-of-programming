#include <iostream>
#include "./Fraction.h"
#include "./FractionException.h"
#include "./Validator.h"

using namespace std;

int main() {
	try {
		Fraction fr1=Fraction(1,2);
		Fraction fr2=Fraction(1,3);
		cout << fr1.addFraction(fr2) << endl;
		cout << fr1.subtractFraction(fr2) << endl;
		cout << fr1.multiplyFraction(fr2) << endl;
		cout << fr1.divideFraction(fr2) << endl<<endl;


		cout << fr1 + fr2 << endl;
		cout << fr1 - fr2 << endl;
		cout << fr1 * fr2<< endl;
		cout << fr1 / fr2<< endl;
	}
	catch (FractionException& e) {
		cout << "Exception caught: " << e.what() << endl;
	}
	return 0;
}