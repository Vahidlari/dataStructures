#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include "chapter1/permutation_checker.hpp"

using namespace std;

bool isPermutation_usingCharCount(string s1, string s2) {
    if (s1.length() != s2.length()) {
        return false;
    }

    int count[128] = {0};
    for (int i = 0; i < s1.length(); i++) {
        count[s1[i]]++;
    }
    for (int i = 0; i < s2.length(); i++) {
        count[s2[i]]--;
    }
    for (int i = 0; i < 128; i++) {
        if (count[i] != 0) {
            return false;
        }
    }
    return true;
}

bool isPermutation_usingSort(string s1, string s2) {
    if (s1.length() != s2.length()) {
        return false;
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

bool isPermutation_usingHashTable(string s1, string s2) {
    if (s1.length() != s2.length()) {
        return false;
    }
    
    unordered_map<char, int> count;
    // Count characters in first string
    for (char c : s1) {
        count[c]++;
    }
    
    // Check characters in second string
    for (char c : s2) {
        if (count.find(c) == count.end() || count[c] == 0) {
            return false;
        }
        count[c]--;
    }
    
    // Verify all counts are zero
    for (const auto& pair : count) {
        if (pair.second != 0) {
            return false;
        }
    }
    
    return true;
}
