#pragma once
#include "Bus.h"

Bus* getArrayOfSameRouteBuses(Bus* buses, int size, int &newSize, int route);
Bus* getArrayOfYearBuses(Bus* buses, int size, int& newSize, int year);
Bus* getArrayOfMileageBuses(Bus* buses, int size, int& newSize, int mileage);