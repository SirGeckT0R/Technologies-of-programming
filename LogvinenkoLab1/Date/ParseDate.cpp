#include "ParseDate.h"

void parseStringInDate(char* inputString, Date& Date) {
	if (inputString[0] == ' ') {
		inputString = findCharachterAfterWhitespace(inputString);
	}
	int day = atoi(static_cast<const char*>(inputString));
	Date.setDay(day);
	cout << Date.getDay() << endl;
	inputString = findCharachterAfterWhitespace(inputString);
	int month = atoi(static_cast<const char*>(inputString));
	Date.setMonth(month);
	cout << static_cast<int>(Date.getMonth()) << endl;
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

void checkDates(Date& startDate, Date& endDate) {
	int startDay = startDate.getDay();
	int startMonth = static_cast<int>(startDate.getMonth());
	int startYear = startDate.getYear();
	int endDay = endDate.getDay();
	int endMonth = static_cast<int>(endDate.getMonth());
	int endYear = endDate.getYear();
	bool areDatesWrong = false;
	bool isDayIncorrect = ((endDay - startDay) < 0 && (endMonth - startMonth) >= 0) && (endYear - startYear) >= 0;
	bool isMonthIncorrect = (endMonth - startMonth) < 0 && (endYear - startYear) >= 0;
	bool isYearIncorrect = (endYear - startYear) < 0;

	if (isDayIncorrect || isMonthIncorrect || isYearIncorrect) {
		areDatesWrong = true;
	}
	if (areDatesWrong) {
		cout << "You misplaced the dates. Rearranging for you..." << endl;
		startDate.setDay(endDay);
		startDate.setMonth(endMonth);
		startDate.setYear(endYear);
		endDate.setDay(startDay);
		endDate.setMonth(startMonth);
		endDate.setYear(startYear);
		return;
	}
}