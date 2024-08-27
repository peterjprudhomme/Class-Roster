#ifndef ROSTER_H
#define ROSTER_H
#include <string>
#include "degree.h"
#include "student.h"
using namespace std;

class Roster {
	public:
		Roster();
		~Roster();
		void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
		void parse(string strToParse);
		void remove(string studentID);
		void printAll() const;
		void printAverageDaysInCourse(string studentID) const;
		void printInvalidEmails() const;
		void printByDegreeProgram(DegreeProgram degreeProgram);
		Student* classRosterArray[5];
	private:
		int newStudentPosition;
};

#endif