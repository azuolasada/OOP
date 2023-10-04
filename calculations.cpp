#include "calculations.h"
#include <numeric>
#include <algorithm>

// Function to compute the mean of a set of integers
double computeMean(const std::vector<int>& results) {
    // std::accumulate computes the sum of the results, divided by the number of elements to get the mean
    return std::accumulate(results.begin(), results.end(), 0.0) / results.size();
}

// Function to compute the median of a set of integers
double computeMedian(const std::vector<int>& results) {
    size_t size = results.size();
    std::vector<int> sortedResults = results;
    std::sort(sortedResults.begin(), sortedResults.end());  // Sorting the results to find the median

    // Check whether the size is even or odd and compute median accordingly
    if (size % 2 == 0) {
        // If even, return the average of the two middle elements
        return (sortedResults[size / 2 - 1] + sortedResults[size / 2]) / 2.0;
    } else {
        // If odd, return the middle element
        return sortedResults[size / 2];
    }
}