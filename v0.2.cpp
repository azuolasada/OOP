#include <iostream>
#include <vector>
#include <chrono>  // for performance measurement

#include "student.h"
#include "calculations.h"
#include "input_output.h"
#include "score_validation.h"
#include "student_generator.h" // This includes the student generation functions

int main() {
    try {
        // Vector to store all student data
        std::vector<Student> students;

        // Prompt user to generate random student data
        char generateData;
        std::cout << "Do you want to generate random student data files? (y/n): ";
        std::cin >> generateData;
        std::cin.ignore();  // Clear the input buffer

        if (generateData == 'y' || generateData == 'Y') {
            std::vector<int> sizes = {1000, 10000, 100000, 1000000, 10000000};

            for (int size : sizes) {
                std::string filename = "students_" + std::to_string(size) + ".csv";
                std::cout << "Generating file: " << filename << " with " << size << " students..." << std::endl;
                
                auto start_time = std::chrono::high_resolution_clock::now(); // Start timer for generation
                
                generateStudentFile(filename, size);

                auto end_time = std::chrono::high_resolution_clock::now();   // End timer for generation
                std::chrono::duration<double> gen_duration = end_time - start_time;
                std::cout << "Time taken to generate " << size << " students: " << gen_duration.count() << " seconds." << std::endl;
            }
            
            std::cout << "Student data generation completed!" << std::endl;
        }

        // Further functionalities (reading, sorting, etc.) will be integrated in later tasks...

    } 
    // Catch any exceptions and display the error message
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
