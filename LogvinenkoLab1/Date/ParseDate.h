#pragma once
#include <string>
#include "Date.h"
#include "Date.h"
using namespace std;

void parseStringInDate(char* inputString,Date &startDate);
char* findCharachterAfterWhitespace(char* string);
void checkDates(Date &startDate, Date& endDate);