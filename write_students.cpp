#include <fstream>

void writeStudentsToFile(const std::vector<Student>& students, const std::string& filename) {
    std::ofstream out(filename);
    out << "Name,Surname,FinalScore\n";
    for (const auto& student : students) {
        out << student.name << "," << student.surname << "," << student.finalScore << "\n";
    }
}