#include "Parser.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int lengthOfFractionPart(long fractionPart);

int Parser::ParseIntConsole() {
	char numberInStr[256];
	char* end = 0;
	long value = 0;
	cout << endl << "Please, enter int value:";
	cin.clear();//очищаем состояние потока (делаем его работоспособным)
	cin.sync();//очищаем поток от имеющихся в нем символов.
	cin >> numberInStr;
	value=ParseIntString(numberInStr);
	return static_cast<int> (value);

}


 double Parser::ParseDoubleConsole() {
	char numberInStr[256];
	char* end = 0;
	long integerPart = 0;
	long fractionPart = 0;
	double value = 0;
	cout << endl << "Please, enter double value:";
	cin.clear();//очищаем состояние потока (делаем его работоспособным)
	cin.sync();//очищаем поток от имеющихся в нем символов.
	cin >> numberInStr;
	value = ParseDoubleString(numberInStr);
	return value;
}



 int Parser::ParseIntFile(istream& fin) {
	 char numberInStr[256];
	 char* end = 0;
	 long value = 0;
	 bool flag = true;
	 fin.getline(numberInStr, 256);

	 errno = 0;
	 value = strtol(numberInStr, &end, NUM_LEN);

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
		}
	 }
	 else
	 {
		cout << "Converted successfully: " << value << endl;//"123456789"
	 }
	 return static_cast<int> (value);

 }


 double Parser::ParseDoubleFile(istream& fin) {
	 char numberInStr[256];
	 char* end = 0;
	 long integerPart = 0;
	 long fractionPart = 0;
	 double value = 0;
	 fin.getline(numberInStr, 256);

	errno = 0;
	integerPart = strtol(numberInStr, &end, NUM_LEN);

	 if (end[0] == '.') {
		 fractionPart = strtol(++end, &end, NUM_LEN);
	 }

	 value = static_cast<double>(integerPart + fractionPart / pow(10, lengthOfFractionPart(fractionPart)));
	 if (errno != 0) {
		 cout << "Conversion error= " << errno << endl;// "12345888888888888888888888888888888888888888888888ter6789";
	 }
	 else if (*end)
	 {
		 if (end == numberInStr) {
			 cout << "Conversion error, this is not number" << endl;//"rr123456789"
		 }
		 else {
			 cout << "Converted partially: " << setprecision(NUM_LEN) << value << ", non-convertible part: " << end << endl;//"12345rr6789"
		 }
	 }
	 else
	 {
		 cout << "Converted successfully: " << setprecision(NUM_LEN) << value << endl;//"123456789"
	 }
	 
	 return value;
 }


int Parser::ParseIntString(const char* str) {
	 char* end = 0;
	 double value = 0;
	errno = 0;
	value = strtol(str, &end, NUM_LEN);
	
	if (errno != 0) {
		cout << "Conversion error= " << errno << endl;// "12345888888888888888888888888888888888888888888888ter6789";
	}
	else if (*end)
	{
		if (end == str) {
			cout << "Conversion error, this is not number" << endl;//"rr123456789"
		}
		else {
			cout << "Converted partially: " << setprecision(NUM_LEN) << value << ", non-convertible part: " << end << endl;//"12345rr6789"
		}
	}
	else
	{
		cout << "Converted successfully: " << setprecision(NUM_LEN) << value << endl;//"123456789"
	}
	 

	 return value;
 }


 double Parser::ParseDoubleString(const char* str) {
	 char* end = 0;
	 long integerPart = 0;
	 long fractionPart = 0;
	 double value = 0;
	 bool flag = true;
	 while (flag)
	 {
		 errno = 0;
		 integerPart = strtol(str, &end, NUM_LEN);

		 if (end[0] == '.') {
			 fractionPart = strtol(++end, &end, NUM_LEN);
		 }

		 value = static_cast<double>(integerPart + fractionPart / pow(10, lengthOfFractionPart(fractionPart)));

		 if (errno != 0) {
			 cout << "Conversion error= " << errno << endl;// "12345888888888888888888888888888888888888888888888ter6789";
		 }
		 else if (*end)
		 {
			 if (end == str) {
				 cout << "Conversion error, this is not number" << endl;//"rr123456789"
				 return 0;
			 }
			 else {
				 cout << "Converted partially: " << setprecision(NUM_LEN) << value << ", non-convertible part: " << end << endl;//"12345rr6789"
				 flag = false;
			 }
		 }
		 else
		 {
			 cout << "Converted successfully: " << setprecision(NUM_LEN) << value << endl;//"123456789"
			 flag = false;
		 }
	 }


	 return value;
 }


 int lengthOfFractionPart(long fractionPart) {
	 char str[NUM_LEN];
	 int length = 0;
	 _ltoa_s(fractionPart,str, NUM_LEN);
	 if (str) {
		 length = strlen(str);
	 }
	 return length;
 }