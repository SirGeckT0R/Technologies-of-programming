#pragma once
const int MAX_NUMBER = 99999;
const int MAX_MILEAGE = 1000000;
const int MAX_LENGTH = 100;
class Validator
{
public:
	bool isYearValid(int year);
	bool isNumberValid(int number);
	bool isMileageValid(int mileage);
};

