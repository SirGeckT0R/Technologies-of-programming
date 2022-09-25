#include <iostream>
#include "IBus.h"
#include "IBusInfo.h"
#include "Validator.h"
using namespace std;

Bus IBus::inputBus() {
	Bus bus;
	Validator validator;
	int temp = 0;
	string str = "";
	
	ignoreAll(cin);
	do {
		cout << "Enter name of the bus driver: ";
		cin >> str;
	} while (str.length() <= 0 || str.length() > MAX_LENGTH);
	bus.setName(str);

	BusInfo info = IBusInfo::inputBusInfo();
	bus.setBusInfo(info);

	ignoreAll(cin);
	do {
		cout << "Enter the number of route: ";
		cin >> temp;
		temp=checkForNumber(cin, temp);
	} while (!validator.isNumberValid(temp));
	bus.setNumberRoute(temp);
	cout << endl;

	return bus;
}