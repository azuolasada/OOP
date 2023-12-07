#include "student.h"

// Member functions that require custom implementation
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

// Input and Output operators
std::ostream& operator<<(std::ostream& os, const Student& student) {
    // Implement the output operator based on your requirements
    // Example:
    os << student.getName() << ", " << student.getSurname() << ", Final Score: " << student.getFinalScore();
    return os;
}

std::istream& operator>>(std::istream& is, Student& student) {
    // Implement the input operator based on your requirements
    // Example:
    std::string name, surname;
    int examResult;
    is >> name >> surname >> examResult;
    student.setName(name);
    student.setSurname(surname);
    student.setExamResult(examResult);
    return is;
}
