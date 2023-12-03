#pragma once

#include "student.h"
#include <vector>
#include <list>
#include <iostream>

template <typename Container>
void processStudents(Container& students, const std::string& filename, int strategy);

template <typename Container>
double computeMean(const Container& results);
double computeMedian(const std::vector<int>& results);

bool isValidScore(int score);

template <typename Container>
void writeStudentsToFile(const Container& students, const std::string& filename);

void generateStudentFile(const std::string& filename, size_t numRecords);

// Input and Output operators for Student class
std::istream& operator>>(std::istream& in, Student& student);
std::ostream& operator<<(std::ostream& out, const Student& student);
