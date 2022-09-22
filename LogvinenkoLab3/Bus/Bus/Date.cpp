#include <iostream>
#include <time.h>
#include "Date.h"
#include "Exception.h"
#include "Validator.h"
using namespace std;

Date::Date(){
	struct tm newtime;
	time_t now = time(0);
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
	Validator validator;
	if (validator.isMonthValid(month))
		this->month = static_cast<Month>(month);
	else throw Exception("The month is wrong!");
}

void Date::setYear(int year) {
	Validator validator;
	if (validator.isYearValid(year))
		this->year = year;
	else throw Exception("The year is wrong!");
}
void Date::setDate(int day, int month, int year) {
	Validator validator;
	if (validator.isDayValid(day, month, year)) {
		this->day = day;
		this->month = static_cast<Month>(month);
		this->year = year;
	}
	else throw Exception("The date is wrong!");
}

int Date::getDay() {
	return day;
}

int Date::getMonth() {
	return month;
}

int Date::getYear() {
	return year;
}

char* Date::toCharArray() {
	char* str = new char[100];
	char strForDay[5];//3-для дня, либо 5-для года
	_itoa_s(day, strForDay, 10);
	strcpy_s(str, 3, strForDay);
	strcat_s(str, 4, " ");
	strcat_s(str, 13, monthStr[month-1]);
	strcat_s(str, 14, " ");
	_itoa_s(year, strForDay, 10);
	strcat_s(str, 18, strForDay);
	return str;
}

std::string Date::toString() {
	std::string str;
	str = std::to_string(day);
	str = str + " " + monthString[month - 1] + " ";
	str += std::to_string(year);
	
	return str;
}
