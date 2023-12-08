#include <iostream>
#include <list>
#include <vector>
#include "side_functions.h"

int main() {
    try {
        char containerType, inputMethod, displayMethod;
        std::cout << "Select container type (l for list, v for vector): ";
        std::cin >> containerType;

        int strategy;
        std::cout << "Select strategy (1 for Strategy 1, 2 for Strategy 2, 3 for Strategy 3): ";
        std::cin >> strategy;
        if (strategy != 1 && strategy != 2 && strategy != 3) {
            throw std::runtime_error("Invalid strategy number!");
        }

        std::cout << "Choose input method (m for manual, f for file): ";
        std::cin >> inputMethod;
        if (inputMethod != 'm' && inputMethod != 'f') {
            throw std::runtime_error("Invalid input method selected!");
        }

        std::cout << "Choose display method (s for screen, f for file): ";
        std::cin >> displayMethod;
        if (displayMethod != 's' && displayMethod != 'f') {
            throw std::runtime_error("Invalid display method selected!");
        }

        std::string sortCriterion;
        std::cout << "Select sort criterion (name, surname, finalScore): ";
        std::cin >> sortCriterion;

        // Define the sizes of student data files to be processed.
        std::vector<int> sizes = {1000, 10000, 100000, 1000000};

        for (int size : sizes) {
            std::string filename = "students_" + std::to_string(size) + ".csv";

            if (inputMethod == 'f') {
                if (containerType == 'l') {
                    std::list<Student> students;
                    processStudents(students, filename, strategy, sortCriterion);
                    if (displayMethod == 's') {
                        displayStudents(students);
                    }
                } else if (containerType == 'v') {
                    std::vector<Student> students;
                    processStudents(students, filename, strategy, sortCriterion);
                    if (displayMethod == 's') {
                        displayStudents(students);
                    }
                }
            } else if (inputMethod == 'm') {
                std::cout << "Enter the number of students: ";
                int numStudents;
                std::cin >> numStudents;
                std::cin.ignore(); // Clear the newline character left in the buffer

                if (containerType == 'l') {
                    std::list<Student> students;
                    for (int i = 0; i < numStudents; ++i) {
                        students.push_back(inputStudentManually());
                    }
                    if (displayMethod == 's') {
                        displayStudents(students);
                    }
                } else if (containerType == 'v') {
                    std::vector<Student> students;
                    for (int i = 0; i < numStudents; ++i) {
                        students.push_back(inputStudentManually());
                    }
                    if (displayMethod == 's') {
                        displayStudents(students);
                    }
                }
            }
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
