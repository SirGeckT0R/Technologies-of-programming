#pragma once
#include<iostream>
#include <string>
#include "Month.h"
class Date
{
	int day=11;
	Month month= SEP;
	int year=2000;
public:
	Date();//конструктор по умолчанию
	Date(int day, int month, int year);
	~Date();

	void setMonth(int month);
	void setYear(int year);
	void setDate(int day, int month, int year);
	
	int getDay();
	int getMonth();
	int getYear();
	
	char* toCharArray();
	std::string toString();
};

