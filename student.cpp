#include "student.h"

// Default constructor
Student::Student() : examResult(0), finalScore(0.0) {}

// Parameterized constructor
Student::Student(const std::string& name, const std::string& surname, int examResult)
    : name(name), surname(surname), examResult(examResult), finalScore(0.0) {}

// Copy constructor
Student::Student(const Student& other)
    : name(other.name), surname(other.surname), homeworkResults(other.homeworkResults),
      examResult(other.examResult), finalScore(other.finalScore) {}

// Destructor
Student::~Student() {}

// Copy assignment operator
Student& Student::operator=(const Student& other) {
    if (this != &other) {
        name = other.name;
        surname = other.surname;
        homeworkResults = other.homeworkResults;
        examResult = other.examResult;
        finalScore = other.finalScore;
    }
    return *this;
}

// Setters and Getters
void Student::setName(const std::string& newName) {
    name = newName;
}

std::string Student::getName() const {
    return name;
}

void Student::setSurname(const std::string& newSurname) {
    surname = newSurname;
}

std::string Student::getSurname() const {
    return surname;
}

void Student::setExamResult(int newExamResult) {
    examResult = newExamResult;
}

int Student::getExamResult() const {
    return examResult;
}

void Student::addHomeworkResult(int result) {
    homeworkResults.push_back(result);
}

const std::vector<int>& Student::getHomeworkResults() const {
    return homeworkResults;
}

// Function to remove the last homework result (typically an exam result)
void Student::removeLastHomeworkResult() {
    if (!homeworkResults.empty()) {
        homeworkResults.pop_back();
    }
}

// Set and Get final score
void Student::setFinalScore(double newScore) {
    finalScore = newScore;
}

double Student::getFinalScore() const {
    return finalScore;
}
