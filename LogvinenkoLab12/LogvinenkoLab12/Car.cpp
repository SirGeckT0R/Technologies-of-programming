#include "Car.h"

Car::Car(): Cargo(),numberOfWheels(0)
{
}

Car::Car(double speed, double weight, string city,double price, int wheels) : Cargo(speed,weight,city,price)
{
	setNumberOfWheels(wheels);
}

Car::~Car()
{
}

int Car::getNumberOfWheels()
{
	return numberOfWheels;
}



void Car::setNumberOfWheels(int wheels)
{
	if (ValidatorCargo::isNumberOfWheelsValid(wheels)) {
		numberOfWheels = wheels;
	}
	else throw ExceptionCargo("Number of wheels in the car isn't valid!");
}

string Car::toString()
{
	string str;
	str=Cargo::toString() + "\nNumber of wheels: " + to_string(numberOfWheels);
	return str;
}
