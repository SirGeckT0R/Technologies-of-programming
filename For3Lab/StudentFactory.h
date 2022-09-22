#pragma once
#include "Student.h"

class StudentFactory
{
public:
	static Student iStudent();
	static Student* iArrayStudent(int size);
};

