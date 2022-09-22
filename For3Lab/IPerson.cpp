#include "IPerson.h"
#include "IDate.h"

/// Сбросить флаги ошибок и содержимое буфера потока.
void ignoreAll(istream& is)
{
	is.clear(); // Сброс ошибок.
	is.sync();  // Синхронизация объекта потока с внешним устройством.
	is.ignore(is.rdbuf()->in_avail()); // Сброс символов уже считанных в буфер потока.
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

