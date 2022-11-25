#include <iostream>
#include "./Cargo.h"
#include "./ExceptionCargo.h"

using namespace std;

int main() {
	try {
		Cargo cargo;
		cout << cargo.toString() << endl;
	}
	catch (ExceptionCargo& e) {
		cout <<"Exception caught:"<< e.what() << endl;
	}
	return 0;
}