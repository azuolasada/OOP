#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <random>
#include <ctime>
#include <fstream>

// Define a structure to represent each student's details
struct Student {
    std::string name;
    std::string surname;
    std::vector<int> homeworkResults; // Store multiple homework scores
    int examResult;
};

// Function to calculate the mean of given results
double computeMean(const std::vector<int>& results) {
    return std::accumulate(results.begin(), results.end(), 0.0) / results.size();
}

// Function to calculate the median of given results
double computeMedian(const std::vector<int>& results) {
    size_t size = results.size();
    std::vector<int> sortedResults = results; // Copy results for sorting
    std::sort(sortedResults.begin(), sortedResults.end());

    if (size % 2 == 0) {
        return (sortedResults[size / 2 - 1] + sortedResults[size / 2]) / 2.0;
    } else {
        return sortedResults[size / 2];
    }
}

// Function to display the header of the results table
void printDataFrameHeader() {
    std::cout << std::left << std::setw(15) << "Name"
              << std::setw(15) << "Surname"
              << std::setw(15) << "Final Score"
              << std::endl;
    std::cout << std::string(45, '-') << std::endl;
}

// Function to generate a random score within a range [min, max]
int generateRandomScore(int min, int max) {
    static std::mt19937 rng(std::time(nullptr));  // Random number generator seeded with current time
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

int main() {
    try {
        std::vector<Student> students; // Vector to store details of all students
        char calculationMethod;
        char inputMethod;

        // Prompt user for the method of score calculation (mean/median)
        std::cout << "Choose calculation method (m for mean, d for median): ";
        std::cin >> calculationMethod;
        if (calculationMethod != 'm' && calculationMethod != 'd') {
            throw std::runtime_error("Invalid calculation method selected!");
        }
        std::cin.ignore();

        // Prompt user for the method of input (manual/random/file)
        std::cout << "Choose input method (i for manual input, r for random, f for file): ";
        std::cin >> inputMethod;
        if (inputMethod != 'i' && inputMethod != 'r' && inputMethod != 'f') {
            throw std::runtime_error("Invalid input method selected!");
        }
        std::cin.ignore();

        // If the chosen input method is from a file
        if (inputMethod == 'f') {
            std::string file_name;
            std::cout << "Enter a file name: ";
            std::cin >> file_name;
            std::ifstream file(file_name);
            if (!file) {
                throw std::runtime_error("Error opening file " + file_name + "!");
            }

            // Skipping the header line of the file
            std::string header;
            std::getline(file, header);

            // Read student details from file until end
            while (file) {
                Student student;
                file >> student.name >> student.surname;

                // If EOF reached after reading name and surname, exit loop
                if (file.eof()) break;

                // Read homework scores and exam result from the file
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

                // Check if student has any homework results, if not, skip calculations
                if (student.homeworkResults.empty()) {
                    std::cout << "No homework results for " << student.name << " " << student.surname << " in the file. It's not possible to do calculations." << std::endl;
                    continue;
                }

                students.push_back(student); // Store student details in vector
            }
        } else {
            // For manual/random input, the procedure is similar to the previous version
            // Prompt user for number of students and read their details appropriately
            
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

                    if (student.homeworkResults.empty()) {
                        std::cout << "No homework results for " << student.name << " " << student.surname << ". It's not possible to do calculations." << std::endl;
                        continue;
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

                students.push_back(student); // Store student details in vector
            }
        }

        // Print student results in tabular form
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
        // Exception handling: Print any error messages and exit with an error code
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0; // Successful execution
}



