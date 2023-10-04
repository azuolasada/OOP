#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <ctime>

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

int main() {
    // Generate student list files with the desired number of records.
    generateStudentFile("students_1000.csv", 1000);
    generateStudentFile("students_10000.csv", 10000);
    generateStudentFile("students_100000.csv", 100000);
    generateStudentFile("students_1000000.csv", 1000000);
    generateStudentFile("students_10000000.csv", 10000000);

    std::cout << "Student list files generated successfully!" << std::endl;
    return 0;
}