#ifndef CHAPTER2_LOOP_DETECTION_HPP
#define CHAPTER2_LOOP_DETECTION_HPP

#include "dataStructures/singlyLinkedList.hpp"

/**
 * @file loop_detection.hpp
 * @brief Solution for Cracking the Coding Interview 2.8: Loop Detection
 * @problem
 * Given a singly linked list, determine if it contains a loop. If it does, return the node at which the loop begins. If there is no loop, return nullptr.
 */

 /**
  * @class CCircularSinglyLinkedList
  * @brief A class that implements a circular singly linked list with loop detection functionality
  * @details This class extends the CSinglyLinkedList class to provide methods for setting a loop and detecting the start of the loop in a circular singly linked list.
  * @tparam Ttype The type of data stored in the list (in this case, int)
  * @tparam PtrType The type of pointer used for the nodes (e.g., std::shared_ptr)
  */
class CCircularSinglyLinkedList : public dataStructures::CSinglyLinkedList<int, std::shared_ptr> {
public:
    using linked_list_t = dataStructures::CSinglyLinkedList<int, std::shared_ptr>;
    using node_ptr_t = typename linked_list_t::node_ptr_t;
    using node_t = typename linked_list_t::node_t;

    /**
     * @brief Default constructor
     */
    CCircularSinglyLinkedList() = default;

    /**
     * @brief Destructor
     */
    ~CCircularSinglyLinkedList() = default;

    /**
     * @brief set a loop by linking the last node to a specific node index
     * @param loopStartIndex The index of the node to which the last node will point to create a loop
     */
    void setLoop(size_t loopStartIndex);

    /**
     * @brief get the starting node of the loop in the list
     * @return The node at which the loop begins, or nullptr if there is no loop
     */
    node_ptr_t getLoopStart() const;

private:
    using linked_list_t::head;
    using linked_list_t::tail;
    using linked_list_t::count;

    /**
     * @brief two-pointer traversal algorithm for two given nodes
     * @param first The first node to traverse
     * @param firstSpeed The traversal speed of the first node
     * @param second The second node to traverse
     * @param secondSpeed The traversal speed of the second node
     * @return The node at which the two pointers meet, or nullptr if they never meet
     */
    node_ptr_t twoPointerTraversal(node_ptr_t first, size_t firstSpeed, node_ptr_t second, size_t secondSpeed) const;

    /**
     * @brief Get the node at a specific index
     * @param n The index of the node to retrieve
     * @return The node at the specified index, or nullptr if the index is out of bounds
     */
    node_ptr_t getNodeAt(size_t n) const;
};

#include "chapter2/loop_detection.inl"

#endif // CHAPTER2_LOOP_DETECTION_HPP