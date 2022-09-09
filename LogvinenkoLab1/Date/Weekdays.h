#pragma once
#include <string>

enum class Weekdays {
	MON = 1, TUE, WED, THU, FRI, SAT, SUN
};


const int WEEKDAYSCOUNT = static_cast<int>(Weekdays::SUN) - static_cast<int>(Weekdays::MON) + 1;

const char WEEKDAYSTR[WEEKDAYSCOUNT][10] = { "monday", "tuesday",
										"wednesday","thursday","friday",
										"saturday","sunday"
};

const std::string WEEKDAYSTRING[WEEKDAYSCOUNT] = { "monday", "tuesday",
										"wednesday","thursday","friday",
										"saturday","sunday"
};