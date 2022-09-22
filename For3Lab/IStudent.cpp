#include <iostream>
#include "IStudent.h"
#include "DateValidator.h"
#include "IPerson.h"

using namespace std;


Student IStudent::iConsole() {
	Student student;
	DateValidator validator;
	int number;
	cout << "\nEnter student" << endl;
	do {
		cout << "Enter number:" << endl;
		cin >> number;
	} while (!validator.isNumberValid(number));
	student.setNumber(number);

	
	IPerson iperson;
	Person person = iperson.inputPerson();
	student.setPerson(person);

	char faculty[MAX_FUCULTY];
	cout << "Enter faculty :" << endl;
	cin >> faculty;
	student.setFaculty(faculty);
	do {
		cout << "Enter course:" << endl;
		cin >> number;
	} while (!validator.isCourse(number));
	student.setCourse(number);

	do {
		cout << "Enter group:" << endl;
		cin >> number;
	} while (!validator.isGroup(number));
	student.setGroup(number);

	double average;
	do {
		cout << "Enter averageScore:" << endl;
		cin >> average;
	} while (!validator.isAverageBall(average));
	student.setAverageBall(average);

	return student;
}
