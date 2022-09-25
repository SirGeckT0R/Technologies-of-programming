#include <time.h>
#include "Validator.h"
#include "Exception.h"


bool Validator::isYearValid(int year) {
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	//int currentDay = newtime.tm_mday;
	//int currentMonth = newtime.tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
	int currentYear = newtime.tm_year + 1900; // Year is # years since 1900
	if (year >= 0 && year <= currentYear)
		return true;
	else return false;
}


bool Validator::isNumberValid(int number) {
	if (number >= 0 && number <= MAX_NUMBER) {
		return true;
	}
	else return false;
}

bool Validator::isMileageValid(int mileage) {
	if (mileage >= 0 && mileage <= MAX_MILEAGE) {
		return true;
	}
	else return false;
}
