#include "BusInfo.h"
#include "Validator.h"
#include "HandleException.h"
#include <string>


BusInfo::~BusInfo(){}

BusInfo::BusInfo() {
	this->numberOfBus = 0;
	strcpy_s(this->brand,2," ");
	this->yearOfExploitation = 0;
	this->mileage = 0;
}

BusInfo::BusInfo(int number, char* brand, int year, int mileage) {
	setNumber(number);
	setBrand(brand);
	setYear(year);
	setMileage(mileage);
}

bool BusInfo::areEqual(BusInfo info) {
	int num = info.getNumber();
	if (this->getNumber() != num) {
		return false;
	}

	const char* str = info.getBrand();
	if (strcmp(this->getBrand(), str)!=0) {
		return false;
	}

	int year = info.getYear();
	if (this->getYear() != year) {
		return false;
	}

	int mileage = info.getMileage();
	if (this->getMileage() != mileage) {
		return false;
	}

	return true;
};

int BusInfo::getNumber() {
	return this->numberOfBus;
}

char* BusInfo::getBrand() {
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
		+ "\nBrand of the bus: " + string(this->brand)
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
	strcpy_s(temp, MAX_LENGTH+1,this->brand);
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
	if (validator.isNumberValid(number,MAX_NUMBER)) {
		this->numberOfBus = number;
	}
	else {
		throw HandleException("The number of bus isn't valid!");
	}
}

void BusInfo::setMileage(int mileage) {
	Validator validator;
	if (validator.isNumberValid(mileage,MAX_MILEAGE)) {
		this->mileage = mileage;
	}
	else {
		throw HandleException("The mileage isn't valid!");
	}
}

void BusInfo::setBrand(char* brand) {
	int length=strlen(brand);
	if (length >= 0 && length < MAX_LENGTH) {
		strcpy_s(this->brand, length +1, brand);
	}
	else {
		throw HandleException("The brand isn't valid!");
	}
}

void BusInfo::setYear(int year) {
	Validator validator;
	if (validator.isYearValid(year)) {
		this->yearOfExploitation=year;
	}
	else {
		throw HandleException("The year of exploitation isn't valid!");
	}
}