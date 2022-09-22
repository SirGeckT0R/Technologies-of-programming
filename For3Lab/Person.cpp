#include "Person.h"

Person::Person() {
	strcpy_s(this->name, "not determined");
	strcpy_s(this->firstName, "not determined");
	strcpy_s(this->secondName, "not determined");
	strcpy_s(this->address, "not determined");
}

Person::Person(char* name, char* firstName, char* secondName, char* address, int day, int month, int year) {
	setPerson(name, firstName, secondName, address, day, month, year);
}

Person::~Person() {}

char* Person::getName() {
	return this->name;
}

char* Person::getFirstName() {
	return this->firstName;
}

char* Person::getSecondName() {
	return this->secondName;
}

char* Person::getAddress() {
	return this->address;
}

Date Person::getYearBirth() {
	return this->yearBirth;
}

void Person::setName(char* name) {
	strcpy_s(this->name, strlen(name)+1, name);
}

void Person::setFirstName(char* firstName) {
	strcpy_s(this->firstName, strlen(firstName) + 1, firstName);
}

void Person::setSecondName(char* secondName) {
	strcpy_s(this->secondName, strlen(secondName) + 1, secondName);
}
void Person::setAddress(char* address) {
	strcpy_s(this->address, strlen(address) + 1, address);
}
void Person::setYearBirth(int day, int month, int year) {

	this->yearBirth.setDate(day, month, year);
}

void Person::setYearBirth(Date date) {
	this->yearBirth = date;
}

void Person::setPerson(char* name, char* firstName, char* secondName, char* address, int day, int month, int year) {
	setName(name);
	setFirstName(firstName);
	setSecondName(secondName);	
	setAddress(address);
	setYearBirth(day, month, year);
}

std::string Person::toString()
{
	std::string str = "FIO: ";
	str = str +  this->name + " " + this->firstName + " " + this->secondName + "\nyearBirth: " + yearBirth.toString() + "\naddress: " + this->address;
	return str;
}







