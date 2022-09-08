#include <iostream>
#include "Date.h"
#include "ExceptionDate.h"
#include "HolidayList.h"
#include "ParseDate.h"

using namespace std;
 
int main() {
	try {

		/*Holiday* holidayList=HolidayList(2022);*/
		HolidayList holidaylist = HolidayList(2022);

		Date startDate, endDate;
		string inputString;

		cout << "Enter the starting date(example: 1 1 2022) ";
		getline(cin,inputString);
		parseStringInDate(inputString, startDate);

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