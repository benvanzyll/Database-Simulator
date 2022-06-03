#ifndef FACULTY_H
#define FACULTY_H

// Class for a faculty, inherits from General

#include "General.h"
#include "DLList.h"
#include <iostream>
#include <string>
using namespace std;

class Faculty : public General {
    public:
        Faculty();
        Faculty(string name, string id, string level, string department);
        ~Faculty();
        string GetDepartment();
        void GetStudents();
        void PrintInfo();
        void AddStudent(string studentId);
        void RemoveStudent(string studentId);

        string department;
        DLList<string>* students;
};

/*
Faculty()

Default constructor for
Faculty object.

Param: n/a
Return: n/a
*/
Faculty::Faculty() {
    name = "NULL";
    id = "NULL";
    level = "NULL";
    department = "NULL";
    students = new DLList<string>();
}

/*
Faculty()

Overloaded constructor for 
Faculty object. Sets name,
id, level, and department.
Creates doubly linked list
to store student IDs.

Param: string name, string id, string level, string department
Return: n/a
*/
Faculty::Faculty(string name, string id, string level, string department) {
    this->name = name;
    this->id = id;
    this->level = level;
    this->department = department;
    students = new DLList<string>();
}

/*
~Faculty()

Destructor for Faculty
class. Does nothing.

Param: n/a
Return: n/a
*/
Faculty::~Faculty() {}

string Faculty::GetDepartment() {
    return department;
}

/*
GetStudents()

Prints list of students
that Faculty object is
advising.

Param: n/a
Return: n/a
*/
void Faculty::GetStudents() {
    students->print();
}

/*
PrintInfo()

Prints all information
for a faculty.

Param: n/a
Return: n/a
*/
void Faculty::PrintInfo() {
    cout << "FACULTY INFORMATION" << endl;
    cout << "Name: " << GetName() << endl;
    cout << "ID: " << GetId() << endl;
    cout << "Level: " << GetLevel() << endl;
    cout << "Department: " << GetDepartment() << endl;
    cout << "Students Advising: "; GetStudents();
    cout << endl;
}

/*
AddStudent()

Adds a student ID to the
doubly linked list that the
faculty object advidses.

Param: string studentId
Return: n/a
*/
void Faculty::AddStudent(string studentId) {
    students->insertBack(studentId);
}

/*
RemoveStudent()

Removes a student ID from the
doubly linked list that the
faculty object advidses.

Param: string studentId
Return: n/a
*/
void Faculty::RemoveStudent(string studentId) {
    students->remove(studentId);
}

#endif
