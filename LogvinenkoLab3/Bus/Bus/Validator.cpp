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

bool Validator::isMonthValid(int month) {
	if (month >= 1 && month <= 12)
		return true;
	else return false;
}
bool Validator::isLeap(int year) {
	return !(year % 4 != 0 || year % 100 == 0 && year % 400 != 0);
}

bool Validator::isDayValid(int day, int month, int year) {
	int lastMonthDay[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isYearValid(year) && isYearValid(month)) {
		if (isLeap(year))
			lastMonthDay[1] = 29;
		if (day >= 1 && day <= lastMonthDay[month - 1])
			return true;
		else return false;
	}
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
