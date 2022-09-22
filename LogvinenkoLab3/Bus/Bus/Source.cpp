#include <iostream>
#include "Date.h"
#include "Exception.h"
#include <string>
#include "Bus.h"
#include "BusInfo.h"
using namespace std;
 
int main() {
	try {
	}

	catch(Exception& e)
	{
		cerr << "exception caught: " << e.what() << '\n';
	}
	system("pause");
}