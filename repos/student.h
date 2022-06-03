#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;
//using std::endl;

class Student {
public:
    const static int courseArraySize = 3;
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInCourse[courseArraySize];
    DegreeProgram degreeProgram;

public:
    Student(); //constructor, sets default values
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram); //full constructor
    ~Student(); //destructor

    // getters
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getDaysInCourse();
    DegreeProgram getDegreeProgram();

    // setters
    void setStudentID(string ID);
    void setFirstName(string fName);
    void setLastName(string lName);
    void setEmailAddress(string email);
    void setAge(int age);
    void setDaysInCourse(int daysInCourse[courseArraySize]);
    void setDegreeProgram(DegreeProgram degree);

    static void printHeader(); //displays a header for the data to follow

    void print(); //displays 'this' student's data




};

