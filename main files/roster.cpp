//
//  roster.cpp
//  test
//
//  Created by Chris Mckenzie on 11/8/24.
//
#include "roster.h"
#include <iostream>

unsigned long Roster::getNumStudents() {
    return studentNumber;
}

//vector<Student*> Roster::getClassRosterArray(){
 //   return classRosterArray;
//}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    
    classRosterArray[studentNumber] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    this->studentNumber++;
}

void Roster::remove(string studentID) {
    bool found = false;
    while (!found) {
        for (int i =0; i < studentNumber; ++i) {
            if (classRosterArray[i]->GetStudentId() == studentID) {
                cout << "///////////////////////////////////" << endl;
                cout << "Student ID: " << classRosterArray[i]->GetStudentId() << " has been removed." << endl;
                --studentNumber;
                for (int j = i; j < studentNumber; ++j) {
                    classRosterArray[j] = classRosterArray[j+1];
                }
                classRosterArray[studentNumber] = nullptr;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "///////////////////////////////////" << endl;
            cout << "Error, student not found" << endl;
            break;
        }
    }
    
}

void Roster::printAll() {
    for (int i = 0; i < studentNumber; ++i) {
        classRosterArray[i]->PrintStudent();
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    bool found = false;
    double average;
    cout << "///////////////////////////////////" << endl;
    while (!found) {
        for (int i =0; i < studentNumber; ++i) {
            if (classRosterArray[i]->GetStudentId() == studentID) {
                average =
                (classRosterArray[i]->GetDaysToComplete1() +
                classRosterArray[i]->GetDaysToComplete2() +
                 classRosterArray[i]->GetDaysToComplete3()) / 3.0;
                cout << "Student ID: " << classRosterArray[i]->GetStudentId() << endl;
                cout << "Average days in courses: " << average << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Error, student not found" << endl;
            break;
        }
    }

}

void Roster::printInvalidEmails() {
    string currEmail;
    unsigned long foundAt, foundPeriod, foundSpace;
    cout << "///////////////////////////////////" << endl;
    for (int i = 0; i < studentNumber; ++i) {
        currEmail = classRosterArray[i]->GetEmailAddress();
        foundAt = currEmail.find('@');
        foundPeriod = currEmail.find('.');
        foundSpace = currEmail.find(' ');
        if (foundAt != string::npos && foundPeriod != string::npos && foundSpace == string::npos) {
            continue;
        }
        else {
            cout << "Invalid email address: " << classRosterArray[i]->GetEmailAddress() << endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < studentNumber; ++i) {
        if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
            classRosterArray[i]->PrintStudent();
        }
    }
}

//Deconstructor
Roster::~Roster() {
    for (int i = 0; i < studentNumber; ++i) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
