#include "./Cargo.h"

Cargo::Cargo() : speed(0.0), maxWeight(0.0),originCity(""),price(0) { }

Cargo::Cargo(double speed, double maxWeight,string city,double price){
	setSpeed(speed);
	setMaxWeight(maxWeight);
	setOriginCity(city);
	setPrice(price);
}

double Cargo::getSpeed() {
	return speed;
}

double Cargo::getPrice()
{
	return price;
}

double Cargo::getMaxWeight() {
	return maxWeight;
}

string Cargo::getOriginCity()
{
	return originCity;
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

void Cargo::setOriginCity(string city)
{
	originCity = city;
}

void Cargo::setPrice(double priceNew)
{
	if (ValidatorCargo::isPriceValid(priceNew)) {
		price = priceNew;
	}
	else throw ExceptionCargo("Price parameter is not valid!");
}

string Cargo::toString() {
	string str = "Speed: " + to_string(speed) + "\nMax weight: " + to_string(maxWeight) + "\nOrigin city: " + originCity + "\nPrice for one hour: " + to_string(price);
	return str;
}

Cargo::~Cargo() {}

