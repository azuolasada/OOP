#include "random_score.h"
#include <random>
#include <ctime>

int generateRandomScore(int min, int max) {
    static std::mt19937 rng(std::time(nullptr));  // Seed the random number generator
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}
