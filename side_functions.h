#pragma once

#include "student.h"

double computeMean(const std::vector<int>& results);
double computeMedian(const std::vector<int>& results);

bool isValidScore(int score);

void writeStudentsToFile(const std::vector<Student>& students, const std::string& filename);

void generateStudentFile(const std::string& filename, size_t numRecords);