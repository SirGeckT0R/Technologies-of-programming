#pragma once
#include <string>
using namespace std;

class ExceptionCargo {
	string message;
public:
	ExceptionCargo(const char*);
	string what();
};