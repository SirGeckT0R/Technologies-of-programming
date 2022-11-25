#include "Book.h"
#include<iostream>
#include "Validator.h"
#include "ExeptoinPublishYear.h"

using namespace std;


Book::Book()
{
}

Book::Book(long int invNumber, string author, string title, string publisher, int year):Item(invNumber)
{
	this->author = author;
	this->title = title;
	this->publisher = publisher;
	setYear(year);
}

Book::~Book()
{
}

string Book::toString()
{
	string result = Item::toString();
	result += "\nauthor: " + author 
		+ "\ntitle: " + title +
		"\npublisher: " + publisher 
		+ "\nyear: " + std::to_string(year);
	return result;
}

string Book::getAuthor()
{
	return author;
}

string Book::getTitle()
{ 
	return title;
}

string Book::getPublisher()
{
	return publisher;
}

int Book::getYear()
{
	return year;
}

void Book::show()
{
	cout << "Book: " << endl
		<< toString();//toString берется от Book, поскольку toString виртуальная функция
}

void Book::setYear(int year)
{
	Validator v;
	if (v.isCorrectYear(year))
	{
		this->year = year;
	}	
	else
	{
		throw ExeptoinPublishYear("The year of publishing of Book is wrong!!!");
	}
}

