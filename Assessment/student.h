#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "degree.h"
using namespace std;

class Student {
	public:
		Student();
		Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
		string GetStudentId() const;
		string GetFirstName() const;
		string GetLastName() const;
		string GetEmailAddress() const;
		int GetAge() const;
		int GetDaysToComplete(int idx) const;
		DegreeProgram GetStudentProgram() const;
		void SetStudentId(string studentID);
		void SetFirstName(string firstName);
		void SetLastName(string lastName);
		void SetEmailAddress(string emailAddress);
		void SetAge(int age);
		void SetDaysToComplete(int inVal, int idx);
		void SetStudentProgram(DegreeProgram studentProgram);
		void Print() const;
	private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		int numDaysToComplete[3];
		DegreeProgram studentProgram;
		static const string studentProgramsArray[3];
};

#endif
