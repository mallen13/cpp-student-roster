#include <iostream>
#include <string>
#include "student.h"

using namespace std;


class Roster {  
    public:
    int numStudents = 0;
    Student* classRosterArray[5];
    
    //Constructor
    Roster(string studentData[]);
    
    //Desctuctor
    ~Roster();

    //Parse student data and create Student object
    void parseStudentData(string studentData);
    
    //Add Student
    void add(
         string studentID,
         string firstName,
         string lastName,
         string emailAddress,
         int age,
         int daysInCourse1,
         int daysInCourse2,
         int daysInCourse3,
         DegreeProgram degreeprogram
    );
    
    //Remove Student
    void remove(string studentID);

    
    //Print Every Student
    void printAll();
    
    //Print Average Days In Course
    void printAverageDaysInCourse(string studentID);
    
    //Verify Email
    void printInvalidEmails();
    
    //Print Degree Program
    void printByDegreeProgram(DegreeProgram degreeProgram);
};
