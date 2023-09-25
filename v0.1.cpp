#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <random>
#include <ctime>
#include <fstream>

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

int generateRandomScore(int min, int max) {
    static std::mt19937 rng(std::time(nullptr));  // Random number generator
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

int main() {
    std::vector<Student> students;
    char calculationMethod;
    char inputMethod;

    std::cout << "Choose calculation method (m for mean, d for median): ";
    std::cin >> calculationMethod;
    std::cin.ignore();

    std::cout << "Choose input method (i for manual input, r for random, f for file): ";
    std::cin >> inputMethod;
    std::cin.ignore();

    if (inputMethod == 'f') {
        std::ifstream file("kursiokai.txt");
        if (!file) {
            std::cerr << "Error opening file kursiokai.txt!" << std::endl;
            return 1;
        }

        // Ignore header line
        std::string header;
        std::getline(file, header);

        while (file) {
            Student student;
            file >> student.name >> student.surname;

            // If we reached the end of file after reading name and surname, exit loop
            if (file.eof()) break;

            // Read homework scores and exam result
            for (int i = 0; i < 15; ++i) {
                int score;
                file >> score;
                student.homeworkResults.push_back(score);
            }
            file >> student.examResult;

            // Ignore rest of line (if there's anything left)
            std::getline(file, header);

            students.push_back(student);
        }
    } else {
        int numStudents;
        std::cout << "Enter the number of students: ";
        std::cin >> numStudents;
        std::cin.ignore();

        for (int i = 0; i < numStudents; ++i) {
            Student student;

            std::cout << "Enter name for student " << (i + 1) << ": ";
            std::getline(std::cin, student.name);

            std::cout << "Enter surname for student " << (i + 1) << ": ";
            std::getline(std::cin, student.surname);

            if (inputMethod == 'i') {
                std::cout << "Enter homework results for student " << (i + 1) << " (press Enter twice to stop):\n";
                while (true) {
                    std::string line;
                    std::getline(std::cin, line);
                    if (line.empty()) {
                        break;
                    }
                    std::istringstream iss(line);
                    int result;
                    iss >> result;
                    student.homeworkResults.push_back(result);
                }

                std::cout << "Enter exam result for student " << (i + 1) << ": ";
                std::cin >> student.examResult;
                std::cin.ignore();
            } else if (inputMethod == 'r') {
                int numHomeworks = generateRandomScore(3, 15);
                for (int j = 0; j < numHomeworks; ++j) {
                    student.homeworkResults.push_back(generateRandomScore(1, 10));
                }

                student.examResult = generateRandomScore(1, 10);
                std::cout << "Generated random scores for " << student.name << " " << student.surname << std::endl;
            }

            students.push_back(student);
        }
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
