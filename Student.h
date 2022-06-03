#ifndef STUDENT_H
#define STUDENT_H

// Class for a student, inherits from General

#include "General.h"
#include <iostream>
#include <string>
using namespace std;

class Student : public General {
    public:
        Student();
        Student(string name, string id, string level, string major, string gpa, string advisorId);
        ~Student();
        string GetMajor();
        string GetGpa();
        string GetAdvisorId();
        void SetAdvisor(string advisorId);
        void PrintInfo();
        
        string major;
        string gpa;
        string advisorId;
};

/*
Student()

Default constructor for
Student object.

Param: n/a
Return: n/a
*/
Student::Student() {
    name = "NULL";
    id = "NULL";
    level = "NULL";
    major = "NULL";
    gpa = "NULL";
    advisorId = "NULL";
}

/*
Student()

Overloaded constructor for 
Student object. Sets name,
id, level, and memeber
variables.

Param: string name, string id, string level, string major, string gpa, string advisorId
Return: n/a
*/
Student::Student(string name, string id, string level, string major, string gpa, string advisorId) {
    this->name = name;
    this->id = id;
    this->level = level;
    this->major = major;
    this->gpa = gpa;
    this->advisorId = advisorId;
}

/*
~Student()

Destructor for Student
class. Does nothing.

Param: n/a
Return: n/a
*/
Student::~Student() {}


/*
GetMajor()

Returns major of
student.

Param: n/a
Return: string major
*/
string Student::GetMajor() {
    return major;
}

/*
GetGpa()

Returns gpa of
student.

Param: n/a
Return: string gpa
*/
string Student::GetGpa() {
    return gpa;
}

/*
GetAdvisorId()

Returns advisorId of
student.

Param: n/a
Return: string advisorId
*/
string Student::GetAdvisorId() {
    return advisorId;
}

/*
SetAdvisor()

Sets advisorId for
Student object.

Param: string advisorId
Return: n/a
*/
void Student::SetAdvisor(string advisorId) {
    this->advisorId = advisorId;
}

/*
PrintInfo()

Prints all information
for a student.

Param: n/a
Return: n/a
*/
void Student::PrintInfo() {
    cout << "STUDENT INFORMATION" << endl;
    cout << "Name: " << GetName() << endl;
    cout << "ID: " << GetId() << endl;
    cout << "Level: " << GetLevel() << endl;
    cout << "Major: " << GetMajor() << endl;
    cout << "GPA: " << GetGpa() << endl;
    cout << "Advisor ID: " << GetAdvisorId() << endl;
    cout << endl;
}

#endif
