#pragma once
#include "Node.h"
#include "Node.cpp"

template <typename T>
class List
{
public:
	List(T);
	List(T*, int);
	List();
	void addFirst(T);
	void addLast(T);
	void deleteFirst();
	void deleteLast();
	void findFirstOccurence(T);

	template <typename U>
	friend ostream& operator<< <>(ostream&, const List<U>&);
private:
	Node<T>* head;
};

