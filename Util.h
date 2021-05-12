#ifndef ASSIGN2_UTIL_H
#define ASSIGN2_UTIL_H

#include <string>

inline int charToInt(char c) {
    return c - '0';
}

void toLowerCase(std::string& s);

#endif