#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>

class Student {
public:
    // Constructors
    Student() = default;
    Student(const std::string& name, const std::string& surname, int examResult)
        : name(name), surname(surname), examResult(examResult), finalScore(0.0) {}

    // Rule of Three
    ~Student() = default;
    Student(const Student& other) = default;
    Student& operator=(const Student& other) = default;

    // Public interface for accessing and modifying private data
    void setName(const std::string& newName) { name = newName; }
    std::string getName() const { return name; }

    void setSurname(const std::string& newSurname) { surname = newSurname; }
    std::string getSurname() const { return surname; }

    void setExamResult(int newExamResult) { examResult = newExamResult; }
    int getExamResult() const { return examResult; }

    void addHomeworkResult(int result) { homeworkResults.push_back(result); }
    const std::vector<int>& getHomeworkResults() const { return homeworkResults; }
    void removeLastHomeworkResult() { if (!homeworkResults.empty()) homeworkResults.pop_back(); }

    void setFinalScore(double newScore) { finalScore = newScore; }
    double getFinalScore() const { return finalScore; }

    // Input/Output operators
    friend std::istream& operator>>(std::istream& in, Student& student);
    friend std::ostream& operator<<(std::ostream& out, const Student& student);

private:
    std::string name;
    std::string surname;
    std::vector<int> homeworkResults;
    int examResult;
    double finalScore;
};

#endif // STUDENT_H
