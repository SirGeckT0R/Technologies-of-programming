#include "Bus.h"
#include <string>

Bus::~Bus() {}

Bus::Bus() {
	strcpy_s(this->nameOfDriver,2," ");
	this->busInfo = BusInfo();
	this->numberOfRoute = 0;
}

Bus::Bus(char* nameOfDriver, int numberOfRoute, int numberOfBus, char* brand, int yearOfExploitation, int mileage) {
	setName(nameOfDriver);
	setBusInfo(numberOfBus, brand, yearOfExploitation, mileage);
	setNumberRoute(numberOfRoute);
}

Bus::Bus(char* nameOfDriver, int numberOfRoute, BusInfo busInfo) {
	setName(nameOfDriver);
	setBusInfo(busInfo);
	setNumberRoute(numberOfRoute);
}

char* Bus::getName() {
	return this->nameOfDriver;
}

BusInfo Bus::getBusInfo() {
	return this->busInfo;
}

int Bus::getNumberRoute() {
	return this->numberOfRoute;
}

string Bus::toString() {
	
	string str = "Name of the bus driver: " + string(this->nameOfDriver)
		+ "\n" + this->busInfo.toString() +
		"Number of route: " + to_string(this->numberOfRoute);
	return str;
}

char* Bus::toCharArray() {
	const int sizeStr = 1000;
	char* str = new char[sizeStr];
	char temp[sizeStr];
	strcpy_s(str, sizeStr, "Name of the bus driver: ");
	strcpy_s(temp, MAX_LENGTH + 1, this->nameOfDriver);
	strcat_s(str, sizeStr, temp);
	strcat_s(str, sizeStr, "\n");
	strcat_s(str, sizeStr, this->busInfo.toCharArray());
	strcat_s(str, sizeStr, "\nNumber of route: ");
	_itoa_s(this->numberOfRoute, temp, 10);
	strcat_s(str, sizeStr, temp);
	return str;
}


void Bus::setName(char* name) {
	int length = strlen(name);
	if (length >= 0 && length < MAX_LENGTH) {
		strcpy_s(this->nameOfDriver, length+1, name);
	}
	else {
		throw HandleException("The name isn't valid!");
	}
}

void Bus::setBusInfo(int number, char* brand, int year, int mileage) {
	BusInfo info = BusInfo(number, brand, year, mileage);
	this->busInfo = info;
}

void Bus::setBusInfo(BusInfo info) {
	this->busInfo = info;
}

void Bus::setNumberRoute(int number) {
	Validator validator;
	if (validator.isNumberValid(number,MAX_NUMBER)) {
		this->numberOfRoute = number;
	}
	else {
		throw HandleException("The number of route isn't valid!");
	}
}