#include <string>
#include <vector>
#include <iostream>

class Student {
public:
    // Constructors
    Student();
    Student(const std::string& name, const std::string& surname, int examResult);
    // Copy constructor
    Student(const Student& other);
    // Destructor
    ~Student();
    // Copy assignment operator
    Student& operator=(const Student& other);

    // Public interface for accessing and modifying private data
    void setName(const std::string& newName);
    std::string getName() const;

    void setSurname(const std::string& newSurname);
    std::string getSurname() const;

    void setExamResult(int newExamResult);
    int getExamResult() const;

    void addHomeworkResult(int result);
    const std::vector<int>& getHomeworkResults() const;
    void removeLastHomeworkResult();

    void setFinalScore(double newScore);
    double getFinalScore() const;

    // Friend functions for input/output operators
    friend std::ostream& operator<<(std::ostream& os, const Student& student);
    friend std::istream& operator>>(std::istream& is, Student& student);

private:
    std::string name;
    std::string surname;
    std::vector<int> homeworkResults;
    int examResult;
    double finalScore;
};