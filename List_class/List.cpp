#include "List.h"

template <typename T>
List<T>::List(T value)
{
	Node<T>* helper = new Node<T>(value);
	this->head = helper;
}

template <typename T>
List<T>::List(T* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		this->addFirst(array[i]);
	}
}

template <typename T>
List<T>::List()
{
	this->head = nullptr;
}

template <typename T>
void List<T>::addFirst(T value)
{
	Node<T>* current = new Node<T>(value);
	current->next = this->head;
	this->head = current;
}

template <typename T>
void List<T>::addLast(T value)
{
	Node<T>* current=this->head;
	if (this->head == nullptr) {
		addFirst(value);
	}
	else {
		while (current->next != nullptr) {
			current = current->next;
		}
		Node<T>* temp = new Node<T>(value);
		current->next = temp;
	}
}

template <typename T>
void List<T>::deleteFirst()
{
	if (head != nullptr)
	{
		Node<T>* tmp;
		tmp = head;
		head = head->next;
		delete tmp;
	}
}

template <typename T>
void List<T>::deleteLast()
{
	if (head == nullptr)
	{
		return;
	}

	if (head->next == nullptr)
	{
		deleteFirst();
		return;
	}
	else
	{
		Node<T>* curr = head;
		while (curr->next->next)
		{
			curr = curr->next;
		}
		delete curr->next;
		curr->next = nullptr;
	}
}

template <typename T>
void List<T>::findFirstOccurence(T value)
{
	Node<T>* current = this->head;
	if (head == nullptr)
	{
		return;
	}
	if (current->next == nullptr)
	{
		if (current->value == value)
		{
			deleteFirst();
			return;
		}
		else
		{
			return;
		}
	}
	while (current->next->value != value && current)
	{
		current = current->next;
	}
	if (!current)
	{
		return;
	}
	Node<T>* temp = current->next;
	current->next = temp->next;
	delete temp;
}

template <typename U>
ostream& operator<<(ostream& stream, const List<U>& list)
{
	Node<U>* current = list.head;

	if (!current) {
		stream << "The list is empty..." << endl;
	}
	while (current) {
		stream << current->value  << " ";
		current = current->next;
	}

	return stream;
}
