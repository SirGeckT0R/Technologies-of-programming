#include <iostream>
#include "IBusInfo.h"
#include "Validator.h"
using namespace std;


BusInfo IBusInfo::inputBusInfo() {
	BusInfo info;
	Validator validator;
	int temp=0;
	string str="";

	ignoreAll(cin);
	do {
		cout << "Enter number of the bus:";
		cin >> temp;
		temp = checkForNumber(cin, temp);
	} while (!validator.isNumberValid(temp));
	info.setNumber(temp);

	ignoreAll(cin);
	do {
		cout << "Enter brand of the bus: ";
		cin >> str;
	} while (str.length() <= 0 || str.length() > MAX_LENGTH);
	info.setBrand(str);

	ignoreAll(cin);
	do {
		cout << "Enter the year of exploitation:";
		cin >> temp;
		temp = checkForNumber(cin, temp);
	} while (!validator.isYearValid(temp));
	info.setYear(temp);

	ignoreAll(cin);
	do {
		cout << "Enter the mileage:";
		cin >> temp;
		temp = checkForNumber(cin, temp);
	} while (!validator.isMileageValid(temp));
	info.setMileage(temp);

	return info;
}


/// Сбросить флаги ошибок и содержимое буфера потока.
void ignoreAll(istream& is)
{
	is.clear(); // Сброс ошибок.
	is.sync();  // Синхронизация объекта потока с внешним устройством.
	is.ignore(is.rdbuf()->in_avail()); // Сброс символов уже считанных в буфер потока.
}

int checkForNumber(istream& cin, int temp) {
	while (cin.fail()) {
		ignoreAll(cin);
		cout << "Please, enter the number:";
		cin >> temp;
	}
	return temp;
}