//
//  student.h
//  test
//
//  Created by Chris Mckenzie on 11/8/24.
//

#ifndef STUDENT_H
#define STUDENT_H
#include "degree.h"
#include <vector>
#include <string>
using namespace std;

class Student {
    public:
        ///Mutators
        Student(string currId, string currFirstName, string currLastName, string currEmail, int currAge, int currDaysToComplete1, int currDaysToComplete2, int currDaysToComplete3, DegreeProgram currDegreeProgram);
        Student();
        void SetStudentID(string currId);
        void SetFirstName(string currFirstName);
        void SetLastname(string currLastName);
        void SetEmailAddress(string currEmail);
        void SetAge(int currAge);
        void setDaysToComplete(int daysToComplete1, int daysToComplete2, int daysToComplete3);
        void SetDegreeProgram(DegreeProgram currDegreeProgram);
        ///Accessors
        string GetStudentId() const ;
        string GetFirstName() const ;
        string GetLastName() const ;
        string GetEmailAddress() const ;
        int GetAge() const ;
        int GetDaysToComplete1() const ;
        int GetDaysToComplete2() const ;
        int GetDaysToComplete3() const;
        DegreeProgram GetDegreeProgram() const ;
        void PrintStudent() const;
        ~Student();
    

    private:
        string studentId;
        string firstName;
        string lastName;
        string email;
        int age;
        int daysToComplete[3];
        DegreeProgram degreeProgram;
};


#endif
