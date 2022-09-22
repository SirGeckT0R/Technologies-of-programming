#pragma once

enum  Month
{
	JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
};
const int mohthCount = DEC - JAN + 1;
const char monthStr[mohthCount][10] = { "JANUARY", "FEBRUARY", "MARCH",
										"APRIL", "MAY", "JUNE", 
										"JULY", "AUGUST", "SEPTEMBER",
										"OCTOBER", "NOVEMBER", "DECEMBER" };
const std::string monthString [mohthCount] = { "JANUARY", "FEBRUARY", "MARCH",
											   "APRIL", "MAY", "JUNE",
                                               "JULY", "AUGUST", "SEPTEMBER",
                                               "OCTOBER", "NOVEMBER", "DECEMBER" };