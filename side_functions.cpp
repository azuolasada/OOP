#include "side_functions.h"
#include <numeric>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <ctime>
#include <list>
#include <vector>
#include <chrono>
#include <sstream>
#include <limits>

/**
 * @brief Prompts user input for creating a Student object.
 * 
 * This function asks the user to enter the name, surname, homework results, 
 * and exam result of a student, then constructs and returns a Student object.
 * @return A Student object constructed from user input.
 */
Student inputStudentManually() {
    std::string name, surname;
    std::vector<int> homeworkResults;
    int examResult;

    std::cout << "Enter student's name: ";
    std::getline(std::cin, name);

    std::cout << "Enter student's surname: ";
    std::getline(std::cin, surname);

    std::cout << "Enter homework results (end with a non-integer): ";
    int result;
    while (std::cin >> result) {
        if (!isValidScore(result)) {
            std::cout << "Invalid score. Please enter a score between 1 and 10." << std::endl;
            continue;
        }
        homeworkResults.push_back(result);
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter student's exam result: ";
    std::cin >> examResult;
    std::cin.ignore();

    Student student(name, surname, homeworkResults, examResult);
    return student;
}
/**
 * @brief Computes the mean of values in a container.
 * 
 * @tparam Container A container type supporting begin() and end() iterators.
 * @param results A container holding numeric values.
 * @return The arithmetic mean of the numeric values.
 */
template <typename Container>
double computeMean(const Container& results) {
    return std::accumulate(results.begin(), results.end(), 0.0) / results.size();
}

/**
 * @brief Computes the median of a vector of integers.
 * 
 * @param results A vector of integers.
 * @return The median value as a double.
 */
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
/**
 * @brief Checks if a score is in the valid range (1-10).
 * 
 * @param score The score to check.
 * @return True if the score is valid, false otherwise.
 */
bool isValidScore(int score) {
    return score >= 1 && score <= 10;
}
/**
 * @brief Checks if a file exists and is not empty.
 * 
 * @param filename The name of the file to check.
 * @return True if the file exists and is not empty, false otherwise.
 */
bool fileExistsAndNotEmpty(const std::string& filename) {
    std::ifstream file(filename);
    return file.good() && file.peek() != std::ifstream::traits_type::eof();
}
/**
 * @brief Writes student data to a specified file.
 * 
 * @tparam Container A container type of Student objects.
 * @param students The container holding the students.
 * @param filename The name of the file to write to.
 */
template <typename Container>
void writeStudentsToFile(const Container& students, const std::string& filename) {
    std::ofstream out(filename);
    out << "Name,Surname,FinalScore\n";
    for (const auto& student : students) {
        out << student.getName() << "," << student.getSurname() << "," << student.getFinalScore() << "\n";
    }
}
/**
 * @brief Generates a random score within a specified range.
 * 
 * @param min The minimum score (inclusive).
 * @param max The maximum score (inclusive).
 * @return A random score within the specified range.
 */
int generateRandomScore(int min, int max) {
    static std::mt19937 rng(std::time(nullptr));
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}
/**
 * @brief Generates a file with random student data.
 * 
 * @param filename The name of the file to create.
 * @param numRecords The number of student records to generate.
 */
void generateStudentFile(const std::string& filename, size_t numRecords) {
    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        std::cerr << "Failed to open " << filename << " for writing." << std::endl;
        return;
    }

    outFile << "Name,Surname,Homework1,Homework2,Homework3,Homework4,Homework5,Exam\n";

    for (size_t i = 0; i < numRecords; ++i) {
        std::string name = "Name" + std::to_string(i + 1);
        std::string surname = "Surname" + std::to_string(i + 1);

        outFile << name << "," << surname;

        for (int j = 0; j < 5; ++j) {
            outFile << "," << generateRandomScore(1, 10);
        }

        outFile << "," << generateRandomScore(1, 10) << "\n";
    }

    outFile.close();
}
/**
 * @brief Displays student information on standard output.
 * 
 * @tparam Container A container type of Student objects.
 * @param students The container holding the students.
 */
template <typename Container>
void displayStudents(const Container& students) {
    for (const auto& student : students) {
        std::cout << "Name: " << student.getName() 
                  << ", Surname: " << student.getSurname() 
                  << ", Final Score: " << student.getFinalScore() 
                  << std::endl;
    }
}
/**
 * @brief Processes students by reading from a file, sorting, and writing to files.
 * 
 * @tparam Container A container type of Student objects.
 * @param students The container to store processed students.
 * @param filename The name of the input file.
 * @param strategy The strategy for processing students (e.g., sorting criteria).
 * @param sortCriterion The criterion used for sorting (e.g., "name", "surname").
 */
