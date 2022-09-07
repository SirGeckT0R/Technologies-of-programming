#pragma once
#include <iostream>
#include <string>
#include "Month.h"
using namespace std;

struct Holiday {
	int day;
	Month month;
	string name = "";
};


const int HOLIDAY_AMOUNT = 12;

class HolidayList {
	Holiday holidayList[HOLIDAY_AMOUNT];
public:
	HolidayList(int year);
	int* computeCatholicEasterDate(int year);
	int* computeOrthodoxEasterDate(int year);
	int* computeRadunitsa(int EasterDay, int EasterMonth);
};	