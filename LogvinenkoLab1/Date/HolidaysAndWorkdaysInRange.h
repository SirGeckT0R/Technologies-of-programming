#pragma once
#include "Date.h"
#include "HolidayList.h"
#include "Month.h"
#include "Weekdays.h"
#include "DateValidator.h"

void printHolidaysAndWorkdays(Date startDate, Date endDate,HolidayList *holidays,int amountOfYears, bool isSaturdayAWeekend);
bool checkForEndDate(Date currentDate, Date endDate);
int getDayOfTheWeek(int day, int month, int year);
bool checkHoliday(Holiday holiday, int day, int month);
void printListOfHolidays(string* holidays, int amountOfHolidays);