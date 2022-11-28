#include <iostream>
#include "./Cargo.h"
#include "./Train.h"
#include "./Plane.h"
#include "./Car.h"
#include "./ExceptionCargo.h"

using namespace std;

int main() {
	try {
		Car car(1,2,"Toronto",4);

		Train train(11242, 2313, "Chicago", 68);

		Plane plane(20000, 1234, "New York", 2);

		const int size = 3;
		Cargo** array=new Cargo*[size];
		array[0] = &car;
		array[1] = &train;
		array[2] = &plane;

		for (int i = 0; i < size; i++) {
			cout << endl << array[i]->toString() << endl;
		}
	}
	catch (ExceptionCargo& e) {
		cout <<"Exception caught:"<< e.what() << endl;
	}
	return 0;
}