//Построить производный класс Magazin от Ite.
//Класс Magazin включает данные-члены: volume; number; year; title 
//и методы: getVolume(),  getTitle(), getNumber(), getYear(), show(), toString()
#pragma once
#include "Item.h"
class Magazin :
	public Item
{
private:
	int volume;
	int number;
	int year;
	string title;
public:
	Magazin();
	Magazin(long int invNumber, int volume,	int number,	int year, string title);
	void setYear(int year);
	~Magazin();
	int getVolume();
	string getTitle();
	int getNumber();
	int getYear();
	string toString();//Функция виртуальная, повторно ключевое слово virtual указывать не обязательно
	void show();
};

