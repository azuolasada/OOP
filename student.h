#pragma once
#include <string>
#include <vector>
#include <iostream>

class Student {
public:
    // Default constructor
    Student() = default; // Use the compiler-generated default constructor

    // Parameterized constructor
    Student(const std::string& name, const std::string& surname, int examResult);

    // Copy constructor
    Student(const Student& other) = default; // Use the compiler-generated copy constructor

    // Destructor
    ~Student() = default; // Use the compiler-generated destructor

    // Copy assignment operator
    Student& operator=(const Student& other) = default; // Use the compiler-generated copy assignment operator

    // Public methods to set and get student's details
    void setName(const std::string& newName);
    std::string getName() const;

    void setSurname(const std::string& newSurname);
    std::string getSurname() const;

    void setExamResult(int newExamResult);
    int getExamResult() const;

    // Method to add a homework result
    void addHomeworkResult(int result);

    // Method to get all homework results
    const std::vector<int>& getHomeworkResults() const;

    // Method to remove the last homework result (assuming it's the exam result)
    void removeLastHomeworkResult();

    // Method to set and get the final score
    void setFinalScore(double newScore);
    double getFinalScore() const;

    // Friend declarations for input/output operators
    friend std::ostream& operator<<(std::ostream& os, const Student& student);
    friend std::istream& operator>>(std::istream& is, Student& student);

private:
    // Member variables
    std::string name; // Student's name
    std::string surname; // Student's surname
    std::vector<int> homeworkResults; // Container for homework results
    int examResult; // Exam result
    double finalScore; // Final calculated score
};
