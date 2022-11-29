#include <iostream>
#include "./Cargo.h"
#include "./Train.h"
#include "./Plane.h"
#include "./Car.h"
#include "./ExceptionCargo.h"
#include "./CargoHandler.h"

using namespace std;

int main() {
	try {
		Car car(1,2,"Toronto",5.5,4);

		Train train(100, 2313, "Chicago",935.12, 68);

		Plane plane(200, 1234, "Chicago",500, 2);

		vector<Cargo*> array;
		array.push_back(&car);
		array.push_back(&train);
		array.push_back(&plane);


		CargoHandler::outputCargo(array);
		
		string city = "";
		cout << "Enter the origin city, from which to start transfer: ";
		cin >> city;

		int distance = 0;
		do {
			cin.clear();
			cout << "Enter distance(positive number): ";
			cin >> distance;
		} while (distance < 0);

		vector<double> timeAndPrice = CargoHandler::timeAndPriceOfTransferFromCity(array, city, distance);
		cout << "\nTime: " << timeAndPrice[0]<<" hours" << endl << "Price: " << timeAndPrice[1] << " dollars" << endl;
	}
	catch (ExceptionCargo& e) {
		cout <<"Exception caught:"<< e.what() << endl;
	}
	return 0;
}