#include "Item.h"
#include <sstream>//��� ���� ostringstream � bool_cast
#include<iostream>
using namespace std;

Item::Item():invNumber(0)
{
}

Item::Item(long int invNumber):taken(false)
{
	this->invNumber = invNumber;
}

Item::~Item()
{
}

string Item::bool_cast(const bool b) 
{
	ostringstream ss;
	ss << boolalpha << b;
	return ss.str();
}

string Item::toString() {
	string result("invNumber: ");
	//������� ������������� ����������� ������� std::to_string, 
	//������� ����� ������������ ��� �������������� ������������� ��������
	//(� �������� � ��������� ������) � ������.
	result += std::to_string(invNumber) + "\ntaken: " + bool_cast(taken);
	return result;
}

void Item::show()
{
	cout << "Item: " << endl
		<< toString();
}

bool Item::isAvailable()
{
	return !taken;
}

int Item::getInvNumber()
{ 
	return invNumber;
}

void Item::take()
{
	taken = true;
}

void Item::returnItem()
{ 
	taken = false; 
}


