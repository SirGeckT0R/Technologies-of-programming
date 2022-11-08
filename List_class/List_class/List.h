#pragma once
#include "Node.h"

class List
{
public:
	List(int);
	List(int*, int);
	List();
	void addFirst(int);
	void addLast(int);
	void deleteFirst();
	void deleteLast();
	void findAndDeleteFirstOccurence(int);
	friend ostream& operator<<(ostream&, const List);
private:
	Node* head;
};

