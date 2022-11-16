#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
	T value;
	Node<T>* next;
	Node();
	Node(T);
	~Node();

	template <typename U>
	friend ostream& operator<<(ostream&, const Node<U>);
};

