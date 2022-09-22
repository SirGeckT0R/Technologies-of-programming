#pragma once
#include "Person.h"

#define MAX_FUCULTY 20

class Student
{
	int number;
	Person person;
	char faculty[MAX_FUCULTY];
	int course;
	int group;
	double averageScore;
public:
	Student();
	Student(int number, Person person, char* faculty, int course, int group, double averageScore);
	~Student();

	void setNumber(int number);
	void setPerson(Person person);
	void setFaculty(char* faculty);
	void setCourse(int course);
	void setGroup(int group);
	void setAverageBall(double b);
	
	int getNumber();
	int getCourse();
	int getGroup();
	double getAverageBall();
    Person getPerson();
	char* getFaculty();

	string toString();
};


