//
//  main.cpp
//  test
//
//  Created by Chris Mckenzie on 11/6/24.
//

#include <iostream>
using namespace std;
#include "student.h"

///Student Constructor with every parameter
Student::Student(string studentId, string firstName, string lastName, string email, int age, int daysToComplete1, int daysToComplete2, int daysToComplete3, DegreeProgram degreeProgram)
    {
    this->studentId = studentId;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    this->daysToComplete[0] = daysToComplete1;
    this->daysToComplete[1] = daysToComplete2;
    this->daysToComplete[2] = daysToComplete3;
    this->degreeProgram = degreeProgram;
}

///default student constructor with no parameters
Student::Student()
    {
    this->studentId = "Unknown";
    this->firstName = "Unknown";
    this->lastName = "Unknown";
    this->email = "Unknown";
    this->age = -1;
    this->daysToComplete[0] = -1;
    this->daysToComplete[1] = -1;
    this->daysToComplete[2] = -1;
    this->degreeProgram = NONE;
}

///mutators
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
void Student::setDaysToComplete(int daysToComplete1, int daysToComplete2, int daysToComplete3) {
    this->daysToComplete[0] = daysToComplete1;
    this->daysToComplete[1] = daysToComplete2;
    this->daysToComplete[2] = daysToComplete3;
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

int Student::GetDaysToComplete1() const {
    return daysToComplete[0];
}

int Student::GetDaysToComplete2() const {
    return daysToComplete[1];
}

int Student::GetDaysToComplete3() const {
    return daysToComplete[2];
}

DegreeProgram Student::GetDegreeProgram() const {
    return degreeProgram;
}

void Student::PrintStudent() const {
    
    cout << "///////////////////////////////////" << endl;
    
    cout << "Student ID: " << studentId << endl;

    cout << "Student Age: " << age << endl;
    
    cout << "Student Name: " << lastName << ", " << firstName << endl;
    
    cout << "Student Email: " << email << endl;
    
    cout << "Days to complete: {" <<
    daysToComplete[0] << ", " <<
    daysToComplete[1] << ", " <<
    daysToComplete[2] << "}" << endl;
    
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

///Deconstructor
Student::~Student() {
    cout << "in student deconstructor: " << this->studentId << endl;
    return;
}
