//
//  roster.h
//  test
//
//  Created by Chris Mckenzie on 11/8/24.
//
#include "student.h"

const string studentData[] =
{"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Chris,Mckenzie,cmcken10@wgu.edu,25,30,35,30,SOFTWARE"};

class Roster {
public:
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(string StudentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    
private:
    Student* newStudent;
    vector<Student*> classRosterArray;
};
