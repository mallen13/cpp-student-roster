#include <iostream>
#include <string>
#include "degree.h"

using namespace std;

class Student {
    private:
        //Attributes
        string studentID;
        string firstName;
        string lastName;
        string emailAddress;
        int age;
        int daysToCompleteCourses[3];
        DegreeProgram degreeProgram;
        
    public:
        //Constructor
        Student(string studentID,string firstName,string lastName,string emailAddress,int age,int daysToCompleteCourses[3],DegreeProgram degreeProgram);
        
        //Setter Functions to mutate
        void setStudentID(string studentID);
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setEmailAddress(string emailAddress);
        void setAge(int age);
        void setDaysToCompleteCourses(int daysInCourses[3]);
        void setDegreeProgram(DegreeProgram degreeProgram);
    
        //Getter functions to access
        string getStudentID();
        string getFirstName();
        string getLastName();
        string getEmailAddress();
        int getAge();
        int* getDaysToCompleteCourses();
        string getDegreeProgram();

        // Print the data
        void print();
};
