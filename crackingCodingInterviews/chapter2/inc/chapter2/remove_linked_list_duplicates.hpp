#ifndef REMOVE_LINKED_LIST_DUPLICATES_HPP
#define REMOVE_LINKED_LIST_DUPLICATES_HPP

#include <dataStructures/singlyLinkedList.hpp>

/**
 * @file remove_linked_list_duplicates.hpp
 * @brief Solution for Cracking the Coding Interview 2.1: Remove Duplicates
 *
 * @problem
 * Write code to remove duplicates from an unsorted linked list.
 *
 * @approach
 * We can use a hash table to keep track of the elements we have seen.
 * We can also use two pointers to remove duplicates in place.
 */

/**
 * @brief The method to use to remove duplicates
 */
enum class ERemovalMethod {
    HASH,
    IN_PLACE
};

/**
 * @brief A class that removes duplicates from a linked list
 * @tparam Ttype The type of the data in the linked list
 * @tparam removalMethod The method to use to remove duplicates
 */
template <typename Ttype, ERemovalMethod removalMethod>
class CLinkedListDuplicatesRemover: public dataStructures::CSinglyLinkedList<Ttype> {
public:
    using node_ptr_t = typename dataStructures::CSinglyLinkedList<Ttype>::node_ptr_t;
    using node_t     = typename dataStructures::CSinglyLinkedList<Ttype>::node_t;

    /**
     * @brief Removes duplicates from the linked list
     * @note This method uses the removal method specified in the template parameter to call the appropriate method
     */
    void removeDuplicates();

private:
    // Make protected members accessible for internal implementation
    using dataStructures::CSinglyLinkedList<Ttype>::head;
    using dataStructures::CSinglyLinkedList<Ttype>::tail;
    using dataStructures::CSinglyLinkedList<Ttype>::count;

    /**
     * @brief Removes duplicates from the linked list using a hash table
     * @note This method uses a hash table to remove duplicates and the time complexity is O(n)
     * @note The space complexity is O(n)
     */
    void removeDuplicates_usingHash();

    /**
     * @brief Removes duplicates from the linked list in place using two pointers
     * @note This method uses two pointers to remove duplicates in place and the time complexity is O(n^2)
     * @note The space complexity is O(1)
     */
    void removeDuplicates_inPlace();
};

#include "chapter2/remove_linked_list_duplicates.inl"

#endif // REMOVE_LINKED_LIST_DUPLICATES_HPP
