#ifndef SIMULATION_H
#define SIMULATION_H

// Class for a Simulation

#include "GeneralBST.h"
#include "Student.h"
#include "Faculty.h"
#include "AStack.h"
#include <fstream>
#include <iostream>
using namespace std;

class Simulation {
    public:
        Simulation();
        Simulation(GeneralBST<Student> studentBST, GeneralBST<Faculty> facultyBST);
        ~Simulation();

        GeneralBST<Student> studentBST;
        GeneralBST<Faculty> facultyBST;

        AStack<GeneralBST<Student> >* rollbackStudent = new AStack<GeneralBST<Student> >(5);
        AStack<GeneralBST<Faculty> >* rollbackFaculty = new AStack<GeneralBST<Faculty> >(5);

        void Simulate();
        void PrintAllStudents();
        void PrintAllFaculty();
        Student SearchStudent(string id);
        Faculty SearchFaculty(string id);
        void AddStudent();
        void RemoveStudentSim(string id);
        void AddFaculty();
        void RemoveFacultySim(string id);
        void PrintAdvisor(string id);
        void PrintAdvisee(string id);
        void ChangeAdvisor(string studentId, string facultyId); // Does not work, issue with SetAdvisor()
        void RemoveAdvisee(string studentId, string facultyId);
        void Rollback();

};

/*
Simulation()

Default constructor for
Simulation object.
Does nothing.

Param: n/a
Return: n/a
*/
Simulation::Simulation() {}

/*
Simulation()

Overloaded constructor
for Simulation object.
Sets binary trees, one
for Student objects and 
one for Faculty. Also creates
a history object for rollback?

Param: n/a
Return: n/a
*/
Simulation::Simulation(GeneralBST<Student> studentBST, GeneralBST<Faculty> facultyBST) {
    this->studentBST = studentBST;
    this->facultyBST = facultyBST;
    // stack object for last X changes for rollback?
}

/*
~Simulation()

Destructor for Simulation
class. Does nothing.

Param: n/a
Return: n/a
*/
Simulation::~Simulation() {}

/*
PrintAllStudents()

Prints every student
in the studentBST and
all of their identifying
information

Param: n/a
Return: n/a
*/
void Simulation::PrintAllStudents() {
    studentBST.inOrder(studentBST.getRoot());
}

/*
PrintAllFaculty()

Prints every faculty
in the facultyBST and
all of their identifying
information

Param: n/a
Return: n/a
*/
void Simulation::PrintAllFaculty() {
    facultyBST.inOrder(facultyBST.getRoot());
}

/*
SearchStudent()

Searches for a student in
the studentBST based on 
the id passed as param

Param: string id
Return: Student
*/
Student Simulation::SearchStudent(string id) {
    if (!studentBST.contains(id))
        return Student();
    return studentBST.find(id);
}

/*
SearchFaculty()

Searches for a faculty in
the facultyBST based on 
the id passed as param

Param: string id
Return: Faculty
*/
Faculty Simulation::SearchFaculty(string id) {
    if (!facultyBST.contains(id)) {
        return Faculty();
    }
    return facultyBST.find(id);
}

/*
AddStudent()

Asks user for information
to fill Student object with.
Creates student object after
getting all info and adds
student to the studentBST.
Also adds student id to
corresponding advisor.

Param: n/a
Return: n/a
*/
void Simulation::AddStudent() {
    string name, id, level, major, gpa, advisorId;
    cout << "Enter name: ";
    cin.ignore(1,'\n');
    getline(cin, name);
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter level: ";
    cin >> level;
    cout << "Enter major: ";
    cin.ignore(1,'\n');
    getline(cin, major);
    cout << "Enter GPA: ";
    cin >> gpa;
    cout << "Enter Advisor ID: ";
    cin >> advisorId;
    if (!facultyBST.contains(advisorId))
        cout << "ERROR: No Such Advisor" << endl;
    else {
        studentBST.insert(new TreeNode<Student>(id, Student(name, id, level, major, gpa, advisorId)));
        facultyBST.find(advisorId).AddStudent(id);
    }
    cout << endl;
}

/*
RemoveStudent()

Removes a student
from the studentBST
given a student ID
as a parameter.

Param: string id
Return: n/a
*/
void Simulation::RemoveStudentSim(string id) {
    if (!studentBST.contains(id))
        cout << "ERROR: Student does not exist" << endl;
    else {
        facultyBST.find(studentBST.find(id).GetAdvisorId()).RemoveStudent(id);
        studentBST.remove(id);
    }
}

