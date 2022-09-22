#include <string>
#include <iostream>
#include "ExceptionDate.h"
using namespace std;

ExceptionDate::ExceptionDate(const char* str) {
	strcpy_s(this->str, 200, str);
}

const char* ExceptionDate::what() {
	return str;
}
