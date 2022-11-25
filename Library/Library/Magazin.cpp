#include "Magazin.h"
#include "Validator.h"
#include "ExeptoinPublishYear.h"
#include<iostream>

using namespace std;

Magazin::Magazin()
{
}


Magazin::~Magazin()
{
}

void Magazin::setYear(int year)
{
	Validator v;
	if (v.isCorrectYear(year))
	{
		this->year = year;
	}
	else
	{
		throw ExeptoinPublishYear("The year of publishing of Magazin is wrong!!!");
	}
}

Magazin::Magazin(long int invNumber, int volume, int number, int year, string title) :Item(invNumber)
{
	Validator v;
	if (v.isPositive(volume))
	{
		this->volume = volume;
	}
	else throw "volume is wrong!!!";

	if (v.isPositive(number))
	{
		this->number = number;
	}
	else throw "number is wrong!!!";

	if (v.isCorrectYear(year))
	{
		this->year = year;
	}
	else throw ExeptoinPublishYear("The year of publishing of Book is wrong!!!");
	this->title = title;
}

int Magazin::getVolume()
{
	return volume;
}

string Magazin::getTitle()
{
	return title;
}

int Magazin::getNumber()
{
	return number;
}

int Magazin::getYear()
{
	return year;
}

string Magazin::toString()
{
	string result = Item::toString();
	result += "\nvolume: " + std::to_string(volume)
		+ "\nnumber: " + std::to_string(number)
		+ "\nyear: " + std::to_string(year)
	    + "\ntitle: " + title;
	return result;
}

void Magazin::show()
{
	cout << "Magazin: " << endl
		<< toString();//toString берется от Book, поскольку toString виртуальная функция
}


