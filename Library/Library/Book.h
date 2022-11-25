//Построить производный класс Book от Item.
//Класс Book со - держит данные - члены: author, title, publisher, year 
//и методы : getAuthor(), getTitle(), getPublisher(), getYearOfPublishing(), show(), toString().

#pragma once
#include "Item.h"
class Book :
	public Item
{
private:
	string author; //Автор
	string title;  // Название книги
	string publisher;//Издательство
	int year;       //Год издания
public:
	Book();
	Book(long int invNumber, string newAuthor, string title, string publisher, int newYear);
	virtual ~Book();
	string toString();//Функция виртуальная, повторно ключевое слово virtual указывать не обязательно
	string getAuthor();
	string getTitle();
	string getPublisher();
	int getYear();
	void setYear(int year);
	void show();
};


