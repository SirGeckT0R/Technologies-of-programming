#include "HolidayList.h"

HolidayList::HolidayList(int year) {
	int* cathEasterDate = this->computeCatholicEasterDate(year);
	int catholicEasterDay = cathEasterDate[0];
	int catholicEasterMonth = cathEasterDate[1];
	int* catholicRadunitsa = this->computeRadunitsa(catholicEasterDay, catholicEasterMonth);
	int catholicRadunitsaDay = catholicRadunitsa[0];
	int catholicRadunitsaMonth = catholicRadunitsa[1];

	int* orthEasterDate = this->computeOrthodoxEasterDate(year);
	int orthodoxEasterDay = orthEasterDate[0];
	int orthodoxEasterMonth = orthEasterDate[1];
	int* orthodoxRadunitsa = this->computeRadunitsa(orthodoxEasterDay, orthodoxEasterMonth);
	int orthodoxRadunitsaDay = orthodoxRadunitsa[0];
	int orthodoxRadunitsaMonth = orthodoxRadunitsa[1];

	holidays[0] = { 1,static_cast<Month>(1),"New Year" };
	holidays[1] = { 7,static_cast<Month>(1),"Orthodox Christmas" };
	holidays[2] = { 8,static_cast<Month>(3),"8th of March" };
	holidays[3] = { 1,static_cast<Month>(5),"Labour Day" };
	holidays[4] = { 9,static_cast<Month>(5),"Victory Day" };
	holidays[5] = { 3,static_cast<Month>(7),"Independence Day" };
	holidays[6] = { 7,static_cast<Month>(11),"October Revolution Day" };
	holidays[7] = { 25,static_cast<Month>(12),"Catholic Christmas" };
	holidays[8] = { catholicEasterDay ,static_cast<Month>(catholicEasterMonth),"Catholic Easter" };
	holidays[9] = { catholicRadunitsaDay ,static_cast<Month>(catholicRadunitsaMonth),"Catholic Radunitsa" };
	holidays[10] = { orthodoxEasterDay,static_cast<Month>(orthodoxEasterMonth),"Orthodox Easter" };
	holidays[11] = { orthodoxRadunitsaDay ,static_cast<Month>(orthodoxRadunitsaMonth),"Orthodox Radunitsa" };
}

int* HolidayList::computeCatholicEasterDate(int year) {
	int easterDate[2];
	int a = year % 19;
	int b = year % 4;
	int c = year % 7;
	int d = (19 * a + 24) % 30;
	int e = (2 * b + 4 * c + 6 * d + 5) % 7;
	int f = d + e;
	if (f <= 9) {
		easterDate[0] = 22 + f;
		easterDate[1] = 3;
		return easterDate;
	}
	else {
		easterDate[0] = f - 9;
		easterDate[1] = 4;
		return easterDate;
	}
}

int* HolidayList::computeOrthodoxEasterDate(int year) {
	int easterDate[2];
	int a = year % 19;
	int b = year % 4;
	int c = year % 7;
	int d = (19 * a + 15) % 30;
	int e = (2 * b + 4 * c + 6 * d + 6) % 7;
	int f = d + e;
	if (f <= 26) {
		easterDate[0] = 4 + f;
		easterDate[1] = 4;
		return easterDate;
	}
	else {
		easterDate[0] = f-26;
		easterDate[1] = 5;
		return easterDate;
	}
}

int* HolidayList::computeRadunitsa(int EasterDay,int EasterMonth) {
	int radunitsaDate[2];
	const int LAST_MARCH_DAY = 31;
	const int LAST_APRIL_DAY = 30;
	const int LAST_MAY_DAY = 31;
	const int DAYS_AFTER_EASTER = 9;

	bool isMarchOverflown = EasterDay + 9 > LAST_MARCH_DAY && EasterMonth == 3;
	bool isAprilOverflown = EasterDay + 9 > LAST_APRIL_DAY && EasterMonth == 4;
	bool isMayOverflown = EasterDay + 9 > LAST_MAY_DAY && EasterMonth == 5;

	if (isMarchOverflown) {
		radunitsaDate[0] = EasterDay + DAYS_AFTER_EASTER - LAST_MARCH_DAY;
		radunitsaDate[1] = EasterMonth + 1;
	}
	else if (isAprilOverflown) {
		radunitsaDate[0] = EasterDay + DAYS_AFTER_EASTER - LAST_APRIL_DAY;
		radunitsaDate[1] = EasterMonth + 1;
	}
	else if (isMayOverflown) {
		radunitsaDate[0] = EasterDay + DAYS_AFTER_EASTER - LAST_MAY_DAY;
		radunitsaDate[1] = EasterMonth + 1;
	}
	else {
		radunitsaDate[0] = EasterDay + DAYS_AFTER_EASTER;
		radunitsaDate[1] = EasterMonth;
	}
	return radunitsaDate;
}


