#include <list>
#include <iostream>
#include <conio.h>
#include "./ListHandler.h"
#include "./ListIOHelper.h"

using namespace std;

int main() {
	srand(time(NULL));
	list<double> list;

	bool fromFile = false;
	cout << "Do you want to enter your list from file or fill it with random numbers?(enter f or r)";
	if (_getche() == 'f') {
		fromFile = true;
	}

	string filename;
	int size = 0;
	if (fromFile) {
		cout << "\nEnter filename(example: list.txt): ";
		cin >> filename;
		list = ListIOHelper::listFromFile(filename);
	}
	else {
		cout << "\nEnter size of a list: ";
		cin >> size;
		ListHandler::fillListWithRandomNumbersNotDescending(list, size);
	}
	cout << "\nOriginal list: " << ListHandler::toString(list) << endl;

	list.reverse();
	cout << "Reversed list: " << ListHandler::toString(list) << endl;


	cout << "\nEnter file, to where you want to write list(example: output.txt): ";
	cin >> filename;
	ListIOHelper::listToFile(filename, list);
	
	return 0;
}