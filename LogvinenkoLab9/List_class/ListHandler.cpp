#include "./ListHandler.h"


void ListHandler::fillListWithRandomNumbers(List& list,int size) {
	list.deleteAll();
	for (int i = 0; i < size; i++) {
		double random = RAND_MIN_NUM + (double)(rand()) / ((double)(RAND_MAX / (RAND_MAX_NUM - RAND_MIN_NUM)));
		list.addLast(random);
	}
}

void ListHandler::fillListWithRandomNumbersNotDescending(List& list,int size) {
	list.deleteAll();
	double* randomArray = new double[size];
	for (int i = 0; i < size; i++) {
		double random = RAND_MIN_NUM + (double)(rand()) / ((double)(RAND_MAX / (RAND_MAX_NUM - RAND_MIN_NUM)));
		randomArray[i] = random;
	}
	bubbleSort(randomArray, size,true);

	for (int i = 0; i < size; i++) {
		list.addLast(randomArray[i]);
	}
	delete[] randomArray;
}