#pragma once

#include "student.h"
#include <vector>

double computeMean(const std::list<int>& results);
double computeMedian(const std::vector<int>& results);

bool isValidScore(int score);

void writeStudentsToFile(const std::list<Student>& students, const std::string& filename);

void generateStudentFile(const std::string& filename, size_t numRecords);