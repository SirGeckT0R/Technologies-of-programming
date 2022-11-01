#include "./ConsoleFractionHelper.h"
#include "./Fraction.h"
#include "./Validator.h"
#include "./FractionException.h"


Fraction ConsoleFractionHelper::inputFractionConsole() {
	int num,den;
	cout << "\nEnter numerator of the fraction: ";
	cin >> num;

	char c;
	while (cin.fail()) {
		cin.clear();
		cin >> c;
		cin >> num;
	}
	ignoreAll(cin);

	cout << "Enter denumenator of the fraction: ";
	cin >> den;
	while (cin.fail()) {
		cin.clear();
		cin >> c;
		cin >> den;
	}
	ignoreAll(cin);

	Fraction resFrac = Fraction(num, den);

	return resFrac;
}

void ConsoleFractionHelper::ignoreAll(istream& is) {
	is.clear();
	is.sync();
	is.ignore(is.rdbuf()->in_avail());
}