#include "CargoHandler.h"

void CargoHandler::outputCargo(vector<Cargo*> array)
{
	for (int i = 0; i < array.size(); i++) {
		cout << endl << array[i]->toString() << endl;
	}
}

vector<double> CargoHandler::timeAndPriceOfTransferFromCity(vector<Cargo*> array, string city, double distance)
{
	vector<double> timeAndPrice;
	double time = 0;
	timeAndPrice.push_back(0);
	timeAndPrice.push_back(0);
	for (int i = 0; i < array.size(); i++) {
		if (array[i]->getOriginCity() == city) {
			time = distance / array[i]->getSpeed();
			timeAndPrice[1] += array[i]->getPrice() * time;
			timeAndPrice[0] += time;
		}
	}
	return timeAndPrice;
}

