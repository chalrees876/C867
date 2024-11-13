//
//  roster.h
//  test
//
//  Created by Chris Mckenzie on 11/8/24.
//
#include "student.h"

class Roster {
public:
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(string StudentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    unsigned long getNumStudents(); // added accessor to access number of students in classRosterArray.
    vector<Student*> getClassRosterArray(); //added accessor to access classRosterArray and be able to index into it.
    ~Roster();
    
private:
    Student* newStudent;
    vector<Student*> classRosterArray;
};
