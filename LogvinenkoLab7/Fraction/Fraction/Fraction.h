#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Fraction {
	vector<int> fraction;
public:
	Fraction();
	Fraction(int num, int den);
	Fraction(int* fractionInput);
	Fraction(const Fraction& inputFraction);
	~Fraction();

	vector<int> getFraction();
	int getNum();
	int getDen();

	void setFraction(int* fractionInput);
	void setNum(int num);
	void setDen(int den);

	Fraction addFraction(const Fraction inputFraction);
	Fraction subtractFraction(const Fraction inputFraction);
	Fraction multiplyFraction(const Fraction inputFraction);
	Fraction divideFraction(const Fraction inputFraction);
	void simplifyFraction();

	Fraction operator+(const Fraction);
	Fraction operator-(const Fraction);
	Fraction operator*(const Fraction);
	Fraction operator/(const Fraction);
	void operator=(const Fraction);
	bool operator==(Fraction inputFraction);
	bool operator>(const Fraction inputFraction);
	bool operator>=(Fraction inputFraction);
	bool operator<=(const Fraction inputFraction);
	bool operator<(const Fraction inputFraction);
	bool operator!=(const Fraction inputFraction);

	friend ostream& operator<<(ostream& os, const Fraction& fraction);
	friend istream& operator>>(istream& is, Fraction& fraction);

	char* toString() const;
}; 