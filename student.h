#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"

class Student {
public:
    Student(std::string studentID, std::string firstName, std::string lastName,
        std::string emailAddress, int age, int daysInCourses[], DegreeProgram degreeProgram);
    ~Student();

    std::string getStudentID() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getEmailAddress() const;
    int getAge() const;
    const int* getDaysToCompleteCourses() const;
    DegreeProgram getDegreeProgram() const;
    // mutators added student id
    void setStudentID(const std::string& studentID);
    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setEmailAddress(const std::string& emailAddress);
    void setAge(int age);
    void setDaysToCompleteCourses(int days[3]);
    void setDegreeProgram(DegreeProgram degreeProgram);


    void print() const;

private:
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    int daysToCompleteCourses[3];
    DegreeProgram degreeProgram;
};

#endif 

