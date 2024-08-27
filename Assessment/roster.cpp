#include "roster.h"
#include "student.h"
#include <iostream>
using namespace std;

Roster::Roster() {
	for (int i = 0; i < 5; ++i) {
		classRosterArray[i] = new Student();
	}
	newStudentPosition = 0;
}

Roster::~Roster() {
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i] != nullptr) {
			delete classRosterArray[i];
		}
	}
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	*classRosterArray[newStudentPosition] = Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
	++newStudentPosition;
}

void Roster::parse(string strToParse) {
	string currStudentID;
	string currFirstName;
	string currLastName;
	string currEmailAddress;
	int currAge;
	int currDaysInCourse1;
	int currDaysInCourse2;
	int currDaysInCourse3;
	DegreeProgram currDegreeProgram;

	int last_comma = 0;
	string currStudent[9];

	for (int i = 0; i < 9; ++i) {
		currStudent[i] = strToParse.substr(last_comma, strToParse.find(',', last_comma) - last_comma);
		last_comma = strToParse.find(',', last_comma) + 1;
	}

	currStudentID = currStudent[0];
	currFirstName = currStudent[1];
	currLastName = currStudent[2];
	currEmailAddress = currStudent[3];
	currAge = stoi(currStudent[4]);
	currDaysInCourse1 = stoi(currStudent[5]);
	currDaysInCourse2 = stoi(currStudent[6]);
	currDaysInCourse3 = stoi(currStudent[7]);
	if (currStudent[8] == "SECURITY") {
		currDegreeProgram = SECURITY;
	}
	else if (currStudent[8] == "NETWORK") {
		currDegreeProgram = NETWORK;
	}
	else if (currStudent[8] == "SOFTWARE") {
		currDegreeProgram = SOFTWARE;
	}

	add(currStudentID, currFirstName, currLastName, currEmailAddress, currAge, currDaysInCourse1, currDaysInCourse2, currDaysInCourse3, currDegreeProgram);
}

void Roster::printAll() const {
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->Print();
		}
	}
}

void Roster::remove(string studentID) {
	bool studentFound = false;

	for (int i = 0; i < 5; ++i) {
		if ((classRosterArray[i] != nullptr) && (classRosterArray[i]->GetStudentId() == studentID)) {
			studentFound = true;
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;
		}
	}
	
	if (studentFound == false) {
		cout << "ERROR -- Student ID " << studentID << " not found" << endl;
	}
}

void Roster::printAverageDaysInCourse(string studentID) const {
	int sum;
	double ave;

	for (int i = 0; i < 5; ++i) {
		if (studentID == classRosterArray[i]->GetStudentId()) {
			sum = classRosterArray[i]->GetDaysToComplete(0) + classRosterArray[i]->GetDaysToComplete(1) + classRosterArray[i]->GetDaysToComplete(2);
			ave = sum / 3.0;
			cout << "Student ID: " << studentID << ", Average days in courses: " << ave << endl;
		}
	}
}

void Roster::printInvalidEmails() const {
	string currEmail;

	for (int i = 0; i < 5; ++i) {
		currEmail = classRosterArray[i]->GetEmailAddress();
		if (
			currEmail.find('@') == string::npos
			|| currEmail.find('.') == string::npos
			|| currEmail.find(' ') != string::npos
			) {
			cout << currEmail << " - is invalid." << endl;
		}

	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i]->GetStudentProgram() == degreeProgram) {
			classRosterArray[i]->Print();
		}
	}
}