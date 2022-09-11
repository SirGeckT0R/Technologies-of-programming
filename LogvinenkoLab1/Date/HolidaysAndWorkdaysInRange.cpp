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

	while (true) {
		currentDay = currentDate.getDay();
		currentMonth = static_cast<int>(currentDate.getMonth());
		currentYear = currentDate.getYear();



		if (validator.isLeap(currentYear) && hasYearChanged) {
			lastMonthDay[1] = 29;
			hasYearChanged = false;
		}

		int currentHolidayDay;
		int currentHolidayMonth;
		bool isHoliday = false;
		for (int i = 0; i < HOLIDAY_AMOUNT; i++) {
			Holiday currentHoliday = holidays[holidayIndex].getHolidayByIndex(i);
			currentHolidayDay = currentHoliday.day;
			currentHolidayMonth =static_cast<int>(currentHoliday.month);
			
			if (currentDay == currentHolidayDay && currentMonth == currentHolidayMonth) {
				listOfHolidays[listOfHolidaysIndex] = currentHoliday.name;
				listOfHolidaysIndex++;
				isHoliday = true;
				amountOfWeekends++;
			}
		}

		if (!isHoliday) {
			int monthCode, yearCode = currentYear;
			if (currentMonth > 2)
				monthCode = currentMonth;
			else {
				monthCode = (12 + currentMonth);
				yearCode--;
			}
			int y = yearCode % 100;
			int c = yearCode / 100;
			int weekdayIndex = (currentDay + floor((13 * (monthCode + 1)) / 5) + y + floor(y / 4) + floor(c / 4) + (5 * c));
			weekdayIndex = weekdayIndex % 7;

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


		if (currentDate.getDay() == endDate.getDay()
			&& currentDate.getMonth() == endDate.getMonth()
			&& currentDate.getYear() == endDate.getYear()) {
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
			}
		}

	}
}