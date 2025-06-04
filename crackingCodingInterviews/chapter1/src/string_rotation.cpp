#include "chapter1/string_rotation.hpp"

bool isStringRotation(const std::string& s1, const std::string& s2) {
    if (s1.length() != s2.length() || s1.empty()) {
        return false;
    }
    
    std::string concatenated = s1 + s1;
    return concatenated.find(s2) != std::string::npos;
}