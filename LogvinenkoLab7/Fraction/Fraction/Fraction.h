#pragma once
#include <string>
#include <iostream>

using namespace std;

class Fraction {
	int* fraction;
public:
	Fraction();
	Fraction(int num, int den);
	Fraction(int* fractionInput);
	Fraction(const Fraction& inputFraction);
	~Fraction();

	int* getFraction();
	int getNum();
	int getDen();

	void setFraction(int* fractionInput);
	void setNum(int num);
	void setDen(int den);

	Fraction addFraction(const Fraction inputFraction);
	Fraction subtractFraction(const Fraction inputFraction);
	Fraction multiplyFraction(const Fraction inputFraction);
	Fraction divideFraction(const Fraction inputFraction);

	Fraction operator+(const Fraction);
	Fraction operator-(const Fraction);
	Fraction operator*(const Fraction);
	Fraction operator/(const Fraction);

	friend ostream& operator<<(ostream& os, const Fraction&);
	friend istream& operator>>(istream&, Fraction&);

	char* toString() const;
}; 