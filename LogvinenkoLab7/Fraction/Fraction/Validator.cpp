#include "./Validator.h"

bool Validator::isDenumeratorValid(int den) {
	if (den != 0) {
		return true;
	}
	return false;
}