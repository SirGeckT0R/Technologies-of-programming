#pragma once
#include <iostream>
#include <vector>
#include "./Cargo.h"
using namespace std;

class CargoHandler {
public:
	static void outputCargo(vector<Cargo*> array);
	static vector<double> timeAndPriceOfTransferFromCity(vector<Cargo*> array, string city, double distance);
};