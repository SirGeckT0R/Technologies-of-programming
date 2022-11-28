#pragma once
#include <string>
#include "./Cargo.h"

using namespace std;

class Car : public Cargo {
	int numberOfWheels;
public:
	Car();
	Car(double speed, double weight, string city, int wheels);
	~Car();
	int getNumberOfWheels();
	void setNumberOfWheels(int wheels);
	string toString();
};