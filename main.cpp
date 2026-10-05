#include "roster.h"
#include <iostream>

int main() {
    std::cout << "Student Roster Manager" << std::endl;
    std::cout << "Programming Language: C++" << std::endl;  

    const std::string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Tyler,Bui,tylerbui1215@gmail.com,20,30,30,30,SOFTWARE"
    };

    Roster classRoster;


    for (const std::string& data : studentData) {
        classRoster.parseThenAdd(data);
    }

    classRoster.printAll();
    classRoster.printInvalidEmails();


    for (int i = 0; i < classRoster.getCurrentSize(); ++i) {
        classRoster.printAverageDaysInCourse(classRoster.getStudent(i)->getStudentID());
    }

    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");

    return 0;
}