#include "roster.h"
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include "student.h"
#include <algorithm>
Roster::Roster() {}

Roster::~Roster() {}


void Roster::add(std::string studentID, std::string firstName, std::string lastName,
	std::string emailAddress, int age, int daysInCourse1, int daysInCourse2,
	int daysInCourse3, DegreeProgram degreeProgram) {
	int days[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	students.emplace_back(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);
}

void Roster::remove(const std::string& studentID) {
	for (size_t i = 0; i < students.size(); ++i) {
		if (students[i].getStudentID() == studentID) {
			students.erase(students.begin() + i);
			std::cout << "Student with ID " << studentID << " has been removed." << std::endl;
			return;
		}
	}
	std::cout << "Error: Student with ID " << studentID << " not found." << std::endl;
}

void Roster::printAll() const {
	std::cout << "Class Roster" << std::endl;
	for (int i = 0; i < students.size(); ++i) {
		students[i].print();
	}
}

void Roster::printAverageDaysInCourse(const std::string& studentID) const {

	for (int i = 0; i < students.size(); ++i) {
		if (students[i].getStudentID() == studentID) {
			const int* days = students[i].getDaysToCompleteCourses();
			double average = (days[0] + days[1] + days[2]) / 3.0;
			std::cout << "Average days in courses for student ID " << studentID << ": " << average << std::endl;
			return;
		}
	}
	std::cout << "Error: Student with ID " << studentID << " not found." << std::endl;
}

static bool isValidEmail(const std::string& email) {
	if (email.find(' ') != std::string::npos) return false;
	if (std::count(email.begin(), email.end(), '@') != 1) return false;

	size_t at = email.find('@');
	if (at == 0) return false;                                     

	size_t dot = email.find('.', at);
	if (dot == std::string::npos) return false;
	if (dot == at + 1) return false;                    
	if (dot == email.size() - 1) return false;
	return true;
}
void Roster::printInvalidEmails() const {
	for (const Student& s : students) {
		std::string email = s.getEmailAddress();
		if (!isValidEmail(email)) {
			std::cout << "Invalid email: " << email << std::endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
	std::cout << "Students in the " << degreeProgramMapping[degreeProgram] << " program:" << std::endl;
	for (int i = 0; i < students.size(); ++i) {
		if (students[i].getDegreeProgram() == degreeProgram) {
			students[i].print();
		}
	}
}

void Roster::parseThenAdd(const std::string& studentData) {
	std::istringstream ss(studentData);
	std::string token;
	std::getline(ss, token, ',');
	std::string studentID = token;
	std::getline(ss, token, ',');
	std::string firstName = token;
	std::getline(ss, token, ',');
	std::string lastName = token;
	std::getline(ss, token, ',');
	std::string emailAddress = token;

	int age = 0;
	int daysInCourse1 = 0;
	int daysInCourse2 = 0;
	int daysInCourse3 = 0;

	try {
		std::getline(ss, token, ',');
		age = std::stoi(token);
		std::getline(ss, token, ',');
		daysInCourse1 = std::stoi(token);
		std::getline(ss, token, ',');
		daysInCourse2 = std::stoi(token);
		std::getline(ss, token, ',');
		daysInCourse3 = std::stoi(token);
	}
	catch (const std::exception& e) {
		std::cerr << "Error: bad number in record: " << studentData << std::endl;
		return;
	}

	std::getline(ss, token, ',');
	DegreeProgram degreeProgram;


	static const std::map<std::string, DegreeProgram> degreeMap = {
		{"SECURITY", SECURITY},
		{"NETWORK", NETWORK},
		{"SOFTWARE", SOFTWARE}
	};

	auto it = degreeMap.find(token);
	if (it != degreeMap.end()) {
		degreeProgram = it->second;
	}
	else {
		std::cerr << "Error: Invalid degree program." << std::endl;
		return;
	}

	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

const Student* Roster::getStudent(int index) const {
	if (index >= 0 && index < static_cast<int>(students.size())) {
		return &students[index];
	}
	return nullptr;
}

int Roster::getCurrentSize() const {
	return static_cast<int>(students.size());
}