#include <string>
#include <iostream>
#include "HandleException.h"
using namespace std;

HandleException::HandleException(const char* str) {
	strcpy_s(this->str, 200, str);
}

const char* HandleException::what() {
	return str;
}