/*
AddFaculty()

Asks user for information
to fill Faculty object with.
Creates faculty object after
getting all info and adds
faculty to the facultyBST.

Param: n/a
Return: n/a
*/
void Simulation::AddFaculty() {
    string name, id, level, department;
    cout << "Enter name: ";
    cin.ignore(1,'\n');
    getline(cin, name);
    cout << "Enter ID: ";
    cin >> id;
    cin.ignore(1,'\n');
    cout << "Enter level: ";
    getline(cin, level);
    cout << "Enter department: ";
    getline(cin, department);

    facultyBST.insert(new TreeNode<Faculty>(id, Faculty(name, id, level, department)));
    cout << endl;
}

/*
RemoveFaculty()

Removes a faculty
from the facultyBST
given a faculty ID
as a parameter.

Param: string id
Return: n/a
*/
void Simulation::RemoveFacultySim(string id) {
    if (!facultyBST.contains(id))
        cout << "ERROR: Faculty does not exist" << endl;
    else {
        facultyBST.remove(id);
    }
}

/*
PrintAdvisor()

Prints a student's
advisor's information
given a student's ID
number.

Param: string id
Return: n/a
*/
void Simulation::PrintAdvisor(string id) {
    if (!studentBST.contains(id))
        cout << "ERROR: Student does not exist" << endl;
    else {
        cout << "---------- " << studentBST.find(id).GetName() << "'s Advisor Info " << "----------" << endl;
        facultyBST.find(studentBST.find(id).GetAdvisorId()).PrintInfo();
    }
    cout << endl;
}

/*
PrintAdvisee()

Prints a faculty's
student information
given a faculty ID
number.

Param: string id
Return: n/a
*/
void Simulation::PrintAdvisee(string id) {
    if (!facultyBST.contains(id))
        cout << "ERROR: Faculty does not exist" << endl;
    else {
        cout << endl << "---------- " << facultyBST.find(id).GetName() << "'s Advisee Info " << "----------" << endl;
        //cout << facultyBST.find(id).GetName() << " advises: "; facultyBST.find(id).GetStudents();
        /*ListNode<string>* curr = facultyBST.find(id).students->head;
        while (curr->next != nullptr) {
            studentBST.find(curr->element).PrintInfo();
            cout << endl;
            curr = curr->next;
        }
        cout << endl;*/
        ListNode<string>* curr = facultyBST.find(id).students->head;
        for (int i = 0; i < facultyBST.find(id).students->length(); i++) {
            studentBST.find(curr->element).PrintInfo();
            cout << endl;
            curr = curr->next;
        }
    }
    cout << endl;
}

/*
ChangeAdvisor()

Change a student's
advisor given a student
ID and the new advisor's
ID.

Param: string studentId, string facultyId
Return: n/a
*/
void Simulation::ChangeAdvisor(string studentId, string facultyId) {
    if (!studentBST.contains(studentId))
        cout << "ERROR. Student does not exist" << endl;
    else if (!facultyBST.contains(facultyId))
        cout << "ERROR. Faculty does not exist" << endl;
    else {
        studentBST.find(studentId).SetAdvisor(facultyId);
        facultyBST.find(studentBST.find(studentId).GetAdvisorId()).RemoveStudent(studentId);
        facultyBST.find(facultyId).AddStudent(studentId);
    }
}

/*
RemoveAdvisee()

Remove a student from the
list of advisees for a 
faculty given a student and
a faculty id.

Param: string studentId, string facultyId
Return: n/a
*/
void Simulation::RemoveAdvisee(string facultyId, string studentId) {
    if (!studentBST.contains(studentId))
        cout << "ERROR. Student does not exist" << endl;
    else if (!facultyBST.contains(facultyId))
        cout << "ERROR. Faculty does not exist" << endl;
    else {
        facultyBST.find(studentBST.find(studentId).GetAdvisorId()).RemoveStudent(studentId);
        studentBST.find(studentId).SetAdvisor("NULL");
    }
}

