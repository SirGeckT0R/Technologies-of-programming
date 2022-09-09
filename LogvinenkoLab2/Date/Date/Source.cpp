#include <iostream>
#include "Date.h"
#include "ExceptionDate.h"

using namespace std;
 
int main() {
	try {
		Date date;
				
		cout << date.toCharArray() << endl;
		cout << date.toString() << endl;
	}
	catch(ExceptionDate& e)
	{
		cerr << "exception caught: " << e.what() << '\n';
	}
	system("pause");
}