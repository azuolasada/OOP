#include "side_functions.h"

#include <numeric>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <ctime>

// Function to compute the mean of a set of integers
double computeMean(const std::vector<int>& results) {
    // std::accumulate computes the sum of the results, divided by the number of elements to get the mean
    return std::accumulate(results.begin(), results.end(), 0.0) / results.size();
}

// Function to compute the median of a set of integers
double computeMedian(const std::vector<int>& results) {
    size_t size = results.size();
    std::vector<int> sortedResults = results;
    std::sort(sortedResults.begin(), sortedResults.end());  // Sorting the results to find the median

    // Check whether the size is even or odd and compute median accordingly
    if (size % 2 == 0) {
        // If even, return the average of the two middle elements
        return (sortedResults[size / 2 - 1] + sortedResults[size / 2]) / 2.0;
    } else {
        // If odd, return the middle element
        return sortedResults[size / 2];
    }
}

bool isValidScore(int score) {
    // The score is valid if it is between 1 and 10 inclusive
    return score >= 1 && score <= 10;
}

void writeStudentsToFile(const std::vector<Student>& students, const std::string& filename) {
    std::ofstream out(filename);
    out << "Name,Surname,FinalScore\n";
    for (const auto& student : students) {
        out << student.name << "," << student.surname << "," << student.finalScore << "\n";
    }
}

// Function to generate a random score between min and max.
int generateRandomScore(int min, int max) {
    static std::mt19937 rng(std::time(nullptr));  // Seed the random number generator once
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

// Function to generate a student list file with the specified number of records.
void generateStudentFile(const std::string& filename, size_t numRecords) {
    std::ofstream outFile(filename);

    // Ensure the file is open before writing.
    if (!outFile.is_open()) {
        std::cerr << "Failed to open " << filename << " for writing." << std::endl;
        return;
    }

    // Define the header of the file.
    outFile << "Name,Surname,Homework1,Homework2,Homework3,Homework4,Homework5,Exam\n";

    // Iterate through the number of records.
    for (size_t i = 0; i < numRecords; ++i) {
        // Generate a name and surname using a predictable pattern.
        std::string name = "Name" + std::to_string(i + 1);
        std::string surname = "Surname" + std::to_string(i + 1);

        // Write the student's name and surname to the file.
        outFile << name << "," << surname;

        // Generate 5 random homework scores.
        for (int j = 0; j < 5; ++j) {
            int homeworkScore = generateRandomScore(1, 10);
            outFile << "," << homeworkScore;
        }

        // Generate an exam score.
        int examScore = generateRandomScore(1, 10);

        // Write the exam score to the file.
        outFile << "," << examScore << "\n";
    }

    // Close the file.
    outFile.close();
}
