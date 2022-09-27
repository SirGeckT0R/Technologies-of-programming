#pragma once
#include <iostream>
#include "BusInfo.h"
#include "Validator.h"
#include "HandleException.h"

using namespace std;

class Bus {
	char nameOfDriver[MAX_LENGTH];
	BusInfo busInfo;
	int numberOfRoute;
public:
	Bus();
	Bus(char* nameOfDriver, int numberOfRoute, int numberOfBus, char* brand, int yearOfExploitation, int mileage);
	Bus(char* nameOfDriver, int numberOfRoute, BusInfo busInfo);
	~Bus();

	char* getName();
	BusInfo getBusInfo();
	int getNumberRoute();
	string toString();
	char* toCharArray();

	void setName(char* name);
	void setBusInfo(int numberOfBus, char* brand, int yearOfExploitation, int mileage);
	void setBusInfo(BusInfo busInfo);
	void setNumberRoute(int number);
};