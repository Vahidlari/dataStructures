#ifndef CHAPTER2_SUM_LISTS_HPP
#define CHAPTER2_SUM_LISTS_HPP

#include "dataStructures/singlyLinkedList.hpp"

/* * @file sum_lists.hpp
 * @brief Solution for Cracking the Coding Interview 2.5: Sum Lists
 *
 * @problem
 * You have two numbers represented by a linked list, where each node contains a single digit. 
 * The digits are stored in reverse order, such that the 1's digit is at the head of the list. 
 * Implement a function that adds the two numbers and returns the sum as a linked list.
 * Example:
 * Input: (7 -> 1 -> 6) + (5 -> 9 -> 2)
 * Output: 2 -> 1 -> 9 (i.e., 617 + 295 = 912)
 *
 * I will implement three approaches, two for forward traverse and one for the backward. The ideas for the forward travers could be 
 * applied to the backward traverse as well, but I go for the simplest one for the backward traverse.
 *
 * @approach
 * 1. Forward Traverse - Sum of Product: Traverse both lists, multiply each digit by the appropriate power of 10, and sum the results.
 * 2. Forward Traverse - Sum of Digits: Traverse both lists, add corresponding digits, and handle carry-over.
 * 3. Reverse Traverse - Sum of Digits: Traverse both lists in reverse order, add corresponding digits, and handle carry-over.
 */

 enum class ESumListsMethod {
    FORWARD_TRAVERSE_SUM_OF_PRODUCT,
    FORWARD_TRAVERSE_SUM_OF_DIGITS,
    REVERSE_TRAVERSE_SUM_OF_DIGITS
 };

class CSummableLists: public dataStructures::CSinglyLinkedList<uint8_t> {
public:
    using node_ptr_t = typename dataStructures::CSinglyLinkedList<uint8_t>::node_ptr_t;
    using node_t     = typename dataStructures::CSinglyLinkedList<uint8_t>::node_t;

    /**
     * @brief Copy Constructor for CSummableLists
     * @param other The other list to copy from
     */
    CSummableLists(const CSummableLists& other) : dataStructures::CSinglyLinkedList<uint8_t>(other) {}

    /**
     * @brief Default Constructor for CSummableLists
     */
    CSummableLists() : dataStructures::CSinglyLinkedList<uint8_t>() {}

    /**
     * @brief Assignment operator for CSummableLists
     * @param other The other list to assign from
     * @return Reference to this list
     */
     CSummableLists& operator=(const CSummableLists& other);

    /**
     * @brief Adds two CSummableLists and returns the result as a new CSummableLists
     * @param other The other list to add
     * @param method The method to use for summation
     * @return A new CSummableLists containing the sum
     */
    template <ESumListsMethod method>
    static CSummableLists add(const CSummableLists& first, const CSummableLists& second);

    /**
     * @brief Helper function to convert an integer to a CSummableLists (digits in forward order)
     * @param value The integer value to convert
     * @return A new CSummableLists containing the digits of the integer in forward order
     */
    static CSummableLists fromIntegerForward(int value);

    /**
     * @brief Helper function to convert an integer to a CSummableLists (digits in reverse order)
     * @param value The integer value to convert
     * @return A new CSummableLists containing the digits of the integer in reverse order
     */
    static CSummableLists fromIntegerReverse(int value);

    /**
     * @brief Helper function to convert the list to an integer (digits in reverse order)
     * @return The integer value represented by the list
     */
    int forwardToInteger() const;

    /**
     * @brief Helper function to convert the list to an integer (digits in reverse order)
     * @return The integer value represented by the list
     */
    int reverseToInteger() const;

private:
    using dataStructures::CSinglyLinkedList<uint8_t>::head;
    using dataStructures::CSinglyLinkedList<uint8_t>::tail;
    using dataStructures::CSinglyLinkedList<uint8_t>::size;

    /**
     * @brief Helper function for forward traverse sum of product
     * @param other The other list to add
     * @return A new CSummableLists containing the sum
     */
    static CSummableLists forwardTraverseSumOfProduct(const CSummableLists& first, const CSummableLists& second);

    /**
     * @brief Helper function for forward traverse sum of digits
     * @param other The other list to add
     * @return A new CSummableLists containing the sum
     */
    static CSummableLists forwardTraverseSumOfDigits(const CSummableLists& first, const CSummableLists& second);

    /**
     * @brief Helper function for reverse traverse sum of digits
     * @param other The other list to add
     * @return A new CSummableLists containing the sum
     */
    static CSummableLists reverseTraverseSumOfDigits(const CSummableLists& first, const CSummableLists& second);

    /**
     * @brief Helper recursive function for reverse traverse sum of digits
     * @param first A pointer to a node inthe first list
     * @param second A pointer to a node in the second list
     * @param A reference to the result list
     * @return The carry from the addition
     */
    static uint8_t reverseTraverseSumOfDigits_recursive(node_ptr_t first, node_ptr_t second, CSummableLists& result);

    /**
     * @brief Helper function to add two digits with carry
     * @param digit1 The first digit
     * @param digit2 The second digit
     * @param carry The carry from the previous addition
     * @param 
     * @return The resulting digit after addition
     */
    static uint8_t addDigits(uint8_t digit1, uint8_t digit2, uint8_t carry, uint8_t& carryResult);
};

#include "chapter2/sum_lists.inl"

#endif // CHAPTER2_SUM_LISTS_HPP