#include <iostream>
#include <conio.h>
#include "Date.h"
#include "ExceptionDate.h"
#include "HolidayList.h"
#include "ParseDate.h"
#include "HolidaysAndWorkdaysInRange.h"

using namespace std;
 
int main() {
	try {

		/*Holiday* holidayList=HolidayList(2022);*/
		/*HolidayList holidaylist = HolidayList(2022);*/

		Date startDate, endDate;
		char inputString[11];

		cout << "Enter the starting date(example: 1 1 2022) ";
		cin.getline(inputString,11);

		parseStringInDate(inputString, startDate);

		cout << "Enter the ending date(example: 1 1 2022) ";
		cin.getline(inputString, 11);
		parseStringInDate(inputString, endDate);

		checkDates(startDate, endDate);

		bool isSaturdayAWeekend = false;
		cout << "Should I consider Saturday a weekend?(y,n)";
		if (_getche() == 'y') {
			isSaturdayAWeekend = true;
		}
		cout << endl;

		int startDateYear = startDate.getYear(); int endDateYear = endDate.getYear();
		int amountOfYears = endDateYear - startDateYear + 1;
		HolidayList* holidays = new HolidayList[amountOfYears];
		for (int i = 0; i < amountOfYears; i++) {
			holidays[i] = HolidayList(startDateYear + i);
		}

		//ÍÅ ÇÀÁÓÄÜ ÏÎÓÄÀËßÒÜ ÓÊÀÇÀÒÅËÈ

		printHolidaysAndWorkdays(startDate,endDate,holidays,amountOfYears,isSaturdayAWeekend);



	}
	catch(ExceptionDate& e)
	{
		cerr << "exception caught: " << e.what() << '\n';
	}
	system("pause");
}