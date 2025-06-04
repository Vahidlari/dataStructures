#ifndef STRING_ROTATION_HPP
#define STRING_ROTATION_HPP

#include <string>

/**
 * @file string_rotation.hpp
 * @brief Solution for Cracking the Coding Interview 1.9: String Rotation
 *
 * @problem
 * Given two strings, s1 and s2, write a method to check if s2 is a rotation of s1.
 * For example, "waterbottle" is a rotation of "erbottlewat".
 *
 * @approach
 * We can check if s2 is a substring of s1 concatenated with itself.
 *
 * @complexity
 * Time: O(N) where N is the length of the strings
 * Space: O(N) for the concatenated string
 */

 bool isStringRotation(const std::string& s1, const std::string& s2);



#endif // STRING_ROTATION_HPP