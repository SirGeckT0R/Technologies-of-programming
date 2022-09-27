#include "BusFactory.h"

Bus* createArrayOfBuses(int size) {
	Bus* busArr = new Bus[size];
	for (int i = 0; i < size; i++) {
		busArr[i] = IBus::inputBus();
	}
	return busArr;
}