#include "Plane.h"

Plane::Plane():Cargo(),numberOfEngines(0)
{
}

Plane::Plane(double speed, double weight, string city, int engines) :Cargo(speed,weight,city)
{
	setNumberOfEngines(engines);
}

Plane::~Plane()
{
}

int Plane::getNumberOfEngines()
{
	return numberOfEngines;
}

void Plane::setNumberOfEngines(int engines)
{
	if (ValidatorCargo::isNumberOfEnginesValid(engines)) {
		numberOfEngines = engines;
	}
	else throw ExceptionCargo("Number of engines on the plane isn't valid!");
}

string Plane::toString()
{
	string str;
	str = Cargo::toString() + "\nNumber of engines: " + to_string(numberOfEngines);
	return str;
}
