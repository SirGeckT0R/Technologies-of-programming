#include "HolidaysAndWorkdaysInRange.h"


void printHolidaysAndWorkdays(Date startDate, Date endDate, HolidayList* holidays, int amountOfYears,bool isSaturdayAWeekend) {
	int lastMonthDay[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	DateValidator validator;
	int amountOfDays = 0, amountOfWorkingDays = 0, amountOfWeekends = 0;
	Date currentDate = startDate;
	int currentDay, currentMonth, currentYear;
	int holidayIndex = 0;
	string* listOfHolidays=new string[amountOfYears * HOLIDAY_AMOUNT];
	int listOfHolidaysIndex = 0;
	bool hasYearChanged = false;
	bool isEndDate;

	while (true) {
		currentDay = currentDate.getDay();
		currentMonth = static_cast<int>(currentDate.getMonth());
		currentYear = currentDate.getYear();


		if (validator.isLeap(currentYear) && hasYearChanged) {
			lastMonthDay[1] = 29;
			hasYearChanged = false;
		}

		
		bool isHoliday = false;
		for (int i = 0; i < HOLIDAY_AMOUNT; i++) {
			Holiday currentHoliday = holidays[holidayIndex].getHolidayByIndex(i);
			if (checkHoliday(currentHoliday, currentDay, currentMonth)) {
				listOfHolidays[listOfHolidaysIndex] = currentHoliday.name;
				listOfHolidaysIndex++;
				isHoliday = true;
				amountOfWeekends++;
			}
		}

		if (!isHoliday) {
			int weekdayIndex = getDayOfTheWeek(currentDay,currentMonth,currentYear);

			if (isSaturdayAWeekend) {
				if (weekdayIndex >= 2) {
					amountOfWorkingDays++;
				}
				else {
					amountOfWeekends++;
				}
			}
			else {
				if (weekdayIndex == 1) {
					amountOfWeekends++;
				}
				else {
					amountOfWorkingDays++;
				}
			}
		}
		amountOfDays++;


		isEndDate=checkForEndDate(currentDate, endDate);
		if (isEndDate) {
			break;
		}

		currentDay++;
		if (validator.isYear(currentYear) && validator.isMonth(static_cast<int>(currentMonth))) {
			
			if (currentDay >= 1 && currentDay <= lastMonthDay[static_cast<int>(currentMonth) - 1]) {
				currentDate.setDay(currentDay);
			}
			else if(currentMonth!=12) {
				currentMonth++;
				currentDate.setMonth(currentMonth);
				currentDate.setDay(1);
			}
			else {
				currentYear++;
				currentMonth = 1;
				currentDate.setYear(currentYear);
				currentDate.setMonth(currentMonth);
				currentDate.setDay(1);
				hasYearChanged = true;
				holidayIndex++;
			}
		}
	}

	cout << "Amount of days in this period:" << amountOfDays << endl;
	cout << "Amount of working days in this period:" << amountOfWorkingDays << endl;
	cout << "Amount of weekends in this period:" << amountOfWeekends << endl;

	printListOfHolidays(listOfHolidays, listOfHolidaysIndex);
	delete[] listOfHolidays;
}

bool checkForEndDate(Date currentDate, Date endDate) {
	if (currentDate.getDay() == endDate.getDay()
		&& currentDate.getMonth() == endDate.getMonth()
		&& currentDate.getYear() == endDate.getYear()) {
		return true;
	}
	return false;
}

int getDayOfTheWeek(int day,int month,int year) {
	int monthCode, yearCode = year;
	if (month > 2)
		monthCode = month;
	else {
		monthCode = (12 + month);
		yearCode--;
	}
	int y = yearCode % 100;
	int c = yearCode / 100;
	int weekdayIndex = (day + floor((13 * (monthCode + 1)) / 5) + y + floor(y / 4) + floor(c / 4) + (5 * c));
	weekdayIndex = weekdayIndex % 7;
	return weekdayIndex;
}

bool checkHoliday(Holiday holiday, int day, int month) {
	int currentHolidayDay= holiday.day;
	int currentHolidayMonth = static_cast<int>(holiday.month);
	return (day == currentHolidayDay && month == currentHolidayMonth);
}

void printListOfHolidays(string* holidays,int amountOfHolidays) {
	cout << "Holidays, that were in this period of time:" << endl;
	for (int i = 0; i < amountOfHolidays; i++) {
		cout << holidays[i];
		if (i == amountOfHolidays - 1) {
			cout << ". ";
			break;
		}
		cout <<", ";
	}
	cout << endl;
}