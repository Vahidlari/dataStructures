#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include "chapter1/palindromic_permutation.hpp"

using namespace std;

bool isPalindromicPermutation_usingHashTable(string s) {
    unordered_map<char, int> count;
    
    // Count characters (ignoring spaces)
    for (char c : s) {
        if (!isspace(c)) {  // Skip spaces
            count[c]++;
        }
    }
    
    // Count characters with odd occurrences
    int oddCount = 0;
    for (const auto& pair : count) {
        if (pair.second % 2 == 1) {
            oddCount++;
            if (oddCount > 1) {  // More than one character has odd count
                return false;
            }
        }
    }
    
    // A palindrome can have at most one character with odd count
    return true;
}