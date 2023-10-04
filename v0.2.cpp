#include <iostream>
#include <vector>
#include <sstream>
#include <random>
#include <ctime>
#include <fstream>
#include <algorithm>
#include <iomanip>

#include "student.h"
#include "calculations.h"
#include "input_output.h"
#include "random_score.h"
#include "score_validation.h"
#include "string_utils.h"


int main() {
    try {
        // Vector to store all student data
        std::vector<Student> students;

        // Variables to determine calculation and input methods
        char calculationMethod;
        char inputMethod;

        // Prompt user to select the calculation method (mean or median)
        std::cout << "Choose calculation method (m for mean, d for median): ";
        std::cin >> calculationMethod;
        if (calculationMethod != 'm' && calculationMethod != 'd') {
            throw std::runtime_error("Invalid calculation method selected!");
        }
        std::cin.ignore();

        // Prompt user to select input method (manual, random or from file)
        std::cout << "Choose input method (i for manual input, r for random, f for file): ";
        std::cin >> inputMethod;
        if (inputMethod != 'i' && inputMethod != 'r' && inputMethod != 'f') {
            throw std::runtime_error("Invalid input method selected!");
        }
        std::cin.ignore();

        // Handle file input
        if (inputMethod == 'f') {
            std::string file_name;
            std::cout << "Enter a file name: ";
            std::cin >> file_name;

            // Open the file and check for any errors
            std::ifstream file(file_name);
            if (!file) {
                throw std::runtime_error("Error opening file " + file_name + "!");
            }

            // Assume the first line is a header and skip it
            std::string header;
            std::getline(file, header);

            // Read student data from file
            while (file) {
                Student student;
                file >> student.name >> student.surname;

                // If end of file is reached after reading name and surname, exit loop
                if (file.eof()) break;

                // Read scores from the current line in the file
                std::string scoreLine;
                std::getline(file, scoreLine);
                
                std::istringstream iss(scoreLine);
                int score;
                while (iss >> score) {
                    if (!isValidScore(score)) {
                        throw std::runtime_error("Invalid score from file! Scores should be between 1 and 10.");
                    }
                    student.homeworkResults.push_back(score);
                }

                // Assume the last score in the line is the exam result
                student.examResult = student.homeworkResults.back();
                student.homeworkResults.pop_back();

                // Add student data to the list
                students.push_back(student);
            }

        } else {
            // Handle manual or random input for students

            int numStudents;
            std::cout << "Enter the number of students: ";
            std::cin >> numStudents;

            // Validate the number of students entered
            if (numStudents <= 0) {
                throw std::runtime_error("Number of students should be positive!");
            }
            std::cin.ignore();

            for (int i = 0; i < numStudents; ++i) {
                Student student;
                
                // Get student name and validate its length
                std::cout << "Enter name for student " << (i + 1) << ": ";
                std::getline(std::cin, student.name);
                if (student.name.empty() || student.name.length() > 50) {
                    throw std::runtime_error("Invalid student name. Ensure it's not empty and less than 50 characters.");
                }

                // Get student surname and validate its length
                std::cout << "Enter surname for student " << (i + 1) << ": ";
                std::getline(std::cin, student.surname);
                if (student.surname.empty() || student.surname.length() > 50) {
                    throw std::runtime_error("Invalid student surname. Ensure it's not empty and less than 50 characters.");
                }

                // Handle manual input
                if (inputMethod == 'i') {
                    std::cout << "Enter homework results for student " << (i + 1) << " (press Enter twice to stop):\n";
                    while (true) {
                        std::string line;
                        std::getline(std::cin, line);

                        // Exit loop if an empty line is entered
                        if (line.empty()) {
                            break;
                        }

                        // Extract and validate score from input line
                        std::istringstream iss(line);
                        int result;
                        iss >> result;
                        if (!isValidScore(result)) {
                            throw std::runtime_error("Invalid score entered. Scores should be between 1 and 10.");
                        }
                        student.homeworkResults.push_back(result);
                    }

                    // Get and validate the exam score
                    std::cout << "Enter exam result for student " << (i + 1) << ": ";
                    std::cin >> student.examResult;
                    std::cin.ignore();
                    if (!isValidScore(student.examResult)) {
                        throw std::runtime_error("Invalid exam score entered. Scores should be between 1 and 10.");
                    }
                } 
                // Handle random input
                else if (inputMethod == 'r') {
                    int numHomeworks = generateRandomScore(3, 15);
                    for (int j = 0; j < numHomeworks; ++j) {
                        student.homeworkResults.push_back(generateRandomScore(1, 10));
                    }
                    student.examResult = generateRandomScore(1, 10);
                }

                // Add student data to the list
                students.push_back(student);
            }
        }

        // Sort students based on custom comparison logic
        std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            if (a.name == b.name) {
                return a.surname < b.surname;
            }
            return a.name < b.name;
        });

        // Print out the sorted students' data
        printDataFrameHeader();
        for (const auto &student : students) {
            double homeworkScore = (calculationMethod == 'm' ? 
                computeMean(student.homeworkResults) : computeMedian(student.homeworkResults));
            double finalScore = 0.4 * homeworkScore + 0.6 * student.examResult;

            // Format and display each student's details
            std::cout << std::left << std::setw(15) << student.name
                      << std::setw(15) << student.surname
                      << std::setw(15) << finalScore
                      << std::endl;
        }
    } 
    // Catch any exceptions and display the error message
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

