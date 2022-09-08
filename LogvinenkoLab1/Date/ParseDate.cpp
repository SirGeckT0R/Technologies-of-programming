#include "ParseDate.h"
#include <string>
#include "Date.h"

void parseStringInDate(string inputString, Date &Date) {
	int day = stoi(inputString);
	Date.setDate(day);
	inputString = inputString.find(" ");
	cout << Date.getDay() << endl;
	int month = stoi(inputString);
	cout << month << endl;
	return;
}