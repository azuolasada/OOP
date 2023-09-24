#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
#include <algorithm>
#include <sstream>

struct Student {
    std::string name;
    std::string surname;
    std::vector<int> homeworkResults;
    int examResult;
};

double computeMean(const std::vector<int>& results) {
    return std::accumulate(results.begin(), results.end(), 0.0) / results.size();
}

double computeMedian(const std::vector<int>& results) {
    size_t size = results.size();
    std::vector<int> sortedResults = results;
    std::sort(sortedResults.begin(), sortedResults.end());

    if (size % 2 == 0) {
        return (sortedResults[size / 2 - 1] + sortedResults[size / 2]) / 2.0;
    } else {
        return sortedResults[size / 2];
    }
}

void printDataFrameHeader() {
    std::cout << std::left << std::setw(15) << "Name"
              << std::setw(15) << "Surname"
              << std::setw(15) << "Final Score"
              << std::endl;
    std::cout << std::string(45, '-') << std::endl;
}

int main() {
    int numStudents;
    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;
    std::cin.ignore(); // to consume newline left after reading numStudents

    std::vector<Student> students;
    char calculationMethod;

    std::cout << "Choose calculation method (m for mean, d for median): ";
    std::cin >> calculationMethod;
    std::cin.ignore();

    for (int i = 0; i < numStudents; ++i) {
        Student student;

        std::cout << "Enter name for student " << (i + 1) << ": ";
        std::getline(std::cin, student.name);

        std::cout << "Enter surname for student " << (i + 1) << ": ";
        std::getline(std::cin, student.surname);

        std::cout << "Enter homework results for student " << (i + 1) << " (press Enter twice to stop):\n";
        while (true) {
            std::string line;
            std::getline(std::cin, line);
            if (line.empty()) {
                break; // Exit the loop when two ENTERs are pressed
            }
            std::istringstream iss(line);
            int result;
            iss >> result;
            student.homeworkResults.push_back(result);
        }

        std::cout << "Enter exam result for student " << (i + 1) << ": ";
        std::cin >> student.examResult;
        std::cin.ignore();

        students.push_back(student);
    }

    printDataFrameHeader();
    for (const auto &student : students) {
        double homeworkScore = (calculationMethod == 'm' ? 
            computeMean(student.homeworkResults) : computeMedian(student.homeworkResults));
        double finalScore = 0.4 * homeworkScore + 0.6 * student.examResult;

        std::cout << std::left << std::setw(15) << student.name
                  << std::setw(15) << student.surname
                  << std::setw(15) << finalScore
                  << std::endl;
    }

    return 0;
}