/*
Simulate()

Simulates the functionality
of the program. Displays the
options to the user and carries
everything out.

Param: n/a
Return: n/a
*/
void Simulation::Simulate() {
    while (true) {
        int selected;
        string studentId;
        string facultyId;

        cout << "\n------------------------------------ OPTIONS ------------------------------------ \n" << endl;
        cout << "1.  Print all students and their information (sorted by ascending ID #)" << endl;
        cout << "2.  Print all faculty and their information (sorted by ascending ID #) " << endl;
        cout << "3.  Find and display student information given the students ID" << endl;
        cout << "4.  Find and display faculty information given the faculty ID" << endl;
        cout << "5.  Given a student’s ID, print the name and info of their faculty advisor" << endl;
        cout << "6.  Given a faculty ID, print ALL the names and info of his/her advisees" << endl;
        cout << "7.  Add a new student" << endl;
        cout << "8.  Delete a student given the ID" << endl;
        cout << "9.  Add a new faculty member" << endl;
        cout << "10. Delete a faculty member given the ID" << endl;
        cout << "11. Change a student’s advisor given the student ID and the new faculty ID" << endl;
        cout << "12. Remove an advisee from a faculty member given the IDs" << endl;
        cout << "13. Rollback" << endl;
        cout << "14. Exit \n" << endl;
        cout << "Enter your choice: ";
        cin >> selected;

        switch(selected) {
            case 1: {
                PrintAllStudents();
                break;
            }
            case 2: {
                PrintAllFaculty();
                break;
            }
            case 3: {
                cout << "Enter student ID: ";
                cin >> studentId;
                SearchStudent(studentId).PrintInfo();
                break;
            }
            case 4: {
                cout << "Enter faculty ID: ";
                cin >> facultyId;
                SearchFaculty(facultyId).PrintInfo();
                break;
            }
            case 5: {
                cout << "Enter student ID: ";
                cin >> studentId;
                PrintAdvisor(studentId);
                break;
            }
            case 6: {
                cout << "Enter faculty ID: ";
                cin >> facultyId;
                PrintAdvisee(facultyId);
                break;
            }
            case 7: {
                AddStudent();
                rollbackStudent->push(studentBST);
                rollbackFaculty->push(facultyBST);
                break;
            }
            case 8: {
                cout << "Enter student ID: ";
                cin >> studentId;
                RemoveStudentSim(studentId);
                rollbackStudent->push(studentBST);
                rollbackFaculty->push(facultyBST);
                break;
            }
            case 9: {
                AddFaculty();
                rollbackStudent->push(studentBST);
                rollbackFaculty->push(facultyBST);
                break;
            }
            case 10: {
                cout << "Enter faculty ID: ";
                cin >> facultyId;
                RemoveFacultySim(facultyId);
                rollbackStudent->push(studentBST);
                rollbackFaculty->push(facultyBST);
                break;
            }
            case 11: {
                cout << "Enter student ID: ";
                cin >> studentId;
                cout << "Enter faculty ID: ";
                cin >> facultyId;
                ChangeAdvisor(studentId, facultyId);
                rollbackStudent->push(studentBST);
                rollbackFaculty->push(facultyBST);
                break;
            }
            case 12: {
                cout << "Enter faculty ID: ";
                cin >> facultyId;
                cout << "Enter student ID: ";
                cin >> studentId;
                RemoveAdvisee(facultyId, studentId);
                rollbackStudent->push(studentBST);
                rollbackFaculty->push(facultyBST);
                break;
            }
            case 13: {
                Rollback();
                cout << "Most recent version restored." << endl;
                break;
            }
            case 14: {
                ofstream out_file;
                out_file.open("studentTable.txt");
                //out_file << PrintAllStudents() << endl; // Use a for loop, need to use functions that return something
                out_file.close();
                ofstream out_file2;
                out_file2.open("facultyTable.txt");
                //out_file2 << PrintAllFaculty() << endl;  // Use a for loop, need to use functions that return something
                out_file2.close();
                cout << endl << "Data outputted to: studentTable.txt, facultyTable.txt" << endl;
                cout << "GOODBYE" << endl;
                exit(1);
            }
            default:
                cout << "INVALID OPTION" << endl;
                break;
        }
        cout << "Press *ENTER* to continue... " << endl;
        getchar();
    }
}

/*
Rollback()

Restores most previous
version of both BSTs from
before the most recent change
was made.

param: n/a
return: n/a
*/
void Simulation::Rollback() {
    rollbackStudent->pop();
    studentBST = rollbackStudent->topValue();
    rollbackStudent->pop();
    facultyBST = rollbackFaculty->topValue();
}

#endif
