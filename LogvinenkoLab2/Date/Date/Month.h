
#include <string>

#ifndef MONTH_H
#define MONTH_H

enum class Month {
	JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
};

const int MONTHCOUNT = static_cast<int>(Month::DEC) - static_cast<int>(Month::JAN) + 1;

const char MONTHSTR[MONTHCOUNT][10] = { "january", "february", "march",
										"april", "may", "june",
										"july", "august", "september",
										"october", "november", "december"
};

const std::string MONTHSTRING[MONTHCOUNT] = { "january", "february", "march",
												"april", "may", "june",
												"july", "august", "september",
												"october", "november", "december"
};

#endif // !MONTH_H

