#include "./Cargo.h"

Cargo::Cargo() : speed(0.0), maxWeight(0.0),destinationCity("") { }

Cargo::Cargo(double speed, double maxWeight,string city){
	setSpeed(speed);
	setMaxWeight(maxWeight);
	setDestinationCity(city);
}

double Cargo::getSpeed() {
	return speed;
}

double Cargo::getMaxWeight() {
	return maxWeight;
}

string Cargo::getDestinationCity()
{
	return destinationCity;
}

void Cargo::setSpeed(double newSpeed) {
	if (ValidatorCargo::isNumberValid(newSpeed)) {
		speed = newSpeed;
	}
	else throw ExceptionCargo("Speed parameter is not valid!");
}

void Cargo::setMaxWeight(double newWeight) {
	if (ValidatorCargo::isNumberValid(newWeight)) {
		maxWeight = newWeight;
	}
	else throw ExceptionCargo("Max weight parameter is not valid!");
}

void Cargo::setDestinationCity(string city)
{
	destinationCity = city;
}

string Cargo::toString() {
	string str = "Speed: " + to_string(speed) + "\nMax weight: " + to_string(maxWeight) + "\nDestination city: " + destinationCity;
	return str;
}

Cargo::~Cargo() {}