template <typename Container>
void processStudents(Container& students, const std::string& filename, int strategy, const std::string& sortCriterion) {
    // Start reading file
    auto start_time_read = std::chrono::high_resolution_clock::now();

    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Error opening file " + filename + "!");
    }
    std::string line, value;
    std::getline(file, line);  // Read the header

    while (std::getline(file, line)) {
        std::string name, surname;
        std::vector<int> homeworkResults;
        int examResult;

        std::istringstream iss(line);
        std::getline(iss, name, ',');
        std::getline(iss, surname, ',');

        while (std::getline(iss, value, ',')) {
            int score = std::stoi(value);
            homeworkResults.push_back(score);
        }

        examResult = homeworkResults.back();
        homeworkResults.pop_back(); // Remove exam result from homework results

        // Calculate final score
        double homeworkScore = computeMean(homeworkResults);
        double finalScore = 0.4 * homeworkScore + 0.6 * examResult;

        Student student(name, surname, homeworkResults, examResult);
        student.setFinalScore(finalScore);

        students.push_back(student);
    }

    auto end_time_read = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> read_duration = end_time_read - start_time_read;

auto start_time_sort = std::chrono::high_resolution_clock::now();

    // Use different sorting methods for std::list and std::vector
    if constexpr (std::is_same<Container, std::vector<Student>>::value) {
        if (sortCriterion == "name") {
            std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
                return a.getName() < b.getName();
            });
        } else if (sortCriterion == "surname") {
            std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
                return a.getSurname() < b.getSurname();
            });
        } else if (sortCriterion == "finalScore") {
            std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
                return a.getFinalScore() < b.getFinalScore();
            });
        }
    } else if constexpr (std::is_same<Container, std::list<Student>>::value) {
        if (sortCriterion == "name") {
            students.sort([](const Student& a, const Student& b) {
                return a.getName() < b.getName();
            });
        } else if (sortCriterion == "surname") {
            students.sort([](const Student& a, const Student& b) {
                return a.getSurname() < b.getSurname();
            });
        } else if (sortCriterion == "finalScore") {
            students.sort([](const Student& a, const Student& b) {
                return a.getFinalScore() < b.getFinalScore();
            });
        }
    }

    auto end_time_sort = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> sort_duration = end_time_sort - start_time_sort;

    // Writing to files
    auto start_time_write = std::chrono::high_resolution_clock::now();

    // Strategy 1: Basic separation into two new containers
    if (strategy == 1) {
        Container good_students, bad_students;
        for (const auto& student : students) {
            if (student.getFinalScore() < 5.0) {
                bad_students.push_back(student);
            } else {
                good_students.push_back(student);
            }
        }
        writeStudentsToFile(good_students, "good_" + filename);
        writeStudentsToFile(bad_students, "bad_" + filename);
    } 
    // Strategy 3: Optimized for std::vector using std::partition
    else if (strategy == 3) {
        auto partitionPoint = std::partition(students.begin(), students.end(),
                                             [](const Student& s) { return s.getFinalScore() >= 5.0; });

        Container good_students(students.begin(), partitionPoint);
        Container bad_students(partitionPoint, students.end());

        writeStudentsToFile(good_students, "good_" + filename);
        writeStudentsToFile(bad_students, "bad_" + filename);
    } 
    // Strategy 2: Modify the original container
    else if (strategy == 2) {
        Container bad_students;
        auto it = students.begin();
        while (it != students.end()) {
            if (it->getFinalScore() < 5.0) {
                bad_students.push_back(*it);
                it = students.erase(it);
            } else {
                ++it;
            }
        }
        writeStudentsToFile(students, "good_" + filename);
        writeStudentsToFile(bad_students, "bad_" + filename);
    }

    auto end_time_write = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> write_duration = end_time_write - start_time_write;

    // Optional: Output processing times
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "File: " << filename << std::endl;
    std::cout << "Read time: " << read_duration.count() << " seconds." << std::endl;
    std::cout << "Sort time: " << sort_duration.count() << " seconds." << std::endl;
    std::cout << "Write time: " << write_duration.count() << " seconds." << std::endl;
    std::cout << "Total processing time: " << (read_duration + sort_duration + write_duration).count() << " seconds." << std::endl;
}

// Explicit template instantiation for std::list and std::vector
template void displayStudents(const std::list<Student>& students);
template void displayStudents(const std::vector<Student>& students);
template void processStudents(std::list<Student>&, const std::string&, int, const std::string&);
template void processStudents(std::vector<Student>&, const std::string&, int, const std::string&);
template void writeStudentsToFile(const std::list<Student>& students, const std::string& filename);
template void writeStudentsToFile(const std::vector<Student>& students, const std::string& filename);