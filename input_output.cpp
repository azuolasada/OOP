#include "input_output.h"
#include <iostream>
#include <iomanip>

void printDataFrameHeader() {
    std::cout << std::left << std::setw(15) << "Name"
              << std::setw(15) << "Surname"
              << std::setw(15) << "Final Score"
              << std::endl;
    std::cout << std::string(45, '-') << std::endl;
}
