// main class

#include "Student.h"
#include "Faculty.h"
#include "GeneralBST.h"
#include "Simulation.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Test if General class works
    /*
    General general1 = General("Ben van Zyll", "2345547", "Junior");
    General general2 = General();

    cout << general1.GetName() << endl;
    cout << general1.GetId() << endl;
    cout << general1.GetLevel() << endl;
    cout << general2.GetName() << endl;
    cout << general2.GetId() << endl;
    cout << general2.GetLevel() << endl;
    */

    // Test if Student class works
    /*
    Student student1 = Student("Ben van Zyll", "2345547", "Junior", "Data Science", "3.9", "7455432");
    Student student2 = Student();
    //student1.PrintStudent();
    //student2.PrintStudent();
    */

    // Test if Faculty class works
    /*
    Faculty faculty1 = Faculty("Rao Hamza Ali", "7455432", "Associate", "Engineering");
    Faculty faculty2 = Faculty();
    faculty1.AddStudent("2345547");
    faculty1.PrintFaculty();
    faculty2.PrintFaculty();
    */

    // Test if GeneralBST class works
    /*
    GeneralBST<Student> studentBST;
    GeneralBST<Faculty> facultyBST;

    studentBST.insert(new TreeNode<Student>("1", Student("Ben van Zyll", "1", "Junior", "Data Science", "3.9", "100")));
    studentBST.insert(new TreeNode<Student>("2", Student("Thomas Ogawa", "2", "Sophomore", "Computer Science", "4.0", "100")));
    studentBST.inOrder(studentBST.getRoot());

    facultyBST.insert(new TreeNode<Faculty>("100", Faculty("Rao Hamza Ali", "100", "Associate Professor", "Computer Science")));
    facultyBST.getRoot()->value.AddStudent("1");
    facultyBST.getRoot()->value.AddStudent("2");
    facultyBST.inOrder(facultyBST.getRoot());
    */
    

   // Test if Simulation class works
   // Constructor works :D
   // PrintAllStudents works (Prints in ascending order) :D
   // PrintAllFaculty works :D (Prints in ascending order)
   // SearchStudent works (with PrintInfo) :D
   // SearchFaculty works (with PrintInfo) :D
   // AddStudent works :D
   // RemoveStudentSim works :D
   // AddFaculty workds :D
   // RemoveFacultySim works :D
   // PrintAdvisor works :D
   // Print Advisee works :D
   /*GeneralBST<Student> studentBST;
   GeneralBST<Faculty> facultyBST;
   Simulation simulation(studentBST, facultyBST);
   simulation.facultyBST.insert(new TreeNode<Faculty>("200", Faculty("Jon Humphreys", "200", "Associate Professor", "Computer Science")));*/
   //simulation.studentBST.insert(new TreeNode<Student>("2", Student("Thomas Ogawa", "2", "Sophomore", "Computer Science", "4.0", "100")));
   /*simulation.AddFaculty();
   simulation.AddStudent();
   simulation.studentBST.find("1").SetAdvisor("200"); //SET ADVISOR DOES NOT WORK
   cout << simulation.studentBST.find("1").GetAdvisorId() << endl << endl;*/
   //simulation.facultyBST.getRoot()->value.AddStudent("1");
   //simulation.facultyBST.getRoot()->value.AddStudent("2");
   //simulation.studentBST.inOrder(simulation.studentBST.getRoot());
   //simulation.facultyBST.inOrder(simulation.facultyBST.getRoot());
   //simulation.PrintAllStudents();
   //simulation.PrintAllFaculty();
   //simulation.SearchStudent("1").PrintInfo();
   //simulation.SearchStudent("100").PrintInfo();
   //simulation.SearchStudent("2").PrintInfo();
   //simulation.SearchFaculty("100").PrintInfo();
   //simulation.SearchFaculty("1").PrintInfo();
   //simulation.RemoveStudentSim("1");
   //simulation.PrintAllStudents();
   //simulation.PrintAllFaculty();
   //simulation.PrintAdvisor("2");
   //simulation.PrintAdvisee("100");
   /*simulation.ChangeAdvisor("1", "200");
   simulation.PrintAllStudents();
   simulation.PrintAdvisor("1");
   simulation.PrintAllFaculty();*/

    Simulation simulation;
    simulation.Simulate();
   


    return 0;
}