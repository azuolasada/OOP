#pragma once

#include "student.h"  // Include your Student class header
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

// Declaration of template functions
Student inputStudentManually();

template <typename Container>
double computeMean(const Container& results);

double computeMedian(const std::vector<int>& results);

bool isValidScore(int score);

template <typename Container>
void writeStudentsToFile(const Container& students, const std::string& filename);

template <typename Container>
void displayStudents(const Container& students);

void generateStudentFile(const std::string& filename, size_t numRecords);

template <typename Container>
void processStudents(Container& students, const std::string& filename, int strategy, const std::string& sortCriterion);

// Declaration of non-template functions
bool fileExistsAndNotEmpty(const std::string& filename);

int generateRandomScore(int min, int max);

// Explicit template instantiation declarations
extern template void processStudents(std::list<Student>&, const std::string&, int, const std::string&);
extern template void processStudents(std::vector<Student>&, const std::string&, int, const std::string&);

extern template void writeStudentsToFile(const std::list<Student>& students, const std::string& filename);
extern template void writeStudentsToFile(const std::vector<Student>& students, const std::string& filename);

extern template void displayStudents(const std::list<Student>& students);
extern template void displayStudents(const std::vector<Student>& students);
