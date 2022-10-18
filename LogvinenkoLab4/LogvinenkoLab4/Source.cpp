#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 100;
int main()
{

	time_t numb_sec; 
	struct tm timeinfo; 
	char buffer[80];


	time(&numb_sec);

	localtime_s(&timeinfo, &numb_sec); 
	
	char loc[MAX];

	do {
		cout << "Enter format, in which to present date(rus, ENG or usa): ";
		cin >> loc;
	} while (strcmp(loc, "rus")!=0 && strcmp(loc, "ENG")!=0 && strcmp(loc, "usa")!=0);

	setlocale(LC_ALL, loc);
	strftime(buffer, 80, "%c", &timeinfo);
	cout << "Date: " << buffer << endl;

	return 0;
}