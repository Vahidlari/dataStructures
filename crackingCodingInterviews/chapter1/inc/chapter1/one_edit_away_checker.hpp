#ifndef ONE_EDIT_AWAY_CHECKER_HPP
#define ONE_EDIT_AWAY_CHECKER_HPP

#include <string>

/**
 * @file one_edit_away_checker.hpp
 * @brief Solution for Cracking the Coding Interview 1.5: One Away
 *
 * @problem
 * There are three types of edits that can be performed on a string: insert a character,
 * remove a character, or replace a character. Given two strings, write a function to check
 * if they are one edit (or zero edits) away.
 *
 * @example
 * Input: "pale", "ple"
 * Output: true (one deletion)
 *
 * Input: "pales", "pale"
 * Output: true (one insertion)
 *
 * Input: "pale", "bale"
 * Output: true (one replacement)
 *
 * Input: "pale", "bake"
 * Output: false (two replacements)
 *
 * @approach
 * We can compare the lengths of the two strings and determine the type of edit needed.
 * If the lengths differ by more than one, they cannot be one edit away. If they are the same,
 * we check for replacements; if they differ by one, we check for insertions or deletions.
 *
 * @complexity
 * Time: O(n) where n is the length of the shorter string
 * Space: O(1) since we only use a few variables for counting
 */
 bool isOneEditAway_usingLengthComparison(const std::string& str1, const std::string& str2);

 enum class OneEditAwayMethod {
     LengthComparison
 };
 /**
  * @brief Checks if two strings are one edit away using the specified method that is passed as a template parameter
  * 
  * @param str1 The first input string
  * @param str2 The second input string
  * @return true if the strings are one edit away or zero edits away
  * @return false if the strings are more than one edit away
  */
 template <OneEditAwayMethod method>
 bool isOneEditAway(const std::string& str1, const std::string& str2);
 
 #include "chapter1/one_edit_away_checker.inl"
#endif // ONE_EDIT_AWAY_CHECKER_HPP