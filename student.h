#pragma once
#include "Person.h"
#include <vector>
#include <sstream>

class Student : public Person {
private:
    std::vector<int> homeworkResults;
    int examResult;
    double finalScore;

public:
    // Default constructor
    Student() : Person("", ""), examResult(0), finalScore(0.0) {}

    // Parameterized constructor
    Student(const std::string& name, const std::string& surname, const std::vector<int>& homeworkResults, int examResult)
        : Person(name, surname), homeworkResults(homeworkResults), examResult(examResult), finalScore(0.0) {}

    // Copy constructor
    Student(const Student& other)
        : Person(other), homeworkResults(other.homeworkResults), examResult(other.examResult), finalScore(other.finalScore) {}

    // Copy assignment operator
    Student& operator=(const Student& other) {
        if (this != &other) {
            Person::operator=(other); // Call base class assignment operator
            homeworkResults = other.homeworkResults;
            examResult = other.examResult;
            finalScore = other.finalScore;
        }
        return *this;
    }

    // Destructor
    ~Student() {}

    // Getters
    const std::vector<int>& getHomeworkResults() const { return homeworkResults; }
    int getExamResult() const { return examResult; }
    double getFinalScore() const { return finalScore; }

    // Setters
    void setHomeworkResults(const std::vector<int>& newHomeworkResults) { homeworkResults = newHomeworkResults; }
    void setExamResult(int newExamResult) { examResult = newExamResult; }
    void setFinalScore(double newFinalScore) { finalScore = newFinalScore; }

    // Friend declarations for input and output operators
    friend std::ostream& operator<<(std::ostream& os, const Student& student);
    friend std::istream& operator>>(std::istream& is, Student& student);
};

// Inline output operator
inline std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << student.getName() << ", " << student.getSurname();
    for (const auto& hw : student.getHomeworkResults()) {
        os << ", " << hw;
    }
    os << ", " << student.getExamResult();
    return os;
}

// Inline input operator
inline std::istream& operator>>(std::istream& is, Student& student) {
    std::string line;
    if (std::getline(is, line)) {
        std::istringstream iss(line);
        std::string token;
        std::getline(iss, token, ',');
        student.setName(token);
        std::getline(iss, token, ',');
        student.setSurname(token);

        std::vector<int> homeworkResults;
        while (std::getline(iss, token, ',')) {
            if (iss.peek() == '\n' || iss.peek() == EOF) {
                student.setExamResult(std::stoi(token));
                break;
            } else {
                homeworkResults.push_back(std::stoi(token));
            }
        }
        student.setHomeworkResults(homeworkResults);
    }
    return is;
}
