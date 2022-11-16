#pragma once
#include "./List.h"
class ListHandler {
public:
	static void fillListWithRandomNumbers(List& list,int size);
	static void fillListWithRandomNumbersNotDescending(List& list,int size);
};