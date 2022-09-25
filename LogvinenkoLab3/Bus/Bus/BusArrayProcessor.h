#pragma once
#include "Bus.h"

Bus* getArrayOfSameRouteBuses(Bus* buses, int size, int &newSize, int route);
Bus* getArrayOfYear(Bus* buses, int size, int& newSize, int year);
Bus* getArrayOfMileage(Bus* buses, int size, int& newSize, int mileage);