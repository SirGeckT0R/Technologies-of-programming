#include "Node.h"

Node::Node(): value(0), next(nullptr) {}

Node::Node(int value_): value(value_), next(nullptr) {}

Node::~Node() {}

ostream& operator<<(ostream& stream, const Node node) {
	stream << node.value << " ";
	return stream;
}

