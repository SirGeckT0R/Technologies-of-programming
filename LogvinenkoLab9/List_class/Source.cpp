#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "Node.h"
#include "List.h"
#include "ListIOHelper.h"
#include "./ListHandler.h"

using namespace std;

int main() {
	srand(time(NULL));
	List list;
	bool fromFile=false;
	bool fromConsole = false;
	cout << "Do you want to enter your list from file, from console or fill it with random numbers?(enter f,c or r)";
	char input = _getche();
	if (input == 'f') {
		fromFile = true;
	}
	else if (input == 'c') {
		fromConsole = true;
	}
	string filename;
	int size = 0;
	if (fromConsole) {
		cout << "\nEnter the size of a list:";
		cin >> size;
		list = ListIOHelper::listFromConsole(size);
	} else if (fromFile) {
		cout << "\nEnter filename(example: list.txt): ";
		cin >> filename;
		list = ListIOHelper::listFromFile(filename);
	}
	else {
		cout << "\nEnter size of a list: ";
		cin >> size;
		ListHandler::fillListWithRandomNumbersNotDescending(list, size);
	}
	cout << "\nOriginal list: "<<list << endl;

	List list2 = list;
	list2.reverseList();
	cout << "Reversed list: " << list2 << endl;


	cout << "\nEnter file, to where you want to write list(example: output.txt): ";
	cin >> filename;
	ListIOHelper::listToFile(filename,list2);
}