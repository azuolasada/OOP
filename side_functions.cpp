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

template <typename Container>
double computeMean(const Container& results) {
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

bool isValidScore(int score) {
    return score >= 1 && score <= 10;
}

template <typename Container>
void writeStudentsToFile(const Container& students, const std::string& filename) {
    std::ofstream out(filename);
    out << "Name,Surname,FinalScore\n";
    for (const auto& student : students) {
        out << student.getName() << "," << student.getSurname() << "," << student.getFinalScore() << "\n";
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
void processStudents(Container& students, const std::string& filename, int strategy) {
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

        std::string name, surname;
        std::getline(iss, name, ',');
        student.setName(name);
        std::getline(iss, surname, ',');
        student.setSurname(surname);

        while (std::getline(iss, value, ',')) {
            int score = std::stoi(value);
            student.addHomeworkResult(score);
        }

        student.setExamResult(student.getHomeworkResults().back());
        student.removeLastHomeworkResult();

        double homeworkScore = computeMean(student.getHomeworkResults());
        student.setFinalScore(0.4 * homeworkScore + 0.6 * student.getExamResult());

        students.push_back(student);
    }

    auto end_time_read = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> read_duration = end_time_read - start_time_read;

    auto start_time_sort = std::chrono::high_resolution_clock::now();
    if constexpr (std::is_same<Container, std::list<Student>>::value) {
        students.sort([](const Student& a, const Student& b) {
            return a.getFinalScore() < b.getFinalScore();
        });
    } else {
        std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.getFinalScore() < b.getFinalScore();
        });
    }

    auto end_time_sort = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> sort_duration = end_time_sort - start_time_sort;

    auto start_time_write = std::chrono::high_resolution_clock::now();
    // Strategy implementation here...
    // ...
    auto end_time_write = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> write_duration = end_time_write - start_time_write;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "File: " << filename << std::endl;
    std::cout << "Read time: " << read_duration.count() << " seconds." << std::endl;
    std::cout << "Sort time: " << sort_duration.count() << " seconds." << std::endl;
    std::cout << "Write time: " << write_duration.count() << " seconds." << std::endl;
    std::cout << "Total processing time: " << (read_duration + sort_duration + write_duration).count() << " seconds." << std::endl;
}

template void processStudents(std::list<Student>&, const std::string&, int);
template void processStudents(std::vector<Student>&, const std::string&, int);

template void writeStudentsToFile(const std::list<Student>& students, const std::string& filename);
template void writeStudentsToFile(const std::vector<Student>& students, const std::string& filename);
