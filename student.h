#pragma once
#include <string>
#include <vector>

class Student {
private:
    std::string name;
    std::string surname;
    std::vector<int> homeworkResults;
    int examResult;
    double finalScore;

public:
    // Default constructor
    Student() : examResult(0), finalScore(0.0) {}

    // Parameterized constructor
    Student(const std::string& name, const std::string& surname, const std::vector<int>& homeworkResults, int examResult)
        : name(name), surname(surname), homeworkResults(homeworkResults), examResult(examResult) {}

    // Getters
    const std::string& getName() const { return name; }
    const std::string& getSurname() const { return surname; }
    const std::vector<int>& getHomeworkResults() const { return homeworkResults; }
    int getExamResult() const { return examResult; }
    double getFinalScore() const { return finalScore; }

    // Setters
    void setName(const std::string& name) { this->name = name; }
    void setSurname(const std::string& surname) { this->surname = surname; }
    void setHomeworkResults(const std::vector<int>& homeworkResults) { this->homeworkResults = homeworkResults; }
    void setExamResult(int examResult) { this->examResult = examResult; }
    void setFinalScore(double finalScore) { this->finalScore = finalScore; }
};
