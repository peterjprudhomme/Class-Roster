#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
#include "roster.h"
using namespace std;

int main()
{
    cout << "Scripting and Programming - Applications - C867" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 011046596" << endl;
    cout << "Name: Peter Prudhomme" << endl;
    cout << endl;
    
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
        "A5,Peter,Prudhomme,pprudh1@class.edu,31,20,35,30,SOFTWARE" 
    };
    
    Roster classRoster;

    for (int i = 0; i < 5; ++i) {
        classRoster.parse(studentData[i]);
    }

    classRoster.printAll();

    cout << endl;

    classRoster.printInvalidEmails();

    cout << endl;

    for (int i = 0; i < 5; ++i) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentId());
    }

    cout << endl;

    cout << "Print by Degree: SOFTWARE" << endl;
    classRoster.printByDegreeProgram(SOFTWARE);

    cout << endl;

    classRoster.remove("A3");
    classRoster.printAll();
    cout << endl;

    classRoster.remove("A3");
}
