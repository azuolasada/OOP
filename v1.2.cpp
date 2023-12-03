#include <iostream>
#include <list>
#include <vector>
#include "side_functions.h"
#include "student.h"

int main() {
    try {
        char containerType;
        std::cout << "Select container type (l for list, v for vector): ";
        std::cin >> containerType;

        if (containerType != 'l' && containerType != 'v') {
            std::cerr << "Invalid container type selected! Must be 'l' or 'v'." << std::endl;
            return 1;
        }

        int strategy;
        std::cout << "Select strategy (1 for Strategy 1, 2 for Strategy 2, 3 for Strategy 3): ";
        std::cin >> strategy;

        if (strategy != 1 && strategy != 2 && strategy != 3) {
            std::cerr << "Invalid strategy number! Must be 1, 2, or 3." << std::endl;
            return 1;
        }

        std::vector<int> sizes = {1000, 10000, 100000, 1000000};

        for (int size : sizes) {
            std::string filename = "students_" + std::to_string(size) + ".csv";

            if (containerType == 'l') {
                std::list<Student> students;
                processStudents(students, filename, strategy);
            } else { // Only other option is 'v', already checked earlier
                std::vector<Student> students;
                processStudents(students, filename, strategy);
            }
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "Processing completed successfully." << std::endl;
    return 0;
}
