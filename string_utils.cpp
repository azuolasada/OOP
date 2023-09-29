#include "string_utils.h"

int extractNumericPart(const std::string& str) {
    size_t i = 0;
    while (i < str.size() && !isdigit(str[i])) {
        ++i;
    }

    if (i == str.size()) {
        return -1;  // No numeric part found.
    }

    size_t start = i;
    while (i < str.size() && isdigit(str[i])) {
        ++i;
    }

    return std::stoi(str.substr(start, i - start));
}

std::string extractNonNumericPart(const std::string& str) {
    std::string result;
    for (char c : str) {
        if (!isdigit(c)) {
            result += c;
        }
    }
    return result;
}
