#pragma once
#include <iostream>

using namespace std;

class Node
{
public:
	int value;
	Node* next;
	Node();
	Node(int);
	~Node();
	friend ostream& operator<<(ostream&, const Node);
};

