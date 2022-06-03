#include <string>
#include "roster.h"
using std::string;
using std::stoi;
void Roster::parse(string studentData) //parses each row-one at a time
{

    int rhs = studentData.find(","); // find the comma
    string sID = studentData.substr(0, rhs); //extract substring in front of the comma

    //FIRST NAME
    int lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string fna = studentData.substr(lhs, rhs - lhs);

    //LAST NAME
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string lna = studentData.substr(lhs, rhs - lhs);

    //EMAIL ADDRESS
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string ema = studentData.substr(lhs, rhs - lhs);

    //AGE
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int age = stoi(studentData.substr(lhs, rhs - lhs));

    //DAYS IN COURSE
    lhs = rhs + 1;  //days in course 1
    rhs = studentData.find(",", lhs);
    int dic1 = stoi(studentData.substr(lhs, rhs - lhs));
    lhs = rhs + 1; //days in course 2
    rhs = studentData.find(",", lhs);
    int dic2 = stoi(studentData.substr(lhs, rhs - lhs));
    lhs = rhs + 1; //days in course 3
    rhs = studentData.find(",", lhs);
    int dic3 = stoi(studentData.substr(lhs, rhs - lhs));

    DegreeProgram dp = SOFTWARE;
    if (studentData.back() == 'K')
    {
        dp = NETWORK;
    }
    if (studentData.back() == 'Y')
    {
        dp = SECURITY;
    }


    add(sID, fna, lna, ema, age, dic1, dic2, dic3, dp);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int dic1, int dic2, int dic3, DegreeProgram degreeProgram)
{
    //put prices back into array
    int parr[3] = { dic1, dic2, dic3 };
    //Make sew student object -- lastIndex starts with -1 not 0
    studentRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, parr, degreeProgram);
}

//Displays all students using tab-seperated output
void Roster::printAll()
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        studentRosterArray[i]->print();
    }
}

void Roster::printByDegreeProgram(DegreeProgram dp)
{
    Student::printHeader();
    for (int i = 0; i <= lastIndex; i++) {
        if (Roster::studentRosterArray[i]->getDegreeProgram() == dp) studentRosterArray[i]->print();
    }
    cout << std::endl;
}

//Each email must contain an @ and no spaces
void Roster::printInvalidEmails() 
{
    bool any = false;
    for (int i = 0; i <= lastIndex; i++)
    {
        string emailAddress = (studentRosterArray[i]->getEmailAddress());
        if (emailAddress.find(' ') != string::npos || emailAddress.find('@') == string::npos || emailAddress.find('.') == string::npos)
        {
            any = true;
            cout << emailAddress << ": " << studentRosterArray[i]->getFirstName() << std::endl;
        }
    }
    if (!any) cout << "NONE" << std::endl;
}

void Roster::printAverageDaysInCourse(string ID)
{
    for (int i = 0; i <= lastIndex; i++)
    {
        if (ID == studentRosterArray[i]->getStudentID())
        {
            cout << studentRosterArray[i]->getStudentID() << ": ";
            cout << (studentRosterArray[i]->getDaysInCourse()[0]
                + studentRosterArray[i]->getDaysInCourse()[1]
                + studentRosterArray[i]->getDaysInCourse()[2]) / 3.0;
        }
    }
    cout << std::endl;
}

void Roster::remove(string studentID) //student to remove comes in as a parameter
{
    bool success = false; // assume its not here
    for (int i = 0; i <= lastIndex; i++)
    {
        if (studentRosterArray[i]->getStudentID() == studentID)
        {
            success = true;
            if (i < numStudents - 1)
            {
                Student* temp = studentRosterArray[i]; // swap with last student
                studentRosterArray[i] = studentRosterArray[numStudents - 1];
                studentRosterArray[numStudents - 1] = temp;
            }
            lastIndex--; //last student no longer visible
            
        }
    }
    if (success)
    {
        cout << studentID << " removed from roster." << std::endl << std::endl;
        this->printAll();//displays students, removed one should not show

    }
    else cout << studentID << " not found." << std::endl << std::endl;
}

Roster::~Roster()
{
    cout << "DESTRUCTOR CALLED!!!" << std::endl << std::endl;
    for (int i = 0; i < numStudents; i++)
    {
        cout << "Destroying student #" << i + 1 << std::endl;
        delete studentRosterArray[i];
        studentRosterArray[i] = nullptr;
    }
}