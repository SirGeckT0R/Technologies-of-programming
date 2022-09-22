#pragma once
#include <iostream>
#include "BusInfo.h"
#include "Validator.h"
#include "Exception.h"

using namespace std;

class Bus {
	string nameOfDriver;
	BusInfo busInfo;
	int numberOfRoute;
public:
	Bus();
	Bus(string nameOfDriver, int numberOfRoute, int numberOfBus, string brand, int yearOfExploitation, int mileage);
	Bus(string nameOfDriver, int numberOfRoute, BusInfo busInfo);
	~Bus();

	string getName();
	BusInfo getBusInfo();
	int getNumberRoute();
	string toString();
	char* toCharArray();

	void setName(string name);
	void setBusInfo(int numberOfBus, string brand, int yearOfExploitation, int mileage);
	void setBusInfo(BusInfo busInfo);
	void setNumberRoute(int number);
};