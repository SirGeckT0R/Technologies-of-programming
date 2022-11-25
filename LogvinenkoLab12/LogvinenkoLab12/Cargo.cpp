#include "./Cargo.h"

Cargo::Cargo() : speed(0.0), maxWeight(0.0) { }

Cargo::Cargo(double speed, double maxWeight){
	setSpeed(speed);
	setMaxWeight(maxWeight);
}

double Cargo::getSpeed() {
	return speed;
}

double Cargo::getMaxWeight() {
	return maxWeight;
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

string Cargo::toString() const {
	string str = "Speed: " + to_string(speed) + "\nMax weight: " + to_string(maxWeight);
	return str;
}

Cargo::~Cargo() {}

