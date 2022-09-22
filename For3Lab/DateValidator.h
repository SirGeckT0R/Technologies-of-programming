#pragma once

class DateValidator
{
public:
	bool isYearValid(int year);
	bool isMonthValid(int year);
	bool isLeap(int year);
	bool isDayValid(int day, int month, int year);
	bool isNumberValid(int number);
	bool isCourse(int course);
	bool isGroup(int group);
	bool isAverageBall(double b);
};

