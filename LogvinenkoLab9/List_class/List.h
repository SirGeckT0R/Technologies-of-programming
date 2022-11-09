#pragma once
#include "Node.h"
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define RAND_MAX_NUM 1000
#define RAND_MIN_NUM -1000

class List
{
public:
	List(double);
	List(double*, int);
	List(vector<double>);
	List(const List& list);
	List();
	~List();
	vector<double> getList();
	void reverseList();
	void rewriteList(const List list);
	void addFirst(double);
	void addLast(double);
	void deleteFirst();
	void deleteLast();
	void deleteAll();
	void findAndDeleteFirstOccurence(double);
	string toString() const;
	List operator=(const List& list);
	friend ostream& operator<<(ostream& stream, const List& list);
private:
	Node* head;
};

void bubbleSort(double* arr, int size, bool isAsc);