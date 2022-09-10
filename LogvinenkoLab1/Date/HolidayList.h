#pragma once
#include <iostream>
#include <string>
#include "Month.h"
using namespace std;

struct Holiday {
	int day=1;
	Month month=Month::JAN;
	const char* name=new char[20];
};

const int HOLIDAY_AMOUNT = 12;

class HolidayList {
	Holiday holidays[HOLIDAY_AMOUNT];
public:
	HolidayList(int year=2022);
	Holiday getHolidayByIndex(int index);
private:
	int* computeCatholicEasterDate(int year);
	int* computeOrthodoxEasterDate(int year);
	int* computeRadunitsa(int EasterDay, int EasterMonth);
};	


//
//Holiday* HolidayList( int year);
//int* computeOrthodoxEasterDate(int year);
//int* computeCatholicEasterDate(int year);
//int* computeRadunitsa(int EasterDay, int EasterMonth);

