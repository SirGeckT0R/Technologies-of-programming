#pragma once
#include <iostream>
#include "Validator.h"
using namespace std;


class BusInfo {
	int numberOfBus;
	char brand[MAX_LENGTH];
	int yearOfExploitation;
	int mileage;
public:
	BusInfo();
	BusInfo(int numberOfBus,char* brand,int yearOfExploitation,int mileage);
	~BusInfo();

	bool areEqual(BusInfo info);

	int getNumber();
	char* getBrand();
	int getYear();
	int getMileage();
	string toString();
	char* toCharArray();

	void setNumber(int number);
	void setBrand(char* brand);
	void setYear(int year);
	void setMileage(int mileage);
};