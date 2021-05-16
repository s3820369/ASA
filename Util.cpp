#include <iostream>
#include "Util.h"

void toLowerCase(std::string& s) {
    for(unsigned int i = 0; i < s.length(); ++i)
        s[i] = tolower(s[i]);        
}


std::vector<std::string> splitString(std::string string, std::string delimiter) {
    std::vector<std::string> split = {};
    std::string token;
    size_t pos = 0;

    for(int i = 0; (pos = string.find(delimiter)) != std::string::npos; ++i) {
        token = string.substr(0, pos);
        std::cout << token << " " << std::endl;
        split.push_back(token);
        string.erase(0, pos + delimiter.length());
    }
    // Edge case
    if(string != "")
        split.push_back(string);
    return split;
}