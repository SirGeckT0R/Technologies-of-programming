#include <iostream>
#include <conio.h>
#include "Date.h"
#include "ExceptionDate.h"
#include "HolidayList.h"
#include "ParseDate.h"

using namespace std;
 
int main() {
	try {

		/*Holiday* holidayList=HolidayList(2022);*/
		/*HolidayList holidaylist = HolidayList(2022);*/

		Date startDate, endDate;
		char inputString[10];

		cout << "Enter the starting date(example: 1 1 2022) ";
		cin.getline(inputString,10);

		parseStringInDate(inputString, startDate);

		cout << "Enter the ending date(example: 1 1 2022) ";
		cin.getline(inputString, 10);
		parseStringInDate(inputString, endDate);

		int startDateYear = startDate.getYear(); int endDateYear = endDate.getYear();
		int amountOfYears = endDateYear - startDateYear + 1;
		HolidayList* holidays = new HolidayList[amountOfYears];
		if (amountOfYears==1) {
			holidays[0] = HolidayList(startDateYear);
		}
		else {
			for (int i = 0; i < amountOfYears; i++) {
				holidays[i] = HolidayList(startDateYear + i);
			}
		}


		bool isSaturdayAWeekend = false;
		cout << "Should I consider Saturday a weekend?(y,n)";
		if (_getche() == 'y') {
			isSaturdayAWeekend = true;
		}
		cout << endl;

		tm time_in = { 0, 0, 0, 9, 8, 2022 - 1900 }; 
		time_t time_buff = mktime(&time_in);

		struct tm time_out;
		localtime_s(&time_out,&time_buff);


		Date date;
				
		cout << date.toCharArray() << endl;
		cout << date.toString() << endl;
	}
	catch(ExceptionDate& e)
	{
		cerr << "exception caught: " << e.what() << '\n';
	}
	system("pause");
}