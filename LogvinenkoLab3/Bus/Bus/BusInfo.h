#pragma once
#include <iostream>
using namespace std;


class BusInfo {
	int numberOfBus;
	string brand;
	int yearOfExploitation;
	int mileage;
public:
	BusInfo();
	BusInfo(int numberOfBus,string brand,int yearOfExploitation,int mileage);
	~BusInfo();

	int getNumber();
	string getBrand();
	int getYear();
	int getMileage();
	string toString();
	char* toCharArray();

	void setNumber(int number);
	void setBrand(string brand);
	void setYear(int year);
	void setMileage(int mileage);
};