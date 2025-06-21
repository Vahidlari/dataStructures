#ifndef CHAPTER2_REMOVE_MIDDLE_NODE_HPP
#define CHAPTER2_REMOVE_MIDDLE_NODE_HPP

#include "dataStructures/singlyLinkedList.hpp"

/**
 * @file remove_middle_node.hpp
 * @brief Solution for Cracking the Coding Interview 2.3: Delete a node in the middle of a linked list
 *
 * @problem
 * Implement an algorithm to delete a node in the middle (i.e., any node but the first and last node, not necessarily the exact middle) of a singly linked list, given only access to that node.
 */

template <typename Ttype>
class CRemoveMiddleNode: public dataStructures::CSinglyLinkedList<Ttype> {
public:
    using node_ptr_t = typename dataStructures::CSinglyLinkedList<Ttype>::node_ptr_t;
    using node_t     = typename dataStructures::CSinglyLinkedList<Ttype>::node_t;
    using data_t     = typename dataStructures::CSinglyLinkedList<Ttype>::data_t;

    /**
     * @brief Remove the middle node
     * @param data The data of the node to remove
     * @note The node must not be the last node.
     */
    bool removeMiddleNode(data_t data);

private:
    using dataStructures::CSinglyLinkedList<Ttype>::count;
    using dataStructures::CSinglyLinkedList<Ttype>::head;

    /**
     * @brief Remove the middle node
     * @param node The node to remove
     * @note The node must not be the last node. This method is a helper method for removeMiddleNode(data_t data).
     */
    bool removeMiddleNode(node_ptr_t node);

    /**
     * @brief Get the node with the given data
     * @param data The data to search for
     * @return The node with the given data
     */    
    node_ptr_t getNode(data_t data) const;
};


#include "chapter2/remove_middle_node.inl"

#endif // CHAPTER2_REMOVE_MIDDLE_NODE_HPP