#include "./ExceptionCargo.h"

ExceptionCargo::ExceptionCargo(const char* str) {
	message = str;
}

string ExceptionCargo::what() {
	return message;
}
