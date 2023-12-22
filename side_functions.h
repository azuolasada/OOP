#pragma once

#include "student.h"  
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>
#include <numeric>
#include <algorithm>
#include <random>
#include <ctime>
#include <chrono>

/**
 * @brief Prompts the user to input a student's details manually.
 * 
 * @return A Student object with the inputted details.
 */
Student inputStudentManually();

/**
 * @brief Computes the mean of values in a container.
 * 
 * @tparam Container The type of the container (e.g., vector, list).
 * @param results The container holding the values.
 * @return The mean of the values as a double.
 */
template <typename Container>
double computeMean(const Container& results);

/**
 * @brief Computes the median of a vector of integers.
 * 
 * @param results The vector containing the integers.
 * @return The median of the values as a double.
 */
double computeMedian(const std::vector<int>& results);

/**
 * @brief Checks if a given score is valid.
 * 
 * @param score The score to be checked.
 * @return True if the score is valid, false otherwise.
 */
bool isValidScore(int score);

/**
 * @brief Writes student details to a file.
 * 
 * @tparam Container The type of the container (e.g., vector, list).
 * @param students The container holding the students.
 * @param filename The name of the file to write to.
 */
template <typename Container>
void writeStudentsToFile(const Container& students, const std::string& filename);

/**
 * @brief Displays student details.
 * 
 * @tparam Container The type of the container (e.g., vector, list).
 * @param students The container holding the students.
 */
template <typename Container>
void displayStudents(const Container& students);

/**
 * @brief Generates a file with random student records.
 * 
 * @param filename The name of the file to generate.
 * @param numRecords The number of student records to generate.
 */
void generateStudentFile(const std::string& filename, size_t numRecords);

/**
 * @brief Processes a list of students based on a specified strategy and sorting criterion.
 * 
 * @tparam Container The type of the container (e.g., vector, list).
 * @param students The container holding the students.
 * @param filename The filename to process.
 * @param strategy The processing strategy to use.
 * @param sortCriterion The criterion to sort the students by.
 */
template <typename Container>
void processStudents(Container& students, const std::string& filename, int strategy, const std::string& sortCriterion);

/**
 * @brief Checks if a file exists and is not empty.
 * 
 * @param filename The name of the file to check.
 * @return True if the file exists and is not empty, false otherwise.
 */
bool fileExistsAndNotEmpty(const std::string& filename);

/**
 * @brief Generates a random score within a specified range.
 * 
 * @param min The minimum score.
 * @param max The maximum score.
 * @return A random score within the specified range.
 */
int generateRandomScore(int min, int max);

// Explicit template instantiation declarations
extern template void processStudents(std::list<Student>&, const std::string&, int, const std::string&);
extern template void processStudents(std::vector<Student>&, const std::string&, int, const std::string&);

extern template void writeStudentsToFile(const std::list<Student>& students, const std::string& filename);
extern template void writeStudentsToFile(const std::vector<Student>& students, const std::string& filename);

extern template void displayStudents(const std::list<Student>& students);
extern template void displayStudents(const std::vector<Student>& students);
