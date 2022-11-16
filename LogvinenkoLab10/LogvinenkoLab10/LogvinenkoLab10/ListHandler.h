#pragma once
#include <list>
#include <string>
using namespace std;


#define RAND_MAX_NUM 1000
#define RAND_MIN_NUM -1000
class ListHandler {
public:
	static string toString(list<double> list);
	static void fillListWithRandomNumbers(list<double>& list,int size);
	static void fillListWithRandomNumbersNotDescending(list<double>& list,int size);
};

void bubbleSort(double* arr, int size, bool isAsc);