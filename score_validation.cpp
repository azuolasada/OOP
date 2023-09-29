#include "score_validation.h"

// Function to check whether a given score is valid according to predetermined criteria
bool isValidScore(int score) {
    // The score is valid if it is between 1 and 10 inclusive
    return score >= 1 && score <= 10;
}
