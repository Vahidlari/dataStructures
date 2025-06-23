# Chapter 1: Arrays and Strings

This folder contains my solutions to selected problems from Chapter 1 ("Arrays and Strings") of *Cracking the Coding Interview*.

## Topics Covered
- String manipulation
- Array operations
- Matrix rotation
- Hashing and bit manipulation for string problems

## Problems Solved

- **Check Permutation (1.2)**  
   *Given two strings, write a method to decide if one is a permutation of the other.*  
   [Implementation](src/permutation_checker.cpp) | [Header](inc/chapter1/permutation_checker.hpp)

- **Palindrome Permutation (1.4)**  
   *Check if a string is a permutation of a palindrome.*  
   [Implementation](src/palindromic_permutation.cpp) | [Header](inc/chapter1/palindromic_permutation.hpp)

- **One Away (1.5)**  
   *Check if two strings are one edit (or zero edits) away.*  
   [Implementation](src/one_edit_away_checker.cpp) | [Header](inc/chapter1/one_edit_away_checker.hpp)

- **String Compression (1.6)**  
   *Implement a method to perform basic string compression using the counts of repeated characters.*  
   [Implementation](src/string_compression.cpp) | [Header](inc/chapter1/string_compression.hpp)

- **Rotate Matrix (1.7)**  
   *Rotate an NxN matrix by 90 degrees.*  
   [Implementation](src/matrix_rotation.cpp) | [Header](inc/chapter1/matrix_rotation.hpp)

- **String Rotation (1.9)**  
  *Check if one string is a rotation of another using only one call to isSubstring.*
  [Implementation](src/string_rotation.cpp) | [Header](inc/chapter1/string_rotatio.hpp)

---

## Not Yet Implemented

- **Is Unique (1.1)**  
  *Implement an algorithm to determine if a string has all unique characters.*

- **URLify (1.3)**  
  *Replace all spaces in a string with '%20'.*

- **Zero Matrix (1.8)**  
  *If an element in an MxN matrix is 0, set its entire row and column to 0.*

---

Each problem is implemented in its own source/header files, with corresponding unit tests under the `tests/` directory.