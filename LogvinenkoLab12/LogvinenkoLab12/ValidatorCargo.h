#pragma once
#define MAX_NUM_WHEELS 15
#define MAX_NUM_CARTS 150
#define MAX_NUM_ENGINES 8
class ValidatorCargo {
public:
	static bool isNumberValid(double);
	static bool isNumberOfWheelsValid(int);
	static bool isNumberOfCartsValid(int);
	static bool isNumberOfEnginesValid(int);
};