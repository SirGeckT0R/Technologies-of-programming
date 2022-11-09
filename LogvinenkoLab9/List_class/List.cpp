#include "List.h"

List::List(double value)
{
	Node* helper = new Node(value);
	head = helper;
}

List::List(double* array, int length)
{
	head = nullptr;
	for (int i = 0; i < length; i++)
	{
		addLast(array[i]);
	}
}

List::List(vector<double> listVect) {
	head = nullptr;
	for (int i = 0; i < listVect.size(); i++)
	{
		addLast(listVect.at(i));
	}
}

List::List(const List& list) {
	if (list.head) {
		Node* inputList=list.head;
		head = new Node(list.head->value);
		while (inputList = inputList->next) {
			addLast(inputList->value);
		}

	}
	else {
		head = list.head;
	}
}

List::List()
{
	head = nullptr;
}

List::~List()
{
	deleteAll();
}


vector<double> List::getList() {
	vector<double> listArr;
	Node* current = head;
	while (current) {
		listArr.push_back(current->value);
		if (current->next == nullptr) {
			break;
		}
		current = current->next;
	}
	return listArr;
}

void List::reverseList() {
	if(head==nullptr){
		return;
	}

	Node* current = head;
	Node* prev,*next;
	prev = next = nullptr;

	while (current) {
		next = current->next;
		current->next = prev;

		prev = current;
		current = next;
	}
	head = prev;

	
	
}

void List::addFirst(double value)
{
	Node* current = new Node(value);
	current->next = head;
	head = current;
}

void List::addLast(double value)
{
	Node* current=head;
	if (head == nullptr) {
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
	if (head) {
		Node* temp = new Node();
		temp = head;
		head = head->next;
		delete temp;
	}
}

void List::deleteLast()
{
	Node* current = head;
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
void List::deleteAll() {
	while (head!=nullptr) {
		deleteFirst();
	}
}

void List::findAndDeleteFirstOccurence(double value) {
	if (head == nullptr) {
		return;
	}

	Node* current = head;
	if (current->value == value) {
		deleteFirst();
		return;
	}
	if (current->next == nullptr) {
		return;
	}

	while (current->next && current->next->value != value) {
			current = current->next;
		}
	if (current->next == nullptr) {
		return;
	}

	Node* temp = current->next;
	current->next = temp->next;
	delete temp;
}

string List::toString() const {
	string str;
	Node* current = head;
	if (!current) {
		str = "This list is empty...";
	}
	while (current) {
		str += " "+to_string(current->value);
		current = current->next;
	}
	return str;
}

List List::operator=(const List& list) {
	if (&list == this) return *this;
	deleteAll();
	rewriteList(list);
	return List(list);
}

void List::rewriteList(const List list) {
	if (list.head) {
		Node* current = list.head;
		this->head = new Node(list.head->value);
		while (current = current->next) {
			addLast(current->value);
		}
	}
	else {
		head = list.head;
	}
}

ostream& operator<<(ostream& stream, const List& list)
{
	stream << list.toString() << endl;

	return stream;
}


void bubbleSort(double* arr, int size,bool isAsc) {
	int i, j;
	if (isAsc) {
		for (i = 0; i < size - 1; i++)
			for (j = 0; j < size - i - 1; j++)
				if (arr[j] > arr[j + 1])
					swap(arr[j], arr[j + 1]);
	}
	else {
			for (i = 0; i < size - 1; i++)
				for (j = 0; j < size - i - 1; j++)
					if (arr[j] < arr[j + 1])
						swap(arr[j], arr[j + 1]);
	}
}