#include "ProcessorStudentArray.h"

Student* ProcessorStudentArray::chooseCourse(Student* arrayStud, int size, int kurs, int& newSize)
{
	Student* arraySt = new Student[size];
	newSize = 0;
	for (int i = 0; i < size; i++)
	{
		if (arrayStud[i].getCourse() == kurs)
		{
			arraySt[newSize] = arrayStud[i];
			newSize++;
		}
	}

	return arraySt;
}

