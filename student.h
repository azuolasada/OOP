#pragma once
#include "Person.h"
#include <vector>
#include <sstream>

/**
 * @class Student
 * @brief Represents a student, extending the properties of Person.
 * 
 * This class holds information about a student's homework and exam results,
 * and calculates a final score based on these results.
 */
class Student : public Person {
private:
    std::vector<int> homeworkResults; ///< List of homework results.
    int examResult; ///< Result of the final exam.
    double finalScore; ///< Calculated final score.

public:
    /**
     * @brief Default constructor.
     * Initializes a new Student with empty names and zero scores.
     */
    Student() : Person("", ""), examResult(0), finalScore(0.0) {}

    /**
     * @brief Parameterized constructor.
     * @param name Name of the student.
     * @param surname Surname of the student.
     * @param homeworkResults List of integers representing homework results.
     * @param examResult Integer representing the exam result.
     */
    Student(const std::string& name, const std::string& surname, const std::vector<int>& homeworkResults, int examResult)
        : Person(name, surname), homeworkResults(homeworkResults), examResult(examResult), finalScore(0.0) {}

    /**
     * @brief Copy constructor.
     * @param other Reference to the Student object to be copied.
     */
    Student(const Student& other)
        : Person(other), homeworkResults(other.homeworkResults), examResult(other.examResult), finalScore(other.finalScore) {}

    /**
     * @brief Copy assignment operator.
     * @param other Reference to the Student object to be assigned.
     * @return Reference to the current Student object.
     */
    Student& operator=(const Student& other) {
        if (this != &other) {
            Person::operator=(other); // Call base class assignment operator
            homeworkResults = other.homeworkResults;
            examResult = other.examResult;
            finalScore = other.finalScore;
        }
        return *this;
    }

    /**
     * @brief Destructor.
     */
    ~Student() {}

    // Getters
    const std::vector<int>& getHomeworkResults() const { return homeworkResults; }
    int getExamResult() const { return examResult; }
    double getFinalScore() const { return finalScore; }

    // Setters
    void setHomeworkResults(const std::vector<int>& newHomeworkResults) { homeworkResults = newHomeworkResults; }
    void setExamResult(int newExamResult) { examResult = newExamResult; }
    void setFinalScore(double newFinalScore) { finalScore = newFinalScore; }

    /**
     * @brief Friend function to output Student details to an output stream.
     * @param os Reference to output stream.
     * @param student Constant reference to Student object.
     * @return Reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Student& student);

    /**
     * @brief Friend function to input Student details from an input stream.
     * @param is Reference to input stream.
     * @param student Reference to Student object.
     * @return Reference to the input stream.
     */
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
