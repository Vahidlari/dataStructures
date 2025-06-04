#ifndef PALINDROMIC_PERMUTATION_HPP
#define PALINDROMIC_PERMUTATION_HPP

#include <string>

/**
 * @file palindromic_permutation.hpp
 * @brief Solution for Cracking the Coding Interview 1.4: Palindrome Permutation
 *
 * @problem
 * Given a string, write a function to check if it is a permutation of a palindrome.
 * A palindrome is a word or phrase that is the same forwards and backwards. A
 * permutation is a rearrangement of letters. The palindrome does not need to be
 * limited to just dictionary words.
 *
 * @example
 * Input: "tact coa"
 * Output: true (permutations: "taco cat", "atco cta", etc.)
 *
 * @approach
 * A string can be rearranged into a palindrome if and only if at most one character
 * appears an odd number of times. We use a hash table to count character frequencies
 * and check this condition.
 *
 * @complexity
 * Time: O(n) where n is the length of the string
 * Space: O(c) where c is the size of the character set
 */

/**
 * @brief Checks if a string is a permutation of a palindrome using a hash table approach
 * 
 * @param s The input string to check
 * @return true if the string can be rearranged to form a palindrome
 * @return false if the string cannot be rearranged to form a palindrome
 */
bool isPalindromicPermutation_usingHashTable(std::string s);

/**
 * @brief Checks if a string is a permutation of a palindrome using bit manipulation
 * 
 * @param s The input string to check
 * @return true if the string can be rearranged to form a palindrome
 * @return false if the string cannot be rearranged to form a palindrome
 */
bool isPalindromicPermutation_usingBitManipulation(std::string s);

enum class PalindromicPermutationMethod {
    HashTable,
    BitManipulation
};

/**
 * @brief Checks if a string is a permutation of a palindrome using the specified method that is passed as a template parameter
 * 
 * @param s The input string to check
 * @return true if the string can be rearranged to form a palindrome
 * @return false if the string cannot be rearranged to form a palindrome
 */

template <PalindromicPermutationMethod method>
bool isPalindromicPermutation(std::string s);

#include "chapter1/palindromic_permutation.inl"
 
#endif // PALINDROMIC_PERMUTATION_HPP