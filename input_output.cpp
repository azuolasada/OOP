#include "input_output.h"
#include <iostream>
#include <iomanip>

// Function to print the header of the data frame
void printDataFrameHeader() {
    // Print the header with appropriate spacing
    std::cout << std::left << std::setw(15) << "Name"
              << std::setw(15) << "Surname"
              << std::setw(15) << "Final Score"
              << std::endl;
    // Print a separator line
    std::cout << std::string(45, '-') << std::endl;
}
