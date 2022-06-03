#include "student.h"

// constructor
Student::Student()
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    for (int i = 0; i < courseArraySize; ++i) this->daysInCourse[i] = 0;
    this->degreeProgram = SOFTWARE;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < courseArraySize; ++i) this->daysInCourse[i] = daysInCourse[i];
    this->degreeProgram = degreeProgram;

}

Student::~Student() {} //destructor does nothing

//Getter functions
string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmailAddress() { return this->emailAddress; }
int Student::getAge() { return this->age; }
int* Student::getDaysInCourse() { return this->daysInCourse; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

// Setter Functions
void Student::setStudentID(string ID) { this->studentID = ID; }
void Student::setFirstName(string fName) { this->firstName = fName; }
void Student::setLastName(string lName) { this->lastName = lName; }
void Student::setEmailAddress(string email) { this->emailAddress = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysInCourse(int days[courseArraySize])
{
    for (int i = 0; i < courseArraySize; ++i) this->daysInCourse[i] = days[i];
}
void Student::setDegreeProgram(DegreeProgram degree) { this->degreeProgram = degree; }

void Student::printHeader()
{
    cout << "Output format ID|First Name|Last Name|Email Address|Age|Days in Course|Degree Program\n";
}

void Student::print()
{
    cout << this->getStudentID() << '\t';
    cout << this->getFirstName() << '\t';
    cout << this->getLastName() << '\t';
    cout << this->getEmailAddress() << '\t';
    cout << this->getAge() << '\t';
    cout << this->getDaysInCourse()[0] << '\t';
    cout << this->getDaysInCourse()[1] << '\t';
    cout << this->getDaysInCourse()[2] << '\t';
    cout << degreeProgramStrings[this->getDegreeProgram()] << '\n'; //degreeprogram to string
}

