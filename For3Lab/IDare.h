#pragma once
class IDate
{
	Date Date::inputDate() {
		Date date;
		int year, month, day;
		cout << "Enter date of birth" << endl;

		do {
			cout << "Enter year:" << endl;
			cin >> year;
		}
		cout << "Enter month:" << endl;
		cin >> month;
		cout << "Enter day:" << endl;
		cin >> day;
		date.setDate(year, month, day);
		return date;
	}
};

