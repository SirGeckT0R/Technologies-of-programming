//Создать массив объектов базового класса и заполнить объектами производных классов.

#include <iostream>
#include "Item.h"
#include "Book.h"
#include "ExeptoinPublishYear.h"
#include "Magazin.h"
#include "HandlerItem.h"

using namespace std;

int main() {
	try
	{
		Item* array[3];
		
		array[0] = new Book(2, "bautor", "btitle", "bpublisher", 2018);
		array[1] = new Magazin(5, 10, 11, 2018, "Burda");
		array[2] = new Item(123456);

		HandlerItem handler;
		handler.arrayShow(array, 3);
		cout << endl;
	}
	catch (ExeptoinPublishYear &ex)
	{
		cout << "Exception: " << ex.what() << endl;
	}
	catch (const char str[])
	{
		cout << "Exception: " << str << endl;
	}
	system("pause");
}