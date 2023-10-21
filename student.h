#pragma once
#include <string>
#include <list>

struct Student {
    std::string name;
    std::string surname;
    std::list<int> homeworkResults;
    int examResult;
    double finalScore;
};