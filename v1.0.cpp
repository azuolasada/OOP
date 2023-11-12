#include <iostream>
#include <list>
#include <vector>
#include "side_functions.h"

int main() {
    try {
        char containerType;
        std::cout << "Select container type (l for list, v for vector): ";
        std::cin >> containerType;

        // Define the sizes of student data files to be processed.
        std::vector<int> sizes = {1000, 10000, 100000, 1000000};

        for (int size : sizes) {
            std::string filename = "students_" + std::to_string(size) + ".csv";

            if (containerType == 'l') {
                std::list<Student> students;
                processStudents(students, filename);
            } else if (containerType == 'v') {
                std::vector<Student> students;
                processStudents(students, filename);
            } else {
                std::cerr << "Invalid container type selected!" << std::endl;
                return 1;
            }
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
