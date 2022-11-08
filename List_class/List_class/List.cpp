#include "List.h"

List::List(int value)
{
	Node* helper = new Node(value);
	this->head = helper;
}

List::List(int* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		this->addFirst(array[i]);
	}
}

List::List()
{
	this->head = nullptr;
}

void List::addFirst(int value)
{
	Node* current = new Node(value);
	current->next = this->head;
	this->head = current;
}

void List::addLast(int value)
{
	Node* current=this->head;
	if (this->head == nullptr) {
		addFirst(value);
	}
	else {
		while (current->next != nullptr) {
			current = current->next;
		}
		Node* temp = new Node(value);
		current->next = temp;
	}
}

void List::deleteFirst()
{
	if (this->head) {
		Node* temp = new Node();
		temp = this->head;
		this->head = this->head->next;
		delete temp;
	}
}

void List::deleteLast()
{
	Node* current = this->head;
	if (head == nullptr) {
		return;
	}
	if(head->next!=nullptr){
		while (current->next->next != nullptr) {
			current = current->next;
		}
		
		delete current->next;
		current->next = nullptr;
	}
	else {
		head = nullptr;
	}
}

void List::findAndDeleteFirstOccurence(int value) {
	Node* current = this->head;
	if (head == nullptr) {
		return;
	}

	if (current->value==value) {
		deleteFirst();
		return;
	}
	else if (current->next == nullptr) {
		return;
	}
	

	while (current->next->value!=value && current) {
		current = current->next;
	}
	if (!current) {
		return;
	}
	
	Node* temp = current->next;
	current->next = temp->next;
	delete temp;
}

ostream& operator<<(ostream& stream, const List list)
{
	Node* current = list.head;

	if (!current) {
		stream << "The list is empty..." << endl;
	}
	while (current) {
		stream << current->value  << " ";
		current = current->next;
	}

	return stream;
}
