#pragma once
#include <iostream>
#include <string>
#include "Month.h"
using namespace std;



const int HOLIDAY_AMOUNT = 12;
const int MAX_NAME_LENGTH = 51;

struct Holiday {
	int day=1;
	Month month=Month::JAN;
	string name;
};

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

