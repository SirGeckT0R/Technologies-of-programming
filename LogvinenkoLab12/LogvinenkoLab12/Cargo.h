#pragma once
#include <string>
#include "./ValidatorCargo.h"
#include "./ExceptionCargo.h"
using namespace std;

class Cargo {
protected:
	double speed;
	double maxWeight;
	string destinationCity;
public:
	Cargo();
	Cargo(double speed, double maxWeight,string city);
	virtual ~Cargo();
	double getMaxWeight();
	string getDestinationCity();
	double getSpeed();
	void setSpeed(double speed);
	void setMaxWeight(double maxWeight);
	void setDestinationCity(string city);

	virtual string toString();
};