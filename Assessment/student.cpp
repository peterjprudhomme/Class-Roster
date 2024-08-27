#include "student.h"
#include <iostream>
using namespace std;

Student::Student() {
	studentID = "No ID";
	firstName = "No first name";
	lastName = "No last name";
	emailAddress = "No email";
	age = -1;
	numDaysToComplete[0] = 0;
	numDaysToComplete[1] = 0;
	numDaysToComplete[2] = 0;
	studentProgram = SOFTWARE;
}
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	numDaysToComplete[0] = daysInCourse1;
	numDaysToComplete[1] = daysInCourse2;
	numDaysToComplete[2] = daysInCourse3;
	this->studentProgram = degreeProgram;
}

string Student::GetStudentId() const {
	return studentID;
}

string Student::GetFirstName() const {
	return firstName;
}

string Student::GetLastName() const {
	return lastName;
}

string Student::GetEmailAddress() const {
	return emailAddress;
}

int Student::GetAge() const {
	return age;
}

int Student::GetDaysToComplete(int idx) const {
	return numDaysToComplete[idx];
}

DegreeProgram Student::GetStudentProgram() const {
	return studentProgram;
}

void Student::SetStudentId(string studentID) {
	this->studentID = studentID;
}

void Student::SetFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::SetLastName(string lastName) {
	this->lastName = lastName;
}

void Student::SetEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}

void Student::SetAge(int age) {
	this->age = age;
}

void Student::SetDaysToComplete(int inVal, int idx) {
	numDaysToComplete[idx] = inVal;
}

void Student::SetStudentProgram(DegreeProgram studentProgram) {
	this->studentProgram = studentProgram;
}

const string Student::studentProgramsArray[3] = { "SECURITY", "NETWORK", "SOFTWARE" };

void Student::Print() const {
	cout << studentID << "   First name: " << firstName << "   Last name: " << lastName << "   Age: " << age;
	cout << "   Days in Course: {" << numDaysToComplete[0] << ", " << numDaysToComplete[1] << ", " << numDaysToComplete[2];
	cout << "}   Degree Program: " << studentProgramsArray[studentProgram] << endl;
}