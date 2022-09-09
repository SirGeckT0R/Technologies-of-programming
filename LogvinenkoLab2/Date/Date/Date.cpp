#include "Date.h"
#include "ExceptionDate.h"
#include "DateValidator.h"
#include <iostream>
#include <time.h>
using namespace std;

Date::Date(){
	struct tm newtime;
	time_t now = time(NULL);
	localtime_s(&newtime, &now);
	this->day = newtime.tm_mday;
	this->month = static_cast<Month>(newtime.tm_mon + 1); // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
	this->year = newtime.tm_year + 1900; // Year is # years since 1900
}

Date::Date(int day, int month, int year) {
	setYear(year);
	setMonth(month);
	setDate(day, month, year);
}

Date::~Date() {}

void Date::setMonth(int month) {
	DateValidator validator;
	if (validator.isYear(month))
		this->month = static_cast<Month>(month);
}

void Date::setYear(int year) {
	DateValidator validator;
	if (validator.isYear(year))
		this->year = year;
}
void Date::setDate(int day, int month, int year) {
	int lastMonthDay[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	DateValidator validator;
	if (validator.isYear(year) && validator.isMonth(month)) {
		if (validator.isLeap(year))
			lastMonthDay[1] = 29;
		if (day >= 1 && day <= lastMonthDay[month - 1])
			this->day = day;
		else throw ExceptionDate("The day is wrong!");
	}
	else throw ExceptionDate("The year ore month is wrong!");
}

int Date::getDay() {
	return day;
}

Month Date::getMonth() {
	return month;
}

int Date::getYear() {
	return year;
}

char* Date::toCharArray() {
	const int sizeStr = 100;
	char* str = new char[sizeStr];
	char temp[sizeStr];//3-для дня, либо 5-для года
	_itoa_s(day, temp, 10);
	strcpy_s(str, sizeStr, temp);
	strcat_s(str, sizeStr, " ");
	strcat_s(str, sizeStr, MONTHSTR[static_cast<int>(month)-1]);
	strcat_s(str, sizeStr, " ");
	_itoa_s(year, temp, 10);
	strcat_s(str, sizeStr, temp);
	return str;
}

std::string Date::toString() {
	std::string str;
	str = std::to_string(day);
	str = str + " " + MONTHSTRING[static_cast<int>(month) - 1] + " ";
	str += std::to_string(year);
	
	return str;
}
