#include <iostream>
#include <iomanip>
#include "IBusInfo.h"
#include "Validator.h"
using namespace std;


BusInfo IBusInfo::inputBusInfo() {
	BusInfo info;
	Validator validator;
	int temp=0;
	char input[MAX_LENGTH + 1];
	char str[MAX_LENGTH];
	do {
		cout << "Enter number of the bus:";
		cin >> temp;
		temp = checkForNumber(cin, temp);
	} while (!validator.isNumberValid(temp,MAX_NUMBER));
	info.setNumber(temp);

	do {
		ignoreAll(cin);
		cout << "Enter name of the bus driver: ";
		cin >> setw(MAX_LENGTH + 1) >> input;
	} while (strlen(input) <= 0 || strlen(input) >= MAX_LENGTH);
	strncpy_s(str, MAX_LENGTH, input, MAX_LENGTH);
	info.setBrand(str);

	do {
		cout << "Enter the year of exploitation:";
		cin >> temp;
		temp = checkForNumber(cin, temp);
	} while (!validator.isYearValid(temp));
	info.setYear(temp);

	do {
		cout << "Enter the mileage:";
		cin >> temp;
		temp = checkForNumber(cin, temp);
	} while (!validator.isNumberValid(temp,MAX_MILEAGE));
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