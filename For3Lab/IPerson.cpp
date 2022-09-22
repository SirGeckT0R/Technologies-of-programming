#include "IPerson.h"
#include "IDate.h"

/// �������� ����� ������ � ���������� ������ ������.
void ignoreAll(istream& is)
{
	is.clear(); // ����� ������.
	is.sync();  // ������������� ������� ������ � ������� �����������.
	is.ignore(is.rdbuf()->in_avail()); // ����� �������� ��� ��������� � ����� ������.
}

Person IPerson::inputPerson()
{
	Person person;
	
	char name[NAMELENGTH];
	char address[ADDRESSLENGTH];
	cout << "Enter name:" << endl;
	ignoreAll(cin);
	cin.getline(name, NAMELENGTH - 1);
	person.setName(name);
	cout << "Enter firstname:" << endl;
	ignoreAll(cin);
	cin.getline(name, NAMELENGTH - 1);
	person.setFirstName(name);

	cout << "Enter secondname:" << endl;
	ignoreAll(cin);
	cin.getline(name, NAMELENGTH - 1);
	person.setSecondName(name);
	cout << "Enter address:" << endl;
	cin.ignore(0, '\n');
	cin.getline(address, ADDRESSLENGTH - 1);
	person.setAddress(address);

	Date date = IDate::iConsole();
	person.setYearBirth(date);
	return person;
}

