#include <iostream>
#include "Date.h"
#include "ExceptionDate.h"
#include "IDate.h"
#include "Person.h"
#include "IPerson.h"
#include "Student.h"
#include "IStudent.h"
#include "StudentFactory.h"
#include "ProcessorStudentArray.h"
using namespace std;
 
int main() {
	try {
		Student* studentArray;
		int sizeStudentArray;
		do {
			cout << "Input size of array: ";
			cin >> sizeStudentArray;
		} while (sizeStudentArray <= 0);

		studentArray = StudentFactory::iArrayStudent(sizeStudentArray);
		cout << endl << endl;
		cout << "Array of Students" << endl;
		for (int i = 0; i < sizeStudentArray; i++)
		{
			cout << studentArray[i].toString() << endl << endl;
		}
		int newSize = 0;
		cout << endl << "\nResult array of " << 2 << " kourse Students" << endl;
		Student* res = ProcessorStudentArray::chooseCourse(studentArray, sizeStudentArray, 2, newSize);
		if (newSize == 0)
		{
			cout << "No such!" << endl;
		}

		for (int i = 0; i < newSize; i++)
		{
			cout << res[i].toString() << endl << endl;
		}
	}

		catch(ExceptionDate& e)
{
	cerr << "exception caught: " << e.what() << '\n';
}
system("pause");
}