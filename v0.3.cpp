#include <iostream>
#include <iomanip>
#include <list>
#include <chrono>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "side_functions.h"


int main() {
    try {
        // char generateData10M;
        // std::cout << "Do you want to generate random student data file with 10 million entries? (y/n): ";
        // std::cin >> generateData10M;

        // if (generateData10M == 'y') {
        //     std::string filename10M = "students_10000000.csv";
        //     std::cout << "Generating file: " << filename10M << " with 10 million students..." << std::endl;

        //     auto start_time_gen10M = std::chrono::high_resolution_clock::now();
        //     generateStudentFile(filename10M, 10000000);
        //     auto end_time_gen10M = std::chrono::high_resolution_clock::now();
        //     std::chrono::duration<double> gen_duration10M = end_time_gen10M - start_time_gen10M;

        //     std::cout << "Time taken to generate 10 million students: " << gen_duration10M.count() << " seconds." << std::endl;
        // }

        // Create a container to store Student objects.
        std::list<Student> students;

        // Define the sizes of student data files to be processed.
        std::vector<int> sizes = {1000, 10000, 100000, 1000000};

        // Process each data file size one-by-one.
        for (int size : sizes) {
            std::string filename = "students_" + std::to_string(size) + ".csv";

            // Start tracking the total time taken for processing this file.
            auto start_time_total = std::chrono::high_resolution_clock::now();

            // Start tracking time taken for reading the data.
            auto start_time_read = std::chrono::high_resolution_clock::now();

            std::ifstream file(filename);
            if (!file) {
                throw std::runtime_error("Error opening file " + filename + "!");
            }
            std::string header;
            std::getline(file, header);  // Read the header

            std::string line;
            // Read student data line-by-line.
            while (std::getline(file, line)) {
                Student student;
                std::istringstream iss(line);
                std::vector<std::string> values;
                std::string value;

                // Split the CSV line into individual values.
                while (std::getline(iss, value, ',')) {
                    values.push_back(value);
                }
                if (values.size() < 3) {
                    throw std::runtime_error("Error reading file. Insufficient data.");
                }
                // Populate the student object with the read data.
                student.name = values[0];
                student.surname = values[1];

                for (size_t i = 2; i < values.size() - 1; i++) {
                    int score = std::stoi(values[i]);
                    if (!isValidScore(score)) {
                        throw std::runtime_error("Invalid score from file! Scores should be between 1 and 10.");
                    }
                    student.homeworkResults.push_back(score);
                }
                student.examResult = std::stoi(values.back());
                // Add the student object to the list.
                students.push_back(student);
            }
            auto end_time_read = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> read_duration = end_time_read - start_time_read;
            std::cout << "-----------------------------------------" << std::endl;
            std::cout << "Process start from a file: " << filename << std::endl;
            std::cout << "Time taken to read data from " << filename << ": " << read_duration.count() << " seconds." << std::endl;

            // Calculate the final score for each student.
            for (auto &student : students) {
                double homeworkScore = computeMean(student.homeworkResults);
                student.finalScore = 0.4 * homeworkScore + 0.6 * student.examResult;
            }

            // Start tracking the time taken for sorting the data.
            auto start_time_sort = std::chrono::high_resolution_clock::now();

            // Sort students based on their final score.
            students.sort([](const Student& a, const Student& b) {
                return a.finalScore < b.finalScore;
            });

            std::list<Student> bad_students;
            std::list<Student> good_students;

            // Categorize students based on their final score.
            for (const auto &student : students) {
                if (student.finalScore < 5.0) {
                    bad_students.push_back(student);
                } else {
                    good_students.push_back(student);
                }
            }
            auto end_time_sort = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> sort_duration = end_time_sort - start_time_sort;
            std::cout << "Time taken to sort students from " << filename << ": " << sort_duration.count() << " seconds." << std::endl;

            // Start tracking the time taken for writing the sorted data to files.
            auto start_time_write = std::chrono::high_resolution_clock::now();

            writeStudentsToFile(good_students, "good_students_" + std::to_string(size) + ".csv");
            writeStudentsToFile(bad_students, "bad_students_" + std::to_string(size) + ".csv");

            auto end_time_write = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> write_duration = end_time_write - start_time_write;
            std::cout << "Time taken to write sorted students to files from " << filename << ": " << write_duration.count() << " seconds." << std::endl;

            auto end_time_total = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> total_duration = end_time_total - start_time_total;
            std::cout << "Total time taken for processing " << filename << ": " << total_duration.count() << " seconds." << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
