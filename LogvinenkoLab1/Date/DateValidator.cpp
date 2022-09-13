#include "DateValidator.h"
#include <ctime>
#include "ExceptionDate.h"
#include "Month.h"

bool DateValidator::isYear(int year) {
	struct tm newtime;
	time_t now = time(NULL);
	localtime_s(&newtime, &now);
	//int currentDay = newtime.tm_mday;
	//int currentMonth = newtime.tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
	int currentYear = newtime.tm_year + 1900; // Year is # years since 1900
	if (year >= 1900 && year <= currentYear)
		return true;
	else throw ExceptionDate("The year is wrong!");
}

bool DateValidator::isMonth(int month) {
	//if (month >= 1 && month <= 12)
	if (month >= static_cast<int>(Month::JAN) && month <= static_cast<int>(Month::DEC))
		return true;
	else throw ExceptionDate("The month is wrong!");
}
bool DateValidator::isLeap(int year) {
	return !(year % 4 != 0 || year % 100 == 0 && year % 400 != 0);
}