#pragma once
#include "Date.h"
#include "HolidayList.h"
#include "Month.h"
#include "Weekdays.h"
#include "DateValidator.h"

void printHolidaysAndWorkdays(Date startDate, Date endDate,HolidayList *holidays,int amountOfYears, bool isSaturdayAWeekend);