#include "Item.h"
#include <sstream>//для типа ostringstream в bool_cast
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
	//Имеется перегруженная стандартная функция std::to_string, 
	//которую можно использовать для преобразования целочисленных значений
	//(и значений с плавающей точкой) в строку.
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


