#include <iostream>
#include <string>
#include "Exception.h"
#include "Bus.h"
#include "IBus.h"
#include "BusInfo.h"
#include "IBusInfo.h"
#include "BusFactory.h"
#include "BusArrayProcessor.h"
using namespace std;
 
int main() {
	try {
		int size;
		do {
			cout << "Enter how many buses to create: ";
			cin >> size;
			size=checkForNumber(cin, size);
		} while (size <= 0);
		Bus* arrayOfBuses=createArrayOfBuses(size);

		int sizeOfRoute=0;
		int route = 1;
		Bus* arrayOfSameRoute = getArrayOfSameRouteBuses(arrayOfBuses, size, sizeOfRoute, route);
		cout << "\nBuses, that drive route number "<<route<<": ";
		for (int i = 0; i < sizeOfRoute; i++) {
			cout << "number " << arrayOfSameRoute[i].getBusInfo().getNumber();
			if (i == sizeOfRoute - 1) {
				cout << ".";
				break;
			}
			cout << " and ";
		}
		cout << endl;

		int sizeOfYear = 0;
		int year = 10;
		Bus* arrayOfYear = getArrayOfYearBuses(arrayOfBuses, size, sizeOfYear, year);
		cout << "\nBuses, that were in exploitation more than " << year << " years: ";
		for (int i = 0; i < sizeOfYear; i++) {
			cout << "number " << arrayOfYear[i].getBusInfo().getNumber();
			if (i == sizeOfYear - 1) {
				cout << ".";
				break;
			}
			cout << " and ";
		}
		cout << endl;

		int sizeOfMileage = 0;
		int mileage = 10000;
		Bus* arrayOfMileage = getArrayOfMileageBuses(arrayOfBuses, size, sizeOfMileage, mileage);
		cout << "\nBuses, that have driven more than " << mileage << " km: ";
		for (int i = 0; i < sizeOfMileage; i++) {
			cout << "number " << arrayOfMileage[i].getBusInfo().getNumber();
			if (i == sizeOfMileage - 1) {
				cout << ".";
				break;
			}
			cout << " and ";
		}
		cout << endl;


		delete[] arrayOfMileage;
		delete[] arrayOfYear;
		delete[] arrayOfSameRoute;
		delete[] arrayOfBuses;
	}

	catch(Exception& e)
	{
		cerr << "exception caught: " << e.what() << '\n';
	}
	system("pause");
}