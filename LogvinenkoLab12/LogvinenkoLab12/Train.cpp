#include "Train.h"

Train::Train() : Cargo(), numberOfCarts(0)
{
}

Train::Train(double speed, double weight, string city, int carts) : Cargo(speed,weight,city)
{
	setNumberOfCarts(carts);
}

Train::~Train()
{
}

int Train::getNumberOfCarts()
{
	return numberOfCarts;
}

void Train::setNumberOfCarts(int carts)
{
	if (ValidatorCargo::isNumberOfCartsValid(carts)) {
		numberOfCarts = carts;
	}
	else throw ExceptionCargo("Number of carts in train isn't valid!");
}

string Train::toString()
{
	string str;
	str = Cargo::toString() + "\nNumber of carts: " + to_string(numberOfCarts);
	return str;
}
