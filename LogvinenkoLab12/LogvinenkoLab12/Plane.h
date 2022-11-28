#pragma once
#include "./Cargo.h"
#include "./ExceptionCargo.h"
#include "./ValidatorCargo.h"
using namespace std;

class Plane : public Cargo {
	int numberOfEngines;
public:
	Plane();
	Plane(double speed, double weight, string city, int engines);
	~Plane();

	int getNumberOfEngines();

	void setNumberOfEngines(int engines);

	string toString();
};