#include "Validator.h"
#include <ctime>
#include "ExeptoinPublishYear.h"
//using namespace std;

int const FIRS_YEAR_FOR_BOOK = 1450;//год издани¤ печатной библии Гуттенберга 
bool Validator::isCorrectYear(int year)
{
	struct tm newtime;
	__time64_t long_time;
	errno_t err;
	_time64(&long_time);
	// Convert to local time.
	_localtime64_s(&newtime, &long_time);
	int currentYear = newtime.tm_year + 1900;
	if ((year>currentYear) || (year<FIRS_YEAR_FOR_BOOK))
	{
		return false;

	}
	return true;
}

bool Validator::isPositive(int n)
{
	if (n>0)
	{
		return true;

	}
	return false;
}