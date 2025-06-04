#ifndef STRING_COMPRESSION_HPP
#define STRING_COMPRESSION_HPP

#include <string>

/**
 * @file string_compression.hpp
 * @brief Solution for Cracking the Coding Interview 1.6: String Compression
 *
 * @problem
 * Implement a method to perform basic string compression using the counts of repeated characters.
 * For example, the string "aabcccccaaa" would become "a2b1c5a3". If the compressed string is not
 * smaller than the original string, your method should return the original string.
 *
 * @example
 * Input: "aabcccccaaa"
 * Output: "a2b1c5a3"
 *
 * @approach
 * Iterate through the string, count consecutive characters, and build the compressed string.
 *
 * @complexity
 * Time: O(n) where n is the length of the string
 * Space: O(n) for the compressed string in the worst case
 */
std::string compressString(const std::string& input);

#endif // STRING_COMPRESSION_HPP