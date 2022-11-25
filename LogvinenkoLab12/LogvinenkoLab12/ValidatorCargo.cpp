#include "ValidatorCargo.h"

bool ValidatorCargo::isNumberValid(double num) {
	if (num >= 0) {
		return true;
	}
	return false;
}