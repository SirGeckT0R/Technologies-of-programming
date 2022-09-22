#pragma once
#include<string>
#include "Date.h"
using namespace std;

#define NAMELENGTH 40
#define ADDRESSLENGTH 100
#define OUTSTRLENGTH 260

class Person
{
	char name[NAMELENGTH];
	char firstName[NAMELENGTH];
	char secondName[NAMELENGTH];
	Date yearBirth;
	char address[ADDRESSLENGTH];
	
public:
	Person();
	Person(char* name, char* firstName, char* secondName, char* address, int day, int month, int year);
	~Person();
	//get
	char* getName();
	char* getFirstName();
	char* getSecondName();
	char* getAddress();
	Date getYearBirth();
	string toString();
	//set
	void setName(char* name);
	void setFirstName(char* firstName);
	void setSecondName(char* secondName);
	void setAddress(char* address);
	void setYearBirth(int day, int month, int year);
	void setYearBirth(Date date);
	void setPerson(char* name, char* firstName, char* secondName, char* address, int day, int month, int year);

	
};