Holiday HolidayList::getHolidayByIndex(int index) {
	return holidays[index];
}


//Holiday* HolidayList(int year) {
//	int* cathEasterDate = computeCatholicEasterDate(year);
//	int catholicEasterDay = cathEasterDate[0];
//	int catholicEasterMonth = cathEasterDate[1];
//	int* catholicRadunitsa = computeRadunitsa(catholicEasterDay, catholicEasterMonth);
//	int catholicRadunitsaDay = catholicRadunitsa[0];
//	int catholicRadunitsaMonth = catholicRadunitsa[1];
//
//	int* orthEasterDate = computeOrthodoxEasterDate(year);
//	int orthodoxEasterDay = orthEasterDate[0];
//	int orthodoxEasterMonth = orthEasterDate[1];
//	int* orthodoxRadunitsa = computeRadunitsa(orthodoxEasterDay, orthodoxEasterMonth);
//	int orthodoxRadunitsaDay = orthodoxRadunitsa[0];
//	int orthodoxRadunitsaMonth = orthodoxRadunitsa[1];
//
//	Holiday buffer[12] = {{1, static_cast<Month>(1), "New Year"},
//	{ 7,static_cast<Month>(1),"Orthodox Christmas" },
//	{ 8,static_cast<Month>(3),"8th of March" },
//	{ 1,static_cast<Month>(5),"Labour Day" },
//	{ 9,static_cast<Month>(5),"Victory Day" },
//	{ 3,static_cast<Month>(7),"Independence Day" },
//	{ 7,static_cast<Month>(11),"October Revolution Day" },
//	{ 25,static_cast<Month>(1),"Catholic Christmas" },
//	{ catholicEasterDay ,static_cast<Month>(catholicEasterMonth),"Catholic Easter" },
//	{ catholicRadunitsaDay ,static_cast<Month>(catholicRadunitsaMonth),"Catholic Radunitsa" },
//	{ orthodoxEasterDay,static_cast<Month>(orthodoxEasterMonth),"Orthodox Easter" },
//	{ orthodoxRadunitsaDay ,static_cast<Month>(orthodoxRadunitsaMonth),"Orthodox Radunitsa" }
//};
//	return buffer;
//}

//
//int* computeCatholicEasterDate(int year) {
//	int easterDate[2];
//	int a = year % 19;
//	int b = year % 4;
//	int c = year % 7;
//	int d = (19 * a + 24) % 30;
//	int e = (2 * b + 4 * c + 6 * d + 5) % 7;
//	int f = d + e;
//	if (f <= 9) {
//		easterDate[0] = 22 + f;
//		easterDate[1] = 3;
//		return easterDate;
//	}
//	else {
//		easterDate[0] = f - 9;
//		easterDate[1] = 4;
//		return easterDate;
//	}
//}
//
//int* computeOrthodoxEasterDate(int year) {
//	int easterDate[2];
//	int a = year % 19;
//	int b = year % 4;
//	int c = year % 7;
//	int d = (19 * a + 15) % 30;
//	int e = (2 * b + 4 * c + 6 * d + 6) % 7;
//	int f = d + e;
//	if (f <= 26) {
//		easterDate[0] = 4 + f;
//		easterDate[1] = 4;
//		return easterDate;
//	}
//	else {
//		easterDate[0] = f - 26;
//		easterDate[1] = 5;
//		return easterDate;
//	}
//}
//
//int* computeRadunitsa(int EasterDay, int EasterMonth) {
//	int radunitsaDate[2];
//	const int LAST_MARCH_DAY = 31;
//	const int LAST_APRIL_DAY = 30;
//	const int LAST_MAY_DAY = 31;
//	const int DAYS_AFTER_EASTER = 9;
//
//	bool isMarchOverflown = EasterDay + 9 > LAST_MARCH_DAY && EasterMonth == 3;
//	bool isAprilOverflown = EasterDay + 9 > LAST_APRIL_DAY && EasterMonth == 4;
//	bool isMayOverflown = EasterDay + 9 > LAST_MAY_DAY && EasterMonth == 5;
//
//	if (isMarchOverflown) {
//		radunitsaDate[0] = EasterDay + DAYS_AFTER_EASTER - LAST_MARCH_DAY;
//		radunitsaDate[1] = EasterMonth + 1;
//	}
//	else if (isAprilOverflown) {
//		radunitsaDate[0] = EasterDay + DAYS_AFTER_EASTER - LAST_APRIL_DAY;
//		radunitsaDate[1] = EasterMonth + 1;
//	}
//	else if (isMayOverflown) {
//		radunitsaDate[0] = EasterDay + DAYS_AFTER_EASTER - LAST_MAY_DAY;
//		radunitsaDate[1] = EasterMonth + 1;
//	}
//	else {
//		radunitsaDate[0] = EasterDay + DAYS_AFTER_EASTER;
//		radunitsaDate[1] = EasterMonth;
//	}
//	return radunitsaDate;
//}
