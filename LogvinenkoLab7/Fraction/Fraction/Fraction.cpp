#include "./Fraction.h"
#include "./Validator.h"
#include "./FractionException.h"

bool validateDenumerator(int den);

Fraction::Fraction() {
	if (!this->fraction) {
		this->fraction = new int[2];
	}
	this->fraction[0] = 0; this->fraction[1] = 1;
}

Fraction::Fraction(int num,int den) {
	validateDenumerator(den);
	if (!this->fraction) {
		this->fraction = new int[2];
	}
	this->fraction[0] = num; this->fraction[1] = den;
}

Fraction::Fraction(int* fractionInput) {
	if (!this->fraction) {
		this->fraction = new int[2];
	}
	this->fraction[0] = fractionInput[0]; this->fraction[1] = fractionInput[1];
}


Fraction::Fraction(const Fraction& inputFraction) {
	fraction = new int[2];
	fraction[0] = inputFraction.fraction[0];
	fraction[1] = inputFraction.fraction[1];
}

Fraction::~Fraction() {
	delete[] this->fraction;
}


int* Fraction::getFraction() {
	return this->fraction;
}

int Fraction::getNum() {
	return this->fraction[0];
}
int Fraction::getDen() {
	return this->fraction[1];
}

void Fraction::setFraction(int* fractionInput) {
	this->fraction[0] = fractionInput[0];
	this->fraction[1] = fractionInput[1];
}

void Fraction::setNum(int num) {
	this->fraction[0] = num;
}

void Fraction::setDen(int den) {
	validateDenumerator(den);
	this->fraction[1] = den;
}

Fraction Fraction::addFraction(const Fraction inputFraction) {
	int resultNum = inputFraction.fraction[1] * this->getNum() + this->getDen() * inputFraction.fraction[0];
	int resultDen = inputFraction.fraction[1] * this->getDen();
	Fraction fr = Fraction(resultNum, resultDen);

	return fr;
}

Fraction Fraction::subtractFraction(const Fraction inputFraction) {
	int resultNum = inputFraction.fraction[1] * this->getNum() - this->getDen() * inputFraction.fraction[0];
	int resultDen = inputFraction.fraction[1] * this->getDen();
	Fraction fr = Fraction(resultNum, resultDen);

	return fr;
}

Fraction Fraction::multiplyFraction(const Fraction inputFraction) {
	int resultNum = inputFraction.fraction[0] * this->getNum();
	int resultDen = inputFraction.fraction[1] * this->getDen();
	Fraction fr = Fraction(resultNum, resultDen);

	return fr;
}

Fraction Fraction::divideFraction(const Fraction inputFraction) {
	int resultNum = inputFraction.fraction[1] * this->getNum();
	int resultDen = inputFraction.fraction[0] * this->getDen();
	Fraction fr = Fraction(resultNum, resultDen);

	return fr;
}

Fraction Fraction::operator+(const Fraction m)
{
	return addFraction(m);
}

Fraction Fraction::operator-(const Fraction m)
{
	return subtractFraction(m);
}
Fraction Fraction::operator*(const Fraction m)
{
	return multiplyFraction(m);
}
Fraction Fraction::operator/(const Fraction m)
{
	return divideFraction(m);
}

char* Fraction::toString() const {
	char* str=new char[10];
	char temp[10];
	_itoa_s(fraction[0],temp,10);
	strcpy_s(str, 10, temp);
	_itoa_s(fraction[1], temp, 10);
	strcat_s(str, 10, "/");
	strcat_s(str, 10, temp);
	return str;
}

ostream& operator<<(ostream& os, const Fraction& inputFraction) {
	os << inputFraction.toString();
	return os;
}


bool validateDenumerator(int den) {
	Validator val;
	if (val.isDenumeratorValid(den)){
		return true;
	}
	else throw FractionException("Denumerator isn't valid!");
}