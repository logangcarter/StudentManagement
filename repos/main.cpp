#include "roster.h"
//using std::ednl;
int main()
{
    cout << "Scripting and Programming - Applications - C867" << std::endl;
    cout << "Project written in C++" << std::endl;
    cout << "Logan Carter -- lcar115" << std::endl << std::endl;


    //LONG STRINGS TO PARSE
    const string studentData[] =

    { 
     "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
     "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
     "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
     "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
     "A5,Logan,Carter,Logangcarter@gmail.com,24,25,35,45,SOFTWARE"
    };

    const int numStudents = 5;
    Roster roster; //creates repo using default parameterless constructor

    for (int i = 0; i < numStudents; i++) roster.parse(studentData[i]);
    cout << "Displaying all students: " << std::endl;
    roster.printAll();
    cout << std::endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "Displaying by degree program: " << degreeProgramStrings[i] << std::endl;
        roster.printByDegreeProgram((DegreeProgram)i); // cast the integer to a degree
    }

    cout << "Displaying students with invalid emails" << std::endl;
    roster.printInvalidEmails();
    cout << std::endl;

    cout << "Displaying average days in course for student with ID A1: " << std::endl;
    roster.printAverageDaysInCourse("A1");
    cout << std::endl;

    cout << "Removing student with ID A3: " << std::endl;
    roster.remove("A3");
    cout << std::endl;

    system("pause");
    return 0;
}
