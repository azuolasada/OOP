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


Student inputStudentManually() {
    Student student;
    std::cout << "Enter student's name: ";
    std::getline(std::cin, student.name); // Assuming name is a string

    std::cout << "Enter student's surname: ";
    std::getline(std::cin, student.surname); // Assuming surname is a string

    // Assuming homeworkResults is a vector of integers
    std::cout << "Enter homework results (end with a non-integer): ";
    int result;
    while (std::cin >> result) {
        if (!isValidScore(result)) {
            std::cout << "Invalid score. Please enter a score between 1 and 10." << std::endl;
            continue;
        }
        student.homeworkResults.push_back(result);
    }

    std::cin.clear(); // Clear the error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Skip to the next line

    std::cout << "Enter student's exam result: ";
    std::cin >> student.examResult;
    std::cin.ignore(); // Ignore the newline character left in the buffer

    return student; // Ensure you return a Student object

}

// Function to compute the mean of a set of integers
template <typename Container>
double computeMean(const Container& results) {
    return std::accumulate(results.begin(), results.end(), 0.0) / results.size();
}

// Function to compute the median of a set of integers
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

bool isValidScore(int score) {
    return score >= 1 && score <= 10;
}

bool fileExistsAndNotEmpty(const std::string& filename) {
    std::ifstream file(filename);
    return file.good() && file.peek() != std::ifstream::traits_type::eof();
}

template <typename Container>
void writeStudentsToFile(const Container& students, const std::string& filename) {
    std::ofstream out(filename);
    out << "Name,Surname,FinalScore\n";
    for (const auto& student : students) {
        out << student.name << "," << student.surname << "," << student.finalScore << "\n";
    }
}

int generateRandomScore(int min, int max) {
    static std::mt19937 rng(std::time(nullptr));
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

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

template <typename Container>
void displayStudents(const Container& students) {
    for (const auto& student : students) {
        std::cout << "Name: " << student.name 
                  << ", Surname: " << student.surname 
                  << ", Final Score: " << student.finalScore 
                  << std::endl;
    }
}



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
        Student student;
        std::istringstream iss(line);

        std::getline(iss, student.name, ',');
        std::getline(iss, student.surname, ',');

        while (std::getline(iss, value, ',')) {
            int score = std::stoi(value);
            student.homeworkResults.push_back(score);
        }

        student.examResult = student.homeworkResults.back();
        student.homeworkResults.pop_back(); // Remove exam result from homework results

        // Calculate final score
        double homeworkScore = computeMean(student.homeworkResults);
        student.finalScore = 0.4 * homeworkScore + 0.6 * student.examResult;

        students.push_back(student);
    }

    auto end_time_read = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> read_duration = end_time_read - start_time_read;

    auto start_time_sort = std::chrono::high_resolution_clock::now();
    // Sorting students based on sortCriterion
    if (sortCriterion == "name") {
        if constexpr (std::is_same<Container, std::vector<Student>>::value) {
            std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
                return a.name < b.name;
            });
        } else {
            students.sort([](const Student& a, const Student& b) {
                return a.name < b.name;
            });
        }
    } else if (sortCriterion == "surname") {
        if constexpr (std::is_same<Container, std::vector<Student>>::value) {
            std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
                return a.surname < b.surname;
            });
        } else {
            students.sort([](const Student& a, const Student& b) {
                return a.surname < b.surname;
            });
        }
    } else if (sortCriterion == "finalScore") {
        if constexpr (std::is_same<Container, std::vector<Student>>::value) {
            std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) { 
                return a.finalScore < b.finalScore; 
            });
        } else {
            students.sort([](const Student& a, const Student& b) { 
                return a.finalScore < b.finalScore; 
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
            if (student.finalScore < 5.0) {
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
                                             [](const Student& s) { return s.finalScore >= 5.0; });

        if constexpr (std::is_same<Container, std::vector<Student>>::value) {
            Container good_students, bad_students;
            good_students.reserve(std::distance(students.begin(), partitionPoint));
            bad_students.reserve(std::distance(partitionPoint, students.end()));

            std::copy(students.begin(), partitionPoint, std::back_inserter(good_students));
            std::copy(partitionPoint, students.end(), std::back_inserter(bad_students));

            writeStudentsToFile(good_students, "good_" + filename);
            writeStudentsToFile(bad_students, "bad_" + filename);
        } else {
            Container good_students(students.begin(), partitionPoint);
            Container bad_students(partitionPoint, students.end());

            writeStudentsToFile(good_students, "good_" + filename);
            writeStudentsToFile(bad_students, "bad_" + filename);
        }
    } 
    // Strategy 2: Modify the original container
    else if (strategy == 2) {
        Container bad_students;
        auto it = students.begin();
        while (it != students.end()) {
            if (it->finalScore < 5.0) {
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

    // Output processing times
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
