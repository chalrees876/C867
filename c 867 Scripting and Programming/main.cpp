//
//  main.cpp
//  test
//
//  Created by Chris Mckenzie on 11/8/24.
//

#include "student.h"
#include "roster.h"
#include <iostream>
#include <string>
using namespace std;

void parseStudentData(const string studentData[], int studentListSize, Roster& newRoster);

int main() {
    int studentListSize = (sizeof(studentData)/sizeof(studentData[0]));
    
    Roster classRoster;
    
    parseStudentData(studentData, studentListSize, classRoster);//parses student data from table and adds it to classRoster object.
    
    classRoster.printAll();
    
    classRoster.remove("A3");
    
    classRoster.printAll();
    
    classRoster.printAverageDaysInCourse("A2");
    
    return 0;
    
    
}


void parseStudentData(const string studentData[], int studentListSize, Roster& newRoster) {
    int i;
    unsigned long nextCommaPosition; //Used to count the commas in each student data string.
    int age, daysToComplete1, daysToComplete2, daysToComplete3;
    string studentID, firstName, lastName, email, s, ageString, daysToComplete1String, daysToComplete2String, daysToComplete3String, degreeProgramString;
    DegreeProgram degreeProgram;
    
    for (i = 0; i < studentListSize; i++) {
        s = studentData[i]; //store each iteration of student data in variable s for cleaner code
        
        nextCommaPosition = s.find(',');
        studentID = s.substr(0, nextCommaPosition);
        s = s.substr(studentID.length() + 1);
        
        nextCommaPosition = s.find(','); //finds next comma
        firstName = s.substr(0, nextCommaPosition);
        s = s.substr(firstName.length() + 1);
        
        nextCommaPosition = s.find(','); //finds next comma
        lastName = s.substr(0, nextCommaPosition);
        s = s.substr(lastName.length() + 1);
        
        nextCommaPosition = s.find(','); //finds next comma
        email = s.substr(0, nextCommaPosition);
        s = s.substr(email.length() + 1);
        
        nextCommaPosition = s.find(','); //finds next comma
        ageString = s.substr(0, nextCommaPosition);
        age = stoi(ageString);
        s = s.substr(ageString.length() + 1);
        
        nextCommaPosition = s.find(','); //finds next comma
        daysToComplete1String = s.substr(0, nextCommaPosition);
        daysToComplete1 = stoi(ageString);
        s = s.substr(daysToComplete1String.length() + 1);
        
        nextCommaPosition = s.find(','); //finds next comma
        daysToComplete2String = s.substr(0, nextCommaPosition);
        daysToComplete2 = stoi(ageString);
        s = s.substr(daysToComplete2String.length() + 1);
    
        nextCommaPosition = s.find(','); //finds next comma
        daysToComplete3String = s.substr(0, nextCommaPosition);
        daysToComplete3 = stoi(ageString);
        s = s.substr(daysToComplete3String.length() + 1);
        
        nextCommaPosition = s.find(','); //finds next comma
        degreeProgramString = s.substr(0, nextCommaPosition);
                
        if (degreeProgramString == "SECURITY") {
            degreeProgram = SECURITY;
        }
        else if (degreeProgramString == "NETWORK") {
            degreeProgram = NETWORK;
        }
        else if (degreeProgramString == "SOFTWARE") {
            degreeProgram = SOFTWARE;
        }
        else {
            degreeProgram = NONE;
        }
        
        newRoster.add(studentID, firstName, lastName, email, age, daysToComplete1, daysToComplete2, daysToComplete3, degreeProgram);
    }
}

