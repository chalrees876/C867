//
//  roster.cpp
//  test
//
//  Created by Chris Mckenzie on 11/8/24.
//
#include "roster.h"
#include <iostream>

unsigned long Roster::getNumStudents() {
    return classRosterArray.size();
}

vector<Student*> Roster::getClassRosterArray(){
    return classRosterArray;
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    Student* newStudent = new Student;
    
    newStudent->SetStudentID(studentID);
    newStudent->SetFirstName(firstName);
    newStudent->SetLastname(lastName);
    newStudent->SetEmailAddress(emailAddress);
    newStudent->SetAge(age);
    vector<int> currDaysToComplete(3);
    currDaysToComplete.at(0) = daysInCourse1;
    currDaysToComplete.at(1) = daysInCourse2;
    currDaysToComplete.at(2) = daysInCourse3;
    newStudent->setDaysToComplete(currDaysToComplete);
    newStudent->SetDegreeProgram(degreeProgram);
    
    classRosterArray.push_back(newStudent);
}

void Roster::remove(string studentID) {
    bool found = false;
    while (!found) {
        for (int i =0; i < classRosterArray.size(); ++i) {
            if (classRosterArray.at(i)->GetStudentId() == studentID) {
                classRosterArray.erase(classRosterArray.begin() + i);
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
    for (int i = 0; i < classRosterArray.size(); ++i) {
        cout << "///////////////////////////////////" << endl;
        cout << classRosterArray.at(i)->GetStudentId() << "\t";
        cout << "First Name: " << classRosterArray.at(i)->GetFirstName() << "\t";
        cout << "Last Name: " << classRosterArray.at(i)->GetLastName() << "\t";
        cout << "Age: " << classRosterArray.at(i)->GetAge() << "\t";
        cout << "daysInCourse: {" <<
        classRosterArray.at(i)->GetDaysToComplete().at(0) << ", " <<
        classRosterArray.at(i)->GetDaysToComplete().at(1) << ", " <<
        classRosterArray.at(i)->GetDaysToComplete().at(2) << "}\t";
        cout << "Degree Program: ";
        
        if (classRosterArray.at(i)->GetDegreeProgram() == 0) {
            cout << "SECURITY";
        }
        else if (classRosterArray.at(i)->GetDegreeProgram() == 1) {
            cout << "NETWORK";
        }
        else if (classRosterArray.at(i)->GetDegreeProgram() == 2) {
            cout << "SOFTWARE";
        }
        else {
            cout << "NONE";
        }
        
        cout << "}" << endl;
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    bool found = false;
    double average;
    cout << "///////////////////////////////////" << endl;
    while (!found) {
        for (int i =0; i < classRosterArray.size(); ++i) {
            if (classRosterArray.at(i)->GetStudentId() == studentID) {
                average =
                (classRosterArray.at(i)->GetDaysToComplete().at(0) +
                classRosterArray.at(i)->GetDaysToComplete().at(1) +
                 classRosterArray.at(i)->GetDaysToComplete().at(2)) / 3.0;
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
    for (int i = 0; i < classRosterArray.size(); ++i) {
        currEmail = classRosterArray.at(i)->GetEmailAddress();
        foundAt = currEmail.find('@');
        foundPeriod = currEmail.find('.');
        foundSpace = currEmail.find(' ');
        if (foundAt != string::npos && foundPeriod != string::npos && foundSpace == string::npos) {
            continue;
        }
        else {
            cout << "Invalid email address: " << classRosterArray.at(i)->GetEmailAddress() << endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < classRosterArray.size(); ++i) {
        if (classRosterArray.at(i)->GetDegreeProgram() == degreeProgram) {
            classRosterArray.at(i)->PrintStudent();
        }
    }
}

Roster::~Roster() {
    for (int i = 0; i < classRosterArray.size(); ++i) {
        cout << "in Roster Deconstructor: " << classRosterArray.at(i)->GetStudentId() << endl;
        delete classRosterArray.at(i);
    }
}