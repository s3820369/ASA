#ifndef ASSIGN2_UTIL_H
#define ASSIGN2_UTIL_H

#include <string>
#include <vector>

// Conversion of single digit numbers to int
inline int charToInt(char c) {
    return c - '0';
}

// Helper method for double digit column parsing
inline int doubleDigitCol(std::string& loc) {
    return charToInt(loc[1]) * 10 + charToInt(loc[2]);
}

// Convert string to lowercase, was going to be used for indifference in
// capitals in commands, may not be used
void toLowerCase(std::string& s);

std::vector<std::string> splitString(std::string string, std::string delimiter);


#endif