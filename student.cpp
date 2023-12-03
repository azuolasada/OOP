#include "student.h"

// Implement constructors
Student::Student() : examResult(0), finalScore(0.0) {}

Student::Student(const std::string& name, const std::string& surname, int examResult)
    : name(name), surname(surname), examResult(examResult), finalScore(0.0) {}

// Implement the "Rule of Three"
Student::Student(const Student& other) 
    : name(other.name), surname(other.surname), homeworkResults(other.homeworkResults),
      examResult(other.examResult), finalScore(other.finalScore) {}

Student::~Student() {}

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

// Implement other member functions
void Student::removeLastHomeworkResult() {
    if (!homeworkResults.empty()) {
        homeworkResults.pop_back();
    }
}

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

void Student::setFinalScore(double newScore) {
    finalScore = newScore;
}

double Student::getFinalScore() const {
    return finalScore;
}