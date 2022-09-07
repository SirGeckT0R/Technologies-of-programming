#pragma once
#include<iostream>
#include <string>
#include "Month.h"
class Date
{
	int day;
	Month month;
	int year;
public:
	Date();//конструктор по умолчанию
	Date(int day, int month, int year);
	~Date();

	void setMonth(int month);
	void setYear(int year);
	void setDate(int day, int month, int year);

	int getDay();
	Month getMonth();
	int getYear();
	
	char* toCharArray();
	std::string toString();
};

