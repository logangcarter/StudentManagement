#pragma once
#include "student.h"
class Roster
{
private:
    int lastIndex = -1;
    const static int numStudents = 5;
    

public:
    Student* studentRosterArray[numStudents];
    //Repo has no constructor; or does it?
    //the parse method goes through a set of comma delimited strings and extracts student data
    void parse(string row);
    //all data is then passes into add method which creats the Student object
    void add(string sID,
        string fName,
        string lName,
        string email,
        int age,
        int days1,
        int days2,
        int days3,
        DegreeProgram dp);
    void remove(string studentID); //Find the student by id and remove
    void printAll(); //calls print() method in 
    void printAverageDaysInCourse(string ID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram dp); //degree program is passed in
    ~Roster();
};

