#include "student.h"
#include <iostream>
#include "degree.h"
Student::Student(std::string studentID, std::string firstName, std::string lastName,
    std::string emailAddress, int age, int daysInCourses[], DegreeProgram degreeProgram)
    : studentID(studentID), firstName(firstName), lastName(lastName),
    emailAddress(emailAddress), age(age), degreeProgram(degreeProgram) {
    for (int i = 0; i < 3; ++i) {
        daysToCompleteCourses[i] = daysInCourses[i];
    }
}

Student::~Student() {}

std::string Student::getStudentID() const {
    return studentID;
}

std::string Student::getFirstName() const {
    return firstName;
}

std::string Student::getLastName() const {
    return lastName;
}

std::string Student::getEmailAddress() const {
    return emailAddress;
}

int Student::getAge() const {
    return age;
}

const int* Student::getDaysToCompleteCourses() const {
    return daysToCompleteCourses;
}

DegreeProgram Student::getDegreeProgram() const {
    return degreeProgram;
}

void Student::setStudentID(const std::string& studentID) {
    this->studentID = studentID;
}

void Student::setFirstName(const std::string& firstName) {
    this->firstName = firstName;
}

void Student::setLastName(const std::string& lastName) {
    this->lastName = lastName;
}

void Student::setEmailAddress(const std::string& emailAddress) {
    this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setDaysToCompleteCourses(int days[3]) {
    for (int i = 0; i < 3; ++i) {
        this->daysToCompleteCourses[i] = days[i];
    }
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}

void Student::print() const {
    std::cout << studentID << "    First Name: " << firstName
        << "    Last Name: " << lastName << "    " << emailAddress
        << "    Age: " << age << "  Days in Courses: {" << daysToCompleteCourses[0]
        << "," << daysToCompleteCourses[1] << "," << daysToCompleteCourses[2]
        << "}   Degree Program: " << degreeProgramMapping[degreeProgram] << std::endl;
}