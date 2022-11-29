#pragma once
#include <string>
#include "./ValidatorCargo.h"
#include "./ExceptionCargo.h"
using namespace std;

class Cargo {
protected:
	double speed; //kilometers per hour
	double maxWeight;
	string originCity;
	double price; 
public:
	Cargo();
	Cargo(double speed, double maxWeight,string city,double price);
	virtual ~Cargo();
	double getMaxWeight();
	string getOriginCity();
	double getSpeed();
	double getPrice();
	void setSpeed(double speed);
	void setMaxWeight(double maxWeight);
	void setOriginCity(string city);
	void setPrice(double price);

	virtual string toString();
};