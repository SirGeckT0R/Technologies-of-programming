#include "HandlerItem.h"
#include <iostream>
using namespace std;


HandlerItem::HandlerItem()
{
}


HandlerItem::~HandlerItem()
{
}

void HandlerItem::arrayShow(Item* array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i]->show();
		cout << endl << endl;

	}

}
