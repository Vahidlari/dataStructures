#ifndef PERMUTATION_CHECKER_HPP
#define PERMUTATION_CHECKER_HPP

#include <string>

/**
 * @file permutation_checker.hpp
 * @brief Solution for Cracking the Coding Interview 1.2: Check Permutation
 *
 * @problem
 * Given two strings, write a method to decide if one is a permutation of the other.
 * A permutation is a rearrangement of letters. The strings may contain ASCII characters.
 *
 * @example
 * Input: s1 = "abc", s2 = "bca"
 * Output: true
 *
 * Input: s1 = "abc", s2 = "def"
 * Output: false
 *
 * @assumptions
 * - Case sensitive: 'A' is different from 'a'
 * - Whitespace is significant
 * - ASCII character set (128 characters)
 */

/**
 * @brief Checks if two strings are permutations using character counting
 * 
 * This approach uses a fixed-size array to count characters in the first string
 * and then decrements counts for the second string.
 *
 * @param s1 First string
 * @param s2 Second string
 * @return true if s2 is a permutation of s1
 * @return false if s2 is not a permutation of s1
 * 
 * @complexity
 * Time: O(n) where n is the length of the strings
 * Space: O(1) as we use a fixed-size array of 128 characters
 */
bool isPermutation_usingCharCount(std::string s1, std::string s2);

/**
 * @brief Checks if two strings are permutations using sorting
 * 
 * This approach sorts both strings and then compares them for equality.
 * If they are permutations, the sorted strings will be identical.
 *
 * @param s1 First string
 * @param s2 Second string
 * @return true if s2 is a permutation of s1
 * @return false if s2 is not a permutation of s1
 * 
 * @complexity
 * Time: O(n log n) due to sorting
 * Space: O(1) if using in-place sort
 */
bool isPermutation_usingSort(std::string s1, std::string s2);

/**
 * @brief Checks if two strings are permutations using a hash table
 * 
 * This approach uses a hash table to count characters in the first string
 * and then checks the second string against these counts.
 *
 * @param s1 First string
 * @param s2 Second string
 * @return true if s2 is a permutation of s1
 * @return false if s2 is not a permutation of s1
 * 
 * @complexity
 * Time: O(n) where n is the length of the strings
 * Space: O(c) where c is the size of the character set
 */
bool isPermutation_usingHashTable(std::string s1, std::string s2);

enum class PermutationMethod {
    CharCount,
    Sort,
    HashTable
};
/**
 * @brief Checks if two strings are permutations using the specified method that is passed as a template parameter
 * 
 * This function allows the user to choose the method for checking permutations.
 *
 * @param s1 First string
 * @param s2 Second string
 * @return true if s2 is a permutation of s1
 * @return false if s2 is not a permutation of s1
 */
template <PermutationMethod method>
bool isPermutation(std::string s1, std::string s2);

#include "chapter1/permutation_checker.inl" // Include the implementation of template functions

#endif // PERMUTATION_CHECKER_HPP 