#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <chrono>  // for performance measurement

#include "student.h"
#include "calculations.h"
#include "input_output.h"
#include "score_validation.h"

int main() {
    try {
        // Vector to store all student data
        std::vector<Student> students;

        // Read student data from file
        std::string file_name;
        std::cout << "Enter the source file name: ";
        std::cin >> file_name;
        
        auto start_time = std::chrono::high_resolution_clock::now(); // Start timer for file read
        
        // Read students from the file
        // readStudentsFromFile(file_name, students);
        
        auto end_time = std::chrono::high_resolution_clock::now();   // End timer for file read
        std::chrono::duration<double> read_duration = end_time - start_time;
        std::cout << "Time taken to read data from file: " << read_duration.count() << " seconds." << std::endl;

        // Sort students based on final score
        start_time = std::chrono::high_resolution_clock::now(); // Start timer for sorting

        std::vector<Student> poor_students;
        std::vector<Student> good_students;
        // sortStudents(students, poor_students, good_students);

        end_time = std::chrono::high_resolution_clock::now();   // End timer for sorting
        std::chrono::duration<double> sort_duration = end_time - start_time;
        std::cout << "Time taken to sort students: " << sort_duration.count() << " seconds." << std::endl;

        // Write students to two new files based on their category
        start_time = std::chrono::high_resolution_clock::now(); // Start timer for file write

        // writeStudentsToFile("poor_students.csv", poor_students);
        // writeStudentsToFile("good_students.csv", good_students);

        end_time = std::chrono::high_resolution_clock::now();   // End timer for file write
        std::chrono::duration<double> write_duration = end_time - start_time;
        std::cout << "Time taken to write sorted students to files: " << write_duration.count() << " seconds." << std::endl;
    } 
    // Catch any exceptions and display the error message
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

