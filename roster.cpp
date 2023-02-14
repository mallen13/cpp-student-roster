#include <iostream>
#include <regex>
#include <string>
#include "roster.h"

using namespace std;

//Constructor
Roster::Roster(string studentData[]) {
    for (int i = 0; i < 5; i++) {
        //parse student data and create Student object
        parseStudentData(studentData[i]);
    }
}

//Destructor
Roster::~Roster() {
    for (int i = 0; i < numStudents; i++) {
        if (classRosterArray[i]) {
            delete classRosterArray[i];
        }
    }
    
    cout << "Desctuctor Executed" << "\n \n";
}

//Parse student data and create Student object
void Roster::parseStudentData(string studentData) {
    //extract student info from parsed data
    string sID = studentData.substr(0, studentData.find(","));
    studentData = studentData.substr(studentData.find(",") + 1);

    string sFirst = studentData.substr(0, studentData.find(","));
    studentData = studentData.substr(studentData.find(",") + 1);

    string sLast = studentData.substr(0, studentData.find(","));
    studentData = studentData.substr(studentData.find(",") + 1);

    string sEmail = studentData.substr(0, studentData.find(","));
    studentData = studentData.substr(studentData.find(",") + 1);

    int sAge = stoi(studentData.substr(0, studentData.find(",")));

    int sDays[3];
    studentData = studentData.substr(studentData.find(",") + 1);
    sDays[0] = stoi(studentData.substr(0, studentData.find(",")));

    studentData = studentData.substr(studentData.find(",") + 1);
    sDays[1] = stoi(studentData.substr(0, studentData.find(",")));

    studentData = studentData.substr(studentData.find(",") + 1);
    sDays[2] = stoi(studentData.substr(0, studentData.find(",")));


    studentData = studentData.substr(studentData.find(",") + 1);
    string sDegreeString = studentData.substr(0, studentData.find(","));

    //convert degree string to DegreeProgram enum
    DegreeProgram sDegree;
    if (sDegreeString == "SECURITY") {
        sDegree = DegreeProgram::SECURITY;
    } else if (sDegreeString == "NETWORK") {
        sDegree = DegreeProgram::NETWORK;
    } else {
        sDegree = DegreeProgram::SOFTWARE;
    }

    //create student object and return
    add(sID,sFirst,sLast,sEmail,sAge,sDays[0],sDays[1],sDays[2],sDegree);

}
    
//Add Student
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
    
    //days into array
    int days[] = {daysInCourse1,daysInCourse2,daysInCourse3};
    //append array
    numStudents++;
    Student* student = new Student(studentID,firstName,lastName,emailAddress,age,days,degreeprogram);
    classRosterArray[numStudents-1] = student;
};
    
//Remove Student
void Roster::remove(string studentID) {
    bool found = false;
    for (int i = 0; i < numStudents; i++) {
        //if found student id 
        if (classRosterArray[i]->getStudentID() == studentID) {
            found = true;
            delete classRosterArray[i];
            
            // Shift the remaining elements in the array
            for (int j = i; j < numStudents-1; j++) {
                classRosterArray[j] = classRosterArray[j+1];
            }
            numStudents--;
            break;
        }
    }
    
    if (found) {
        cout << "Removed Student with ID " << studentID << "\n \n";
    } else {
        cout << "Student with ID " << studentID << " was not found" << "\n \n";
    }
}

//Print Every Student
void Roster::printAll() {
    for (int i = 0; i < numStudents; i++) {
        classRosterArray[i]->print();
    }
}
    
//Print Average Days In Course
void Roster::printAverageDaysInCourse(string studentID) {
    float avgDays = 0.00;
    int* daysToComplete = nullptr;
    
    //find student
    for (int i = 0; i < numStudents; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            //get days to complete the courses
            daysToComplete = classRosterArray[i]->getDaysToCompleteCourses();
            break;
        }
    }
    
    for (int i = 0; i < 3; i++) {
        avgDays += daysToComplete[i];
    }
    
    avgDays /= 3;
    
    //calculate average
    cout << "Avg Days in Course for " << studentID << ": " << avgDays << "\n";
}

    
//Verify Email
void Roster::printInvalidEmails() {
    bool invalidFound = false;
    cout << "\n";
    
    //loop through students and validate emails
    for (int i = 0; i < numStudents; i++) {
        string email = classRosterArray[i]->getEmailAddress();
        //check if valid against regex and no spaces
        regex emailRegex("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
        
        if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
            cout << "invalid email:" << email << "\n";
            invalidFound = true;
        };
    }
    
    //if no invalid
    if (!invalidFound) {
        cout << "No invalid emails found." << "\n";
    }
    cout << "\n";
}

//Print Degree Program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    
    cout << "\n";
    
    //that prints out student information for a degree program specified by an enumerated type.
    string program;
    
    if (degreeProgram == SOFTWARE) {
        program = "Software";
    } else if (degreeProgram == SECURITY) {
        program ="Security";
    } else {
        program = "Network";
    }
    
    cout << "Degree Program Enum Entered: " << program << "\n \n";
}
