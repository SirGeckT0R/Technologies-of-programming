#pragma once
#include "./Fraction.h"
#include "./Validator.h"

using namespace std;

class ConsoleFractionHelper {
public:
	static Fraction inputFractionConsole();
	static void ignoreAll(istream&);
};