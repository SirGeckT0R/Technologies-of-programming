#include "./ListHandler.h"


string ListHandler::toString(list<double> list) {
	string str;
	for (double& v : list)
		str +=to_string(v)+" ";

	return str;
}

void ListHandler::fillListWithRandomNumbers(list<double>& list,int size) {
	list.clear();
	for (int i = 0; i < size; i++) {
		double random = RAND_MIN_NUM + (double)(rand()) / ((double)(RAND_MAX / (RAND_MAX_NUM - RAND_MIN_NUM)));
		list.push_back(random);
	}
}

void ListHandler::fillListWithRandomNumbersNotDescending(list<double>& list,int size) {
	list.clear();
	double* randomArray = new double[size];
	for (int i = 0; i < size; i++) {
		double random = RAND_MIN_NUM + (double)(rand()) / ((double)(RAND_MAX / (RAND_MAX_NUM - RAND_MIN_NUM)));
		randomArray[i] = random;
	}
	bubbleSort(randomArray, size,true);

	for (int i = 0; i < size; i++) {
		list.push_back(randomArray[i]);
	}
	delete[] randomArray;
}

void bubbleSort(double* arr, int size, bool isAsc) {
	int i, j;
	if (isAsc) {
		for (i = 0; i < size - 1; i++)
			for (j = 0; j < size - i - 1; j++)
				if (arr[j] > arr[j + 1])
					swap(arr[j], arr[j + 1]);
	}
	else {
		for (i = 0; i < size - 1; i++)
			for (j = 0; j < size - i - 1; j++)
				if (arr[j] < arr[j + 1])
					swap(arr[j], arr[j + 1]);
	}
}