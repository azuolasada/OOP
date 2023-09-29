#pragma once
#include <string>

// Extracts the numeric part from a string.
// If no numeric part is found, it returns -1.
int extractNumericPart(const std::string& str);

// Extracts the non-numeric part from a string.
std::string extractNonNumericPart(const std::string& str);