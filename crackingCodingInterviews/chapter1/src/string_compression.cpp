#include "chapter1/string_compression.hpp"


std::string compressString(const std::string& str) {
    if (str.length() <= 1) {
        return str;
    }
    int repeatCount = 1;
    char lastCh = str[0];
    std::string cmpStr;
    for (std::size_t i = 1; i < str.length(); i++) {
        if (str[i] == lastCh) {
            repeatCount++;
        } else {
            cmpStr += lastCh; 
            cmpStr += std::to_string(repeatCount);
            lastCh = str[i];
            repeatCount = 1;
        }
    }
    cmpStr += lastCh + std::to_string(repeatCount);
    // If the compressed string is not shorter than the original, return the original string
    return cmpStr.length() < str.length() ? cmpStr : str;
}