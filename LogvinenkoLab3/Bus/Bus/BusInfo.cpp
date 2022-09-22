#include "BusInfo.h"
#include "Validator.h"
#include "Exception.h"
#include <string>


BusInfo::~BusInfo(){}

BusInfo::BusInfo() {
	this->numberOfBus = 0;
	this->brand = "";
	this->yearOfExploitation = 0;
	this->mileage = 0;
}

BusInfo::BusInfo(int number, string brand, int year, int mileage) {
	setNumber(number);
	setBrand(brand);
	setYear(year);
	setMileage(mileage);
}

int BusInfo::getNumber() {
	return this->numberOfBus;
}

string BusInfo::getBrand() {
	return this->brand;
}

int BusInfo::getYear() {
	return this->yearOfExploitation;
}

int BusInfo::getMileage() {
	return this->mileage;
}

string BusInfo::toString() {
	string str = "Number of the bus: " + to_string(this->numberOfBus)
		+ "\nBrand of the bus: " + this->brand
		+"\nStart of exploitation: " + to_string(this->yearOfExploitation)
		+ "\nMileage: " + to_string(this->mileage) + "\n";
	return str;
}

char* BusInfo::toCharArray() {
	const int sizeStr = 1000;
	char* str = new char[sizeStr];
	char temp[sizeStr];
	strcpy_s(temp, sizeStr, "Number of the bus: ");
	strcpy_s(str, sizeStr, temp);
	_itoa_s(this->numberOfBus, temp, 10);
	strcat_s(str, sizeStr, temp);
	strcat_s(str, sizeStr, "\nBrand of the bus: ");
	strcpy_s(temp, MAX_LENGTH+1,this->brand.c_str());
	strcat_s(str, sizeStr, temp);
	strcat_s(str, sizeStr, "\nStart of exploitation: ");
	_itoa_s(this->yearOfExploitation, temp, 10);
	strcat_s(str, sizeStr, temp);
	strcat_s(str, sizeStr, "\nMileage: ");
	_itoa_s(this->mileage, temp, 10);
	strcat_s(str, sizeStr, temp);
	return str;
}

void BusInfo::setNumber(int number) {
	Validator validator;
	if (validator.isNumberValid(number)) {
		this->numberOfBus = number;
	}
	else {
		throw Exception("The number of bus isn't valid!");
	}
}

void BusInfo::setMileage(int mileage) {
	Validator validator;
	if (validator.isMileageValid(mileage)) {
		this->mileage = mileage;
	}
	else {
		throw Exception("The mileage isn't valid!");
	}
}

void BusInfo::setBrand(string brand) {
	if (brand.length() >= 0 && brand.length() < MAX_LENGTH) {
		this->brand = brand;
	}
	else {
		throw Exception("The brand isn't valid!");
	}
}

void BusInfo::setYear(int year) {
	Validator validator;
	if (validator.isYearValid(year)) {
		this->yearOfExploitation=year;
	}
	else {
		throw Exception("The year of exploitation isn't valid!");
	}
}