#include "string_utils.h"


// Function to extract the numeric part from a string
int extractNumericPart(const std::string& str) {
    size_t i = 0;
    
    // Iterate until the first digit is found
    while (i < str.size() && !isdigit(str[i])) {
        ++i;
    }

    // If no digits are found, return -1
    if (i == str.size()) {
        return -1;  // No numeric part found.
    }

    // Identify the start of the numeric segment
    size_t start = i;

    // Continue iterating until the end of the numeric segment
    while (i < str.size() && isdigit(str[i])) {
        ++i;
    }

    // Convert the extracted numeric segment to an integer and return it
    return std::stoi(str.substr(start, i - start));
}

// Function to extract the non-numeric part from a string
std::string extractNonNumericPart(const std::string& str) {
    std::string result;

    // Iterate through the string
    for (char c : str) {
        // If the character is not a digit, add it to the result string
        if (!isdigit(c)) {
            result += c;
        }
    }

    // Return the concatenated non-numeric segment of the string
    return result;
}
