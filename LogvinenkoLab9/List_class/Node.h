#pragma once
#include <iostream>

using namespace std;

class Node
{
public:
	double value;
	Node* next;
	Node();
	Node(double);
	~Node();
	friend ostream& operator<<(ostream&, const Node);
};

