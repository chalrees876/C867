//
//  main.cpp
//  test
//
//  Created by Chris Mckenzie on 11/6/24.
//

#include <iostream>
using namespace std;
#include "student.h"

Student::Student(string studentId, string firstName, string lastName, string email, int age, int daysToComplete1, int daysToComplete2, int daysToComplete3, DegreeProgram degreeProgram)
    {
    this->studentId = studentId;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    this->daysToComplete.push_back(daysToComplete1);
    this->daysToComplete.push_back(daysToComplete2);
    this->daysToComplete.push_back(daysToComplete3);
    this->degreeProgram = degreeProgram;
}

Student::Student()
    {
    this->studentId = "Unknown";
    this->firstName = "Unknown";
    this->lastName = "Unknown";
    this->email = "Unknown";
    this->age = -1;
    this->daysToComplete.push_back(-1);
    this->daysToComplete.push_back(-1);
    this->daysToComplete.push_back(-1);
    this->degreeProgram = NONE;
}

void Student::SetStudentID(string studentId) {
    this->studentId = studentId;
}
void Student::SetFirstName(string firstName) {
    this->firstName = firstName;
}
void Student::SetLastname(string lastName) {
    this->lastName = lastName;
}
void Student::SetEmailAddress(string currEmail) {
    this->email = currEmail;
}
void Student::SetAge(int age) {
    this->age = age;
}
void Student::setDaysToComplete(vector<int> daysToComplete) {
    this->daysToComplete = daysToComplete;
}
void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}
///Accessors
string Student::GetStudentId() const {
    return studentId;
}
string Student::GetFirstName() const {
    return firstName;
}
string Student::GetLastName() const {
    return lastName;
}
string Student::GetEmailAddress() const {
    return email;
}
int Student::GetAge() const {
    return age;
}

/// FIX ME Figure out days to complete array

vector<int> Student::GetDaysToComplete() const {
    return daysToComplete;
}

DegreeProgram Student::GetDegreeProgram() const {
    return degreeProgram;
}

void Student::PrintStudent() const {

    cout << "Student Age: " << age << endl;
    cout << "Student Name: " << lastName << ", " << firstName << endl;
    cout << "Student Email: " << email << endl;
    cout << "Days to complete course 1: " << daysToComplete.at(0) << endl;
    cout << "Days to complete course 2: " << daysToComplete.at(1) << endl;
    cout << "Days to complete course 3: " << daysToComplete.at(2) << endl;
    cout << "Student Degree Program: ";
    
    if (degreeProgram == 0) {
        cout << "SECURITY" << endl;
    }
    else if (degreeProgram == 1) {
        cout << "NETWORK" << endl;
    }
    else if (degreeProgram == 2) {
        cout << "SOFTWARE" << endl;
    }
    else {
        cout << "NONE" << endl;
    }
}

Student::~Student() {
    cout << "in student deconstructor: " << this->studentId << endl;
}
