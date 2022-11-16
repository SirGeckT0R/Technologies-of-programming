#include "Node.h"

template <typename T>
Node<T>::Node(): value(0), next(nullptr) {}

template <typename T>
Node<T>::Node(T value_): value(value_), next(nullptr) {}

template <typename T>
Node<T>::~Node() {}

template <typename T>
ostream& operator<<(ostream& stream, const Node<T> node) {
	stream << node.value << " ";
	return stream;
}

