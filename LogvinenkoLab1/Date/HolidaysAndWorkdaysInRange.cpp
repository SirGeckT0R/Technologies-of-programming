#include "HolidaysAndWorkdaysInRange.h"


void printHolidaysAndWorkdays(Date startDate, Date endDate, HolidayList* holidays, int amountOfYears,bool isSaturdayAWeekend) {
	int lastMonthDay[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	DateValidator validator;
	int amountOfDays = 0, amountOfWorkingDays = 0, amountOfWeekends = 0;
	Date currentDate = startDate;
	int holidayIndex = 0;
	char** listOfHolidays=new char*[amountOfYears*HOLIDAY_AMOUNT];
	int listOfHolidaysIndex = 0;

	while (true) {
		int currentDay = currentDate.getDay();
		int currentMonth = static_cast<int>(currentDate.getMonth());
		int currentYear = currentDate.getYear();
		bool hasYearChanged = false;

		if (validator.isLeap(currentYear) && hasYearChanged) {
			lastMonthDay[1] = 29;
		}

		int currentHolidayDay;
		int currentHolidayMonth;
		char* currentHolidayName = new char[20];
		for (int i = 0; i < HOLIDAY_AMOUNT; i++) {
			Holiday currentHoliday = holidays[holidayIndex].getHolidayByIndex(i);
			currentHolidayDay = currentHoliday.day;
			currentHolidayMonth =static_cast<int>(currentHoliday.month);
			strcpy_s(currentHolidayName,20,currentHoliday.name);
			
			if (currentDay == currentHolidayDay && currentMonth == currentHolidayMonth) {
				listOfHolidays[listOfHolidaysIndex] = currentHolidayName;
				listOfHolidaysIndex++;
			}
		}




		if (validator.isYear(currentYear) && validator.isMonth(static_cast<int>(currentMonth))) {
			
			if (currentDay >= 1 && currentDay <= lastMonthDay[static_cast<int>(currentMonth) - 1]) {

			}
		}


		amountOfDays++;
	}
}