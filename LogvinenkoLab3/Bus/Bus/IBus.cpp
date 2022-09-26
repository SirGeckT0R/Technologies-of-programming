#include <iostream>
#include <iomanip>
#include "IBus.h"
#include "IBusInfo.h"
#include "Validator.h"
using namespace std;

Bus IBus::inputBus() {
	Bus bus;
	Validator validator;
	int temp = 0;
	char input[MAX_LENGTH+1];
	char str[MAX_LENGTH];
	
	do {
		ignoreAll(cin);
		cout << "Enter name of the bus driver: ";
		cin >> setw(MAX_LENGTH+1) >> input;
	} while (strlen(input) <= 0 || strlen(input) >= MAX_LENGTH);
	strncpy_s(str, MAX_LENGTH, input, MAX_LENGTH);
	bus.setName(str);

	BusInfo info = IBusInfo::inputBusInfo();
	bus.setBusInfo(info);

	do {
		cout << "Enter the number of route: ";
		cin >> temp;
		temp=checkForNumber(cin, temp);
	} while (!validator.isNumberValid(temp,MAX_NUMBER));
	bus.setNumberRoute(temp);
	cout << endl;

	return bus;
}