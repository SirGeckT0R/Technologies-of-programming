#include <string>
#include <iostream>
#include "Exception.h"
using namespace std;

Exception::Exception(const char* str) {
	strcpy_s(this->str, 200, str);
}

const char* Exception::what() {
	return str;
}
