#include "./Fraction.h"
#include "./Validator.h"
#include "./FractionException.h"
#include "./ConsoleFractionHelper.h"
#include <math.h>


Fraction::Fraction() {
	fraction = { 0,1 };
}

Fraction::Fraction(int num,int den) {
	fraction.push_back(num);
	fraction.push_back(den);
}

Fraction::Fraction(int* fractionInput) {
	Validator val;
	if (val.isDenumeratorValid(fractionInput[1])) {
		fraction.push_back(fractionInput[0]);
		fraction.push_back(fractionInput[1]);
	}
	else throw FractionException("Denumerator isn't valid!");
}


Fraction::Fraction(const Fraction& inputFraction) {
	if (fraction.size() < 1) {
		fraction.push_back(inputFraction.fraction.at(0));
		fraction.push_back(inputFraction.fraction.at(1));
	}
	else {
		setNum(inputFraction.fraction.at(0));
		setDen(inputFraction.fraction.at(0));
	}
}

Fraction::~Fraction() {
}


vector<int> Fraction::getFraction() {
	return fraction;
}

int Fraction::getNum() {
	return fraction.at(0);
}
int Fraction::getDen() {
	return fraction.at(1);
}

void Fraction::setFraction(int* fractionInput) {
	setNum(fraction[0]);
	setDen(fraction[1]);
}

void Fraction::setNum(int num) {
	fraction.at(0)=num;
}

void Fraction::setDen(int den) {
	Validator val;
	if (val.isDenumeratorValid(den)) {
		fraction.at(1) = den;
	}
	else throw FractionException("Denumerator isn't valid!");
}

Fraction Fraction::addFraction(const Fraction inputFraction) {
	int resultNum = inputFraction.fraction.at(1) * this->getNum() + this->getDen() * inputFraction.fraction.at(0);
	int resultDen = inputFraction.fraction.at(1) * this->getDen();
	Fraction fr = Fraction(resultNum, resultDen);
	fr.simplifyFraction();
	return fr;
}

Fraction Fraction::subtractFraction(const Fraction inputFraction) {
	int resultNum = inputFraction.fraction.at(1) * this->getNum() - this->getDen() * inputFraction.fraction.at(0);
	int resultDen = inputFraction.fraction.at(1) * this->getDen();
	Fraction fr = Fraction(resultNum, resultDen);
	fr.simplifyFraction();
	return fr;
}

Fraction Fraction::multiplyFraction(const Fraction inputFraction) {
	int resultNum = inputFraction.fraction.at(0) * this->getNum();
	int resultDen = inputFraction.fraction.at(1) * this->getDen();
	Fraction fr = Fraction(resultNum, resultDen);
	fr.simplifyFraction();
	return fr;
}

Fraction Fraction::divideFraction(const Fraction inputFraction) {
	int resultNum = inputFraction.fraction.at(1) * this->getNum();
	int resultDen = inputFraction.fraction.at(0) * this->getDen();
	Fraction fr = Fraction(resultNum, resultDen);
	fr.simplifyFraction();
	return fr;
}

void Fraction::simplifyFraction() {
	int numAbs = abs(getNum());
	int denAbs = abs(getDen());
	int min = (numAbs <= denAbs) ? numAbs : denAbs;
	int i = 2;
	while (i <= min) {
		if (getDen() % i == 0 && getNum() % i == 0) {
			setNum(fraction[0] / i);
			setDen(fraction[1] / i);
		}
		else {
			i++;
		}
	}
}

Fraction Fraction::operator+(Fraction inputFraction)
{
	return addFraction(inputFraction);
}

Fraction Fraction::operator-(Fraction inputFraction)
{
	return subtractFraction(inputFraction);
}
Fraction Fraction::operator*(Fraction inputFraction)
{
	return multiplyFraction(inputFraction);
}
Fraction Fraction::operator/(Fraction inputFraction)
{
	return divideFraction(inputFraction);
}
void Fraction::operator=(Fraction inputFraction)
{
	inputFraction.simplifyFraction();
	simplifyFraction();
	fraction[0] = inputFraction.fraction.at(0);
	fraction[1] = inputFraction.fraction.at(1);
}

bool Fraction::operator==(Fraction inputFraction)
{
	inputFraction.simplifyFraction();
	simplifyFraction();
	if (fraction[0] * inputFraction.fraction.at(1) == inputFraction.fraction.at(0) * fraction[1]) {
		return true;
	}
	return false;
}

bool Fraction::operator>(Fraction inputFraction)
{
	inputFraction.simplifyFraction();
	simplifyFraction();
	if (fraction[0] * inputFraction.fraction.at(1) > inputFraction.fraction.at(0) * fraction[1]) {
		return true;
	}
	return false;
}


bool Fraction::operator>=(Fraction inputFraction)
{
	inputFraction.simplifyFraction();
	simplifyFraction();
	if (fraction[0] * inputFraction.fraction.at(1) >= inputFraction.fraction.at(0) * fraction[1]) {
		return true;
	}
	return false;
}


bool Fraction::operator<(Fraction inputFraction)
{
	inputFraction.simplifyFraction();
	simplifyFraction();
	if (fraction[0] * inputFraction.fraction.at(1) < inputFraction.fraction.at(0) * fraction[1]) {
		return true;
	}
	return false;
}


bool Fraction::operator<=(Fraction inputFraction)
{
	inputFraction.simplifyFraction();
	simplifyFraction();
	if (fraction[0] * inputFraction.fraction.at(1) <= inputFraction.fraction.at(0) * fraction[1]) {
		return true;
	}
	return false;
}

bool Fraction::operator!=(Fraction inputFraction)
{
	inputFraction.simplifyFraction();
	simplifyFraction();
	if (fraction[0] * inputFraction.fraction.at(1) != inputFraction.fraction.at(0) * fraction[1]) {
		return true;
	}
	return false;
}



char* Fraction::toString() const {
	char* str=new char[MAX_LEN];
	char temp[MAX_LEN];
	_itoa_s(fraction[0],temp, 10);
	strcpy_s(str, MAX_LEN, temp);
	_itoa_s(fraction[1], temp, 10);
	strcat_s(str, 10, "/");
	strcat_s(str, MAX_LEN, temp);
	return str;
}

ostream& operator<<(ostream& os, const Fraction& inputFraction) {
	os << inputFraction.toString();
	return os;
}


istream& operator>>(istream& is, Fraction& fraction) {
	fraction = ConsoleFractionHelper::inputFractionConsole();
	return is;
}

