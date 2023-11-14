#include <string>
#include <vector>

class Student {
public:
    // Constructors
    Student() = default;
    Student(const std::string& name, const std::string& surname, int examResult)
        : name(name), surname(surname), examResult(examResult) {}

    // Public interface for accessing and modifying private data
    void setName(const std::string& newName) { name = newName; }
    std::string getName() const { return name; }

    void setSurname(const std::string& newSurname) { surname = newSurname; }
    std::string getSurname() const { return surname; }

    void setExamResult(int newExamResult) { examResult = newExamResult; }
    int getExamResult() const { return examResult; }

    void addHomeworkResult(int result) { homeworkResults.push_back(result); }
    const std::vector<int>& getHomeworkResults() const { return homeworkResults; }

    void setFinalScore(double newScore) { finalScore = newScore; }
    double getFinalScore() const { return finalScore; }

private:
    std::string name;
    std::string surname;
    std::vector<int> homeworkResults;
    int examResult;
    double finalScore;
};
