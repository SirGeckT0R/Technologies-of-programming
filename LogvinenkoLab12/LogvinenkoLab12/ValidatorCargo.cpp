#include "ValidatorCargo.h"

bool ValidatorCargo::isNumberValid(double num) {
	if (num >= 0) {
		return true;
	}
	return false;
}

bool ValidatorCargo::isPriceValid(double num) {
	if (num >= 0 && num <= MAX_PRICE) {
		return true;
	}
	return false;
}

bool ValidatorCargo::isNumberOfWheelsValid(int num) {
	if (num >= 0 && num<=MAX_NUM_WHEELS) {
		return true;
	}
	return false;
}

bool ValidatorCargo::isNumberOfCartsValid(int num) {
	if (num >= 0 && num <= MAX_NUM_CARTS) {
		return true;
	}
	return false;
}

bool ValidatorCargo::isNumberOfEnginesValid(int num) {
	if (num >= 0 && num <= MAX_NUM_ENGINES) {
		return true;
	}
	return false;
}