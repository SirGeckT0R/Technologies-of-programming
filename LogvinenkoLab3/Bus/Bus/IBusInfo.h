#pragma once
#include "BusInfo.h"

class IBusInfo {
public:
	static BusInfo inputBusInfo();
};

void ignoreAll(istream& is);
int checkForNumber(istream& cin, int temp);