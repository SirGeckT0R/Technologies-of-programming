#include "./FractionException.h"
#include <string>
#include <iostream>
using namespace std;

FractionException::FractionException(const char* str) {
	strcpy_s(this->str, 200, str);
}

const char* FractionException::what() {
	return str;
}
