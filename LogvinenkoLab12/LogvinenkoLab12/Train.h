#pragma once
#include <string>
#include "./Cargo.h"
#include "./ValidatorCargo.h"
#include "./ExceptionCargo.h"

class Train : public Cargo {
	int numberOfCarts;
public:
	Train();
	Train(double speed, double weight, string city,double price, int carts);
	virtual ~Train();

	int getNumberOfCarts();

	void setNumberOfCarts(int carts);

	void outputFields();
	string toString();
};