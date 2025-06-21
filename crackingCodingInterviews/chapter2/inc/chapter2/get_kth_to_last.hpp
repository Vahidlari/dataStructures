#ifndef CHAPTER2_GET_KTH_TO_LAST_HPP
#define CHAPTER2_GET_KTH_TO_LAST_HPP

#include "dataStructures/singlyLinkedList.hpp"

/**
 * @file get_kth_to_last.hpp
 * @brief Solution for Cracking the Coding Interview 2.2: Return Kth to Last
 *
 * @problem
 * Implement an algorithm to find the kth to last element of a singly linked list.
 *
 * @approach
 * We can use two pointers to find the kth to last element.
 * We can also use a recursive approach to find the kth to last element.
 *
 */

enum class EGetKthToLastMethod {
    TWO_POINTERS,
    RECURSIVE
};

/**
 * @brief A class that finds the kth to last element of a singly linked list
 * @tparam Ttype The type of the data in the linked list
 * @tparam method The method to use to find the kth to last element
 */
template <typename Ttype, EGetKthToLastMethod method>
class CGetKthToLast: public dataStructures::CSinglyLinkedList<Ttype> {
public:
    using node_ptr_t = typename dataStructures::CSinglyLinkedList<Ttype>::node_ptr_t;
    using node_t     = typename dataStructures::CSinglyLinkedList<Ttype>::node_t;

    /**
     * @brief Get the kth to last element of the linked list
     * @param k The index of the element to get
     * @return The kth to last element of the linked list
     */
    node_ptr_t getKthToLast(size_t k);

private:
    using dataStructures::CSinglyLinkedList<Ttype>::head;
    using dataStructures::CSinglyLinkedList<Ttype>::count;

    /**
     * @brief Get the kth to last element of the linked list using two pointers
     * @param k The index of the element to get
     * @return The kth to last element of the linked list
     */
    node_ptr_t getKthToLast_twoPointers(size_t k);

    /**
     * @brief Get the kth to last element of the linked list using recursion
     * @param k The index of the element to get
     * @param currentNode The current node
     * @param index The index of the current node
     * @return The kth to last element of the linked list
     */
    node_ptr_t getKthToLast_recursive(size_t k, node_ptr_t currentNode, size_t& index);
};

#include "chapter2/get_kth_to_last.inl"

#endif // CHAPTER2_GET_KTH_TO_LAST_HPP