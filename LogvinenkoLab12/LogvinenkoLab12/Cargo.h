#pragma once
#include "./ValidatorCargo.h"
#include "./ExceptionCargo.h"

class Cargo {
	double speed;
	double maxWeight;
public:
	Cargo();
	Cargo(double speed, double maxWeight);
	virtual ~Cargo();
	double getMaxWeight();
	double getSpeed();
	void setSpeed(double speed);
	void setMaxWeight(double maxWeight);

	virtual string toString() const;
};