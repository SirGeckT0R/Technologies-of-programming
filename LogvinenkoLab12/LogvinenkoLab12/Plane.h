#pragma once
#include "./Cargo.h"
#include "./ExceptionCargo.h"
#include "./ValidatorCargo.h"
using namespace std;

class Plane : public Cargo {
	int numberOfEngines;
public:
	Plane();
	Plane(double speed, double weight, string city, double price,int engines);
	virtual ~Plane();

	int getNumberOfEngines();

	void setNumberOfEngines(int engines);

	void outputFields();
	string toString();
};