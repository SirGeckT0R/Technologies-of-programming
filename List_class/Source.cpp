#include <iostream>
#include "Node.h"
#include "List.h"
#include "List.cpp"

using namespace std;

int main() {
	//Node node(2);
	//cout << node << endl;

	//list.addFirst(2);
	double array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	List<double> list(array, 10);
	cout << list << endl;
	//list.deleteFirst();
	list.deleteLast();
	cout << list << endl;
	//list.addLast(67);
	//cout << list;
	//list.findFirstOccurence(1);
}