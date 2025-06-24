#ifndef PALINDROME_CHECKER_HPP
#define PALINDROME_CHECKER_HPP

#include "dataStructures/singlyLinkedList.hpp"
#include <string>
#include <utility>

/**
 * @file palindrome_checker.hpp
 * @brief Solution for Cracking the Coding Interview 2.6: Palindrome
 * @problem
 * Implement a function to check if a linked list is a palindrome.
 * @approach
 * We can use a two-pointer technique to check if the linked list is a palindrome.
 * We can also use a stack to check if the linked list is a palindrome.
 * @note
 * This class extends the CSinglyLinkedList class to provide functionality for checking if a linked list is a palindrome.
 * It does not add any new data members, but provides methods to check for palindromes using the existing singly linked list structure.
 * The class is designed to be used with characters, but can be adapted for other types as needed.
 * @tparam Ttype The type of the data in the linked list, default is char
 */

enum class EPalindromeLinkedListCheckerMethod {
    COMPARE_WITH_REVERSAL,
    USING_STACK,
    RECURSIVE
};

class CPalindromeChecker: public dataStructures::CSinglyLinkedList<char> {
public:
    using node_ptr_t = typename dataStructures::CSinglyLinkedList<char>::node_ptr_t;
    using node_t     = typename dataStructures::CSinglyLinkedList<char>::node_t;
    using result_t   = typename std::pair<node_ptr_t, bool>;

    /**
     * @brief Default constructor
     */
    CPalindromeChecker() = default;

    /**
     * @brief Constructor that initializes the linked list with a string
     * @param str The string to initialize the linked list with
     */
    CPalindromeChecker(const std::string& str);

    /**
     * @brief Check if the linked list is a palindrome
     * @param method The method to use for checking the palindrome
     * @return true if the linked list is a palindrome, false otherwise
     */
    template <EPalindromeLinkedListCheckerMethod method>
    bool isPalindrome() const;

private:
    using dataStructures::CSinglyLinkedList<char>::head;
    using dataStructures::CSinglyLinkedList<char>::count;

    /**
     * @brief Check if the linked list is a palindrome using a stack
     * @return true if the linked list is a palindrome, false otherwise
     * @note This method uses a stack to store the characters of the first half of the linked list,
     * and then compares them with the second half of the linked list.
     * This is a straightforward approach that uses O(n) space and O(n) time complexity.
     */
    bool isPalindrome_usingStack() const;

    /**
     * @brief Check if the linked list is a palindrome by comparing with its reversal
     * @return true if the linked list is a palindrome, false otherwise
     * @note This method reverses the linked list and compares it with the original.
     * It uses O(n) time and O(n) space complexity.
     */
    bool isPalindrome_compareWithReversal() const;

    /**
     * @brief Check if the linked list is a palindrome using recursion
     * @param currentNode The current node being checked
     * @param index The index of the current node in the linked list
     * @return true if the linked list is a palindrome, false otherwise
     * @note This method uses recursion to compare characters from both ends of the linked list.
     * It uses O(n) time and O(n) space complexity due to recursion stack.
     */
    result_t isPalindrome_recursive(node_ptr_t currentNode, size_t index) const;
};

#include "chapter2/palindrome_checker.inl"

#endif // PALINDROME_CHECKER_HPP