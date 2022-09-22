#include <iostream>
#include "IDate.h"
#include "DateValidator.h"
using namespace std;

Date IDate::iConsole() {
	Date date;
	int year, month, day;
	DateValidator validator;
	do {		
		cout << "Enter year of birth:" << endl;
		cin >> year;
	} while (!validator.isYearValid(year));

	do {
	cout << "Enter month:" << endl;
	cin >> month;
	} while (!validator.isMonthValid(month));

	do {
	cout << "Enter day:" << endl;
	cin >> day;
	} while (!validator.isDayValid(day, month, year));
	date.setDate(day, month, year);
	return date;
}