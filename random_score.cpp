#include "random_score.h"
#include <random>
#include <ctime>

// Function to generate a random score between min and max inclusive
int generateRandomScore(int min, int max) {
    // Initialize the random number generator with a seed based on the current time
    static std::mt19937 rng(std::time(nullptr));
    std::uniform_int_distribution<int> dist(min, max);  // Define the distribution to be between min and max inclusive
    
    // Generate and return a random number in the specified range
    return dist(rng);
}
