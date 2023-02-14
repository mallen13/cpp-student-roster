#include <iostream>
#include <string>
#include "student.h"

using namespace std;

//Constructor Definition
Student::Student(
            string studentID,
            string firstName,
            string lastName,
            string emailAddress,
            int age,
            int daysToCompleteCourses[3],
            DegreeProgram degreeProgram
        ) {
            this->studentID = studentID;
            this->firstName = firstName;
            this->lastName = lastName;
            this->emailAddress = emailAddress;
            this->age = age;
            for (int i = 0; i < 3; i++) {
                this->daysToCompleteCourses[i] = daysToCompleteCourses[i];
            }
            this->degreeProgram = degreeProgram;
        }
        
//Setter Function Definitions
void Student::setStudentID(string studentID) {
    this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(string lastName) {
    this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress) {
    this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setDaysToCompleteCourses(int daysInCourses[3]) {
    for (int i = 0; i < 3; i++) {
        this->daysToCompleteCourses[i] = daysToCompleteCourses[i];
    }
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}

//Getter functions Definitions
string Student::getStudentID() {
    return this->studentID;
}

string Student::getFirstName() {
    return this->firstName;
}

string Student::getLastName() {
    return this->lastName;
}

string Student::getEmailAddress() {
    return this->emailAddress;
}

int Student::getAge() {
    return this->age;
}

int* Student::getDaysToCompleteCourses() {
    return (int*) daysToCompleteCourses;
}

string Student::getDegreeProgram() {
    string program;
    
    if (this->degreeProgram == SOFTWARE) {
        program = "Software";
    } else if (this->degreeProgram == SECURITY) {
        program ="Security";
    } else {
        program = "Network";
    }
    return program;
}

// Print the data
void Student::print() {
    cout << "Student ID: " << studentID << "\t";
    cout << "Name: " << firstName << " " << lastName << "\t";
    cout << "Email: " << emailAddress << "\t";
    cout << "Age: " << age << "\t";
    cout << "Days in class: " << daysToCompleteCourses[0] << ", " << daysToCompleteCourses[1] << ", " << daysToCompleteCourses[2] << "\t";
    cout << "Degree program: " << getDegreeProgram() << "\n";
}
