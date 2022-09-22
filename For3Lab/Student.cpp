#include <string>
#include "Student.h"
#include "DateValidator.h"
#include "ExceptionDate.h"
using namespace std;

Student::Student(){}

Student::Student(int number, Person person, char* faculty, int course, int group, double averageScore) {
	setNumber(number);
	setPerson(person);
	strcpy_s(this->faculty, strlen(faculty) + 1, faculty);
	setCourse(course);
	setGroup(group);
	setAverageBall(averageScore);
}

Student::~Student()
{
}


int Student::getNumber() {
	return this->number;
}
int Student::getCourse() {
	return this->course; 
}

int Student::getGroup() {
	return this->group;
}

double Student::getAverageBall() {
	return this->averageScore;
}

Person Student::getPerson() {
	return this->person;
}

char* Student::getFaculty() { 
	return this->faculty;
}

void Student::setNumber(int number) {
	DateValidator validator;
	if (validator.isNumberValid(number))
		this->number = number;
	else throw ExceptionDate("The number is wrong!");
}

void Student::setCourse(int course) {
	DateValidator validator;
	if (validator.isCourse(course))
		this->course = course;
	else throw ExceptionDate("The course is wrong!");
}

void Student::setFaculty(char* faculty) {
	if (strlen(faculty) <= MAX_FUCULTY)
		strcpy_s(this->faculty, strlen(faculty) + 1, faculty);
	else throw ExceptionDate("The faculty is wrong!");
}

void Student::setPerson(Person person) {
	this->person = person;
}

void Student::setGroup(int group) {
	DateValidator validator;
	if (validator.isGroup(group))
		this->group = group;
	else throw ExceptionDate("The group is wrong!");
}

void Student::setAverageBall(double b) {
	DateValidator validator;
	if (validator.isAverageBall(b))
		this->averageScore = b;
	else throw ExceptionDate("The averageScore is wrong!");
}

string Student::toString() {
	std::string str = "number: "+ to_string(number) + "\n" + person.toString() + "\nfaculty: " 
		+ this->faculty + "\ncourse: " + to_string(course) + "\ngroup: " + to_string(group)
		+ "\naverageScore: " + to_string(averageScore);	
	return str;
}