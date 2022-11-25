//��������� ����������� ����� Book �� Item.
//����� Book �� - ������ ������ - �����: author, title, publisher, year 
//� ������ : getAuthor(), getTitle(), getPublisher(), getYearOfPublishing(), show(), toString().

#pragma once
#include "Item.h"
class Book :
	public Item
{
private:
	string author; //�����
	string title;  // �������� �����
	string publisher;//������������
	int year;       //��� �������
public:
	Book();
	Book(long int invNumber, string newAuthor, string title, string publisher, int newYear);
	virtual ~Book();
	string toString();//������� �����������, �������� �������� ����� virtual ��������� �� �����������
	string getAuthor();
	string getTitle();
	string getPublisher();
	int getYear();
	void setYear(int year);
	void show();
};


