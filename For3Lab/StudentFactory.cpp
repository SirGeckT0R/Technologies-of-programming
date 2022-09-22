#include "StudentFactory.h"
#include "IStudent.h"
Student StudentFactory::iStudent()
{
	return IStudent::iConsole();
}

Student* StudentFactory::iArrayStudent(int size)
{
	Student* arrayStudent;
	arrayStudent = new Student[size];
	for (size_t i = 0; i < size; i++)
	{
		arrayStudent[i] = StudentFactory::iStudent();
	}
	return arrayStudent;
}
