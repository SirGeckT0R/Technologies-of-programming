#include <iostream>
#include "Node.h"
#include "List.h"

using namespace std;

int main() {
	//Node node(2);
	//cout << node << endl;

	//list.addFirst(2);
	int array[1] = {1};
	List list(array,1);
	

	cout << list << endl;
	list.findAndDeleteFirstOccurence(1);
	cout << list;
}