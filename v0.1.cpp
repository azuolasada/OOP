#include <iostream>
#include <vector>
#include <sstream>
#include <random>
#include <ctime>
#include <fstream>
#include <algorithm>

#include "student.h"
#include "calculations.h"
#include "input_output.h"

int generateRandomScore(int min, int max) {
    static std::mt19937 rng(std::time(nullptr));
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

int main() {
    try {
        std::vector<Student> students;
        char calculationMethod;
        char inputMethod;

        std::cout << "Choose calculation method (m for mean, d for median): ";
        std::cin >> calculationMethod;
        if (calculationMethod != 'm' && calculationMethod != 'd') {
            throw std::runtime_error("Invalid calculation method selected!");
        }
        std::cin.ignore();

        std::cout << "Choose input method (i for manual input, r for random, f for file): ";
        std::cin >> inputMethod;
        if (inputMethod != 'i' && inputMethod != 'r' && inputMethod != 'f') {
            throw std::runtime_error("Invalid input method selected!");
        }
        std::cin.ignore();

        if (inputMethod == 'f') {
            std::string file_name;
            std::cout << "Enter a file name: ";
            std::cin >> file_name;
            std::ifstream file(file_name);
            if (!file) {
                throw std::runtime_error("Error opening file " + file_name + "!");
            }

            std::string header;
            std::getline(file, header); // Ignore the header line

            while (file) {
                Student student;
                file >> student.name >> student.surname;
                if (file.eof()) break;

                for (int i = 0; i < 15; ++i) {
                    int score;
                    if (!(file >> score)) {
                        throw std::runtime_error("Error reading score from file!");
                    }
                    student.homeworkResults.push_back(score);
                }
                if (!(file >> student.examResult)) {
                    throw std::runtime_error("Error reading exam result from file!");
                }
                students.push_back(student);
            }
        } else {
            int numStudents;
            std::cout << "Enter the number of students: ";
            std::cin >> numStudents;
            if (numStudents <= 0) {
                throw std::runtime_error("Number of students should be positive!");
            }
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
                }

                students.push_back(student);
            }
        }

        // Sort the students by name and surname
        std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            if (a.name == b.name) {
                return a.surname < b.surname;
            }
            return a.name < b.name;
        });

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
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
