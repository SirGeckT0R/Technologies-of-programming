#include "BusArrayProcessor.h"
#include <time.h>

Bus* getArrayOfSameRouteBuses(Bus* buses,int size,int &newSize,int route) {
	Bus* arr=new Bus[size];
	newSize = 0;
	for (int i = 0; i < size; i++) {
		if (buses[i].getNumberRoute() == route) {
			arr[newSize] = buses[i];
			newSize++;
		}
	}
	return arr;
}

Bus* getArrayOfYearBuses(Bus* buses, int size, int& newSize, int year) {
	Bus* arr = new Bus[size];
	newSize = 0;
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int currentYear = newtime.tm_year + 1900; 
	for (int i = 0; i < size; i++) {
		int difference = currentYear - buses[i].getBusInfo().getYear();
		if (difference > year) {
			arr[newSize] = buses[i];
			newSize++;
		}
	}
	return arr;
}

Bus* getArrayOfMileageBuses(Bus* buses, int size, int& newSize, int mileage) {
	Bus* arr = new Bus[size];
	newSize = 0;
	for (int i = 0; i < size; i++) {
		if (buses[i].getBusInfo().getMileage()>10000) {
			arr[newSize] = buses[i];
			newSize++;
		}
	}
	return arr;
}