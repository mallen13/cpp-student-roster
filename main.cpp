#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main() {
    
    cout << "Scripting and Programming Applications (C867)" << "\n";
    cout << "C++" << "\n";
    cout << "Matthew Allen - 010945885" << "\n \n";
    
    
    //List of Students
    string studentData[] = {
        "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Matthew,Allen,mall671@wgu.edu,32,10,25,20,SOFTWARE"
    };
    
    //Initialize Class
    Roster classRoster(studentData);
    
    //Print All Students
    classRoster.printAll();
 
    //Print Invalid Email Addresses
    classRoster.printInvalidEmails();
    
    //Get Each Student's Average Time in Class
    for (int i = 0; i < classRoster.numStudents; i++) {
        //get student id
        string studentID = classRoster.classRosterArray[i]->getStudentID();
        
        //print days in courses
        classRoster.printAverageDaysInCourse(studentID);
    }
    
    //Print Degree Program for Enum
    classRoster.printByDegreeProgram(SECURITY);
    
    //Remove Student
    classRoster.remove("A3");
    
    //Print All Students
    classRoster.printAll();
    
    //Attempt Remove Student
    cout << "\n";
    classRoster.remove("A3");
        //should return "Student with this ID was not found."
    
    return 0;
}

