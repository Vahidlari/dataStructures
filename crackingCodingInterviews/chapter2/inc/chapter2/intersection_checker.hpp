#ifndef CHAPTER2_INTERSECTION_CHECKER_HPP
#define CHAPTER2_INTERSECTION_CHECKER_HPP

#include "dataStructures/singlyLinkedList.hpp"

/**
 * @file intersection_checker.hpp
 * @brief Solution for Cracking the Coding Interview 2.7: Intersection
 * @problem
 * Given two singly linked lists, determine if the two lists intersect. Return the intersecting node. Note that the intersection is defined based on reference, not value.
 */

 /**
  * @brief A singly linked list that can append nodes to the end of the list. Note that this class extends the CSinglyLinkedList class.
  * @tparam Ttype The type of the data in the linked list.
  * @note The appended node could be a part of another linked list. In this case, all the subsequent nodes will be part of the same linked list
  * and the tail of the list will be the same as the tail of the other linked list.
  */
template <typename Ttype>
class CAppendableSinglyLinkedList: public dataStructures::CSinglyLinkedList<Ttype, std::shared_ptr> {
public:
    using linked_list_t = dataStructures::CSinglyLinkedList<Ttype, std::shared_ptr>;
    using node_ptr_t = typename linked_list_t::node_ptr_t;
    using node_t     = typename linked_list_t::node_t;

    /**
     * @brief Append a node to the end of the list
     * @param node The node to append
     */
    void append(node_ptr_t node);

    /**
     * @brief Get the head of the list
     * @return The head of the list
     */
    node_ptr_t getHead() const;

    /**
     * @brief Get the tail of the list
     * @return The tail of the list
     */
    node_ptr_t getTail() const;

    /**
     * @brief Get the referece to the nth node in the list
     * @param n The index of the node to get
     * @return The node at the specified index, or nullptr if the index is out of bounds
     */
    node_ptr_t getNodeAt(size_t n) const;

private:
    using linked_list_t::head;
    using linked_list_t::tail;
    using linked_list_t::count;
};

/**
 * @brief Check if two singly linked lists intersect
 * @param list1 The first singly linked list
 * @param list2 The second singly linked list
 * @return The intersecting node if the lists intersect, nullptr otherwise
 */
template <typename Ttype>
typename CAppendableSinglyLinkedList<Ttype>::node_ptr_t checkIntersection(
    const CAppendableSinglyLinkedList<Ttype>& list1,
    const CAppendableSinglyLinkedList<Ttype>& list2
);

#include "chapter2/intersection_checker.inl"

#endif // CHAPTER2_INTERSECTION_CHECKER_HPP