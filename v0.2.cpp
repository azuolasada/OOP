#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>
#include <algorithm>
#include <fstream>
#include <sstream>

#include "student.h"
#include "calculations.h"
#include "input_output.h"
#include "score_validation.h"
#include "student_generator.h"

void writeStudentsToFile(const std::vector<Student>& students, const std::string& filename) {
    std::ofstream out(filename);
    out << "Name,Surname,FinalScore\n";
    for (const auto& student : students) {
        out << student.name << "," << student.surname << "," << student.finalScore << "\n";
    }
}

int main() {
    try {
        // Vector to store all student data
        std::vector<Student> students;

        // Prompt user to generate random student data
        char generateData;
        std::cout << "Do you want to generate random student data files? (y/n): ";
        std::cin >> generateData;

        std::vector<int> sizes = {1000, 10000, 100000, 1000000};

        if (generateData == 'y') {
            for (int size : sizes) {
                std::string filename = "students_" + std::to_string(size) + ".csv";
                std::cout << "Generating file: " << filename << " with " << size << " students..." << std::endl;
                
                auto start_time = std::chrono::high_resolution_clock::now();
                generateStudentFile(filename, size);
                auto end_time = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> gen_duration = end_time - start_time;

                std::cout << "Time taken to generate " << size << " students: " << gen_duration.count() << " seconds." << std::endl;
            }

            std::cout << "Student data generation completed!" << std::endl;
        }

        for (int size : sizes) {
            std::string filename = "students_" + std::to_string(size) + ".csv";
            std::ifstream file(filename);
            if (!file) {
                throw std::runtime_error("Error opening file " + filename + "!");
            }

            std::string header;
            std::getline(file, header);

            while (file) {
                Student student;
                file >> student.name >> student.surname;

                if (file.eof()) break;

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

                student.examResult = student.homeworkResults.back();
                student.homeworkResults.pop_back();

                students.push_back(student);
            }

            // Calculate the finalScore for each student
            for (auto &student : students) {
                double homeworkScore = computeMean(student.homeworkResults);
                student.finalScore = 0.4 * homeworkScore + 0.6 * student.examResult;
            }

            // Sort the students based on their finalScore
            std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
                return a.finalScore < b.finalScore;
            });

            // Divide students into bad_students and good_students categories
            std::vector<Student> bad_students;
            std::vector<Student> good_students;
            for (const auto &student : students) {
                if (student.finalScore < 5.0) {
                    bad_students.push_back(student);
                } else {
                    good_students.push_back(student);
                }
            }

            // Write to separate files
            writeStudentsToFile(good_students, "good_students_" + std::to_string(size) + ".csv");
            writeStudentsToFile(bad_students, "bad_students_" + std::to_string(size) + ".csv");
        }

        // Print out the sorted students' data
        printDataFrameHeader();
        for (const auto &student : students) {
            std::cout << std::left << std::setw(15) << student.name
                      << std::setw(15) << student.surname
                      << std::setw(15) << student.finalScore
                      << std::endl;
        }

    } 
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
