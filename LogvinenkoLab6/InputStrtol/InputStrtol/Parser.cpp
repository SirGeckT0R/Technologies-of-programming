#include "Parser.h"
#include <iostream>
using namespace std;

int Parser::ParseInt() {
	char numberInStr[256];
	char* end = 0;
	long value = 0;
	bool flag = true;
	while (flag)
	{
		cout << endl << "Please, enter int value:";
		cin.clear();//очищаем состояние потока (делаем его работоспособным)
		cin.sync();//очищаем поток от имеющихся в нем символов.
		cin >> numberInStr;
		errno = 0;
		value = strtol(numberInStr, &end, 10);

		if (errno != 0) {
			cout << "Conversion error= " << errno << endl;// "12345888888888888888888888888888888888888888888888ter6789";
		}
		else if (*end)
		{
			if (end == numberInStr) {
				cout << "Conversion error, this is not number" << endl;//"rr123456789"
			}
			else {
				cout << "Converted partially: " << value << ", non-convertible part: " << end << endl;//"12345rr6789"
				flag = false;
			}
		}
		else
		{
			cout << "Converted successfully: " << value << endl;//"123456789"
			flag = false;
		}
	}
	return static_cast<int> (value);

}

