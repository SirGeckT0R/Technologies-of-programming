#pragma once
#include <string>

enum class Weekdays {
	SAT = 1, SUN, MON, TUE, WED, THU, FRI
};	


const int WEEKDAYSCOUNT = static_cast<int>(Weekdays::FRI) - static_cast<int>(Weekdays::SAT) + 1;

const char WEEKDAYSTR[WEEKDAYSCOUNT][10] = {
										"saturday","sunday","monday", "tuesday",
										"wednesday","thursday","friday"
};

const std::string WEEKDAYSTRING[WEEKDAYSCOUNT] = { "saturday","sunday","monday", "tuesday",
										"wednesday","thursday","friday"
};