//��������� ����������� ����� Magazin �� Ite.
//����� Magazin �������� ������-�����: volume; number; year; title 
//� ������: getVolume(),  getTitle(), getNumber(), getYear(), show(), toString()
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
	string toString();//������� �����������, �������� �������� ����� virtual ��������� �� �����������
	void show();
};

