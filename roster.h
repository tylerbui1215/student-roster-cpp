#ifndef ROSTER_H
#define ROSTER_H

#include <vector>
#include <iostream>
#include <string>
#include "student.h"

class Roster {
public:
    Roster();
    ~Roster();

    void add(std::string studentID, std::string firstName, std::string lastName,
        std::string emailAddress, int age, int daysInCourse1, int daysInCourse2,
        int daysInCourse3, DegreeProgram degreeProgram);
    void remove(const std::string& studentID);
    void printAll() const;
    void printAverageDaysInCourse(const std::string& studentID) const;
    void printInvalidEmails() const;
    void printByDegreeProgram(DegreeProgram degreeProgram) const;
    void parseThenAdd(const std::string& studentData);
    const Student* getStudent(int index) const;
    int getCurrentSize() const;

private:
    std::vector<Student> students;
};

#endif 