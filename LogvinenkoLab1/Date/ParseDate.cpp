#include "ParseDate.h"
#include <string>
#include "Date.h"

void parseStringInDate(char* inputString, Date &Date) {
	inputString = findCharachterAfterWhitespace(inputString);
	int day = atoi(static_cast<const char*>(inputString));
	Date.setDate(day);
	cout << Date.getDay() << endl;
	inputString = findCharachterAfterWhitespace(inputString);
	int month = atoi(static_cast<const char*>(inputString));
	Date.setMonth(month);
	cout <<static_cast<int>(Date.getMonth()) << endl;
	inputString = findCharachterAfterWhitespace(inputString);
	int year = atoi(static_cast<const char*>(inputString));
	Date.setYear(year);
	cout << Date.getYear() << endl;
	return;
}

char* findCharachterAfterWhitespace(char* string) {
	int index = 0;
	while (true) {
		if (string[index] == ' ') {
			string += ++index;
			return string;
		}
		index++;
	}
}