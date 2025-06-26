#include "chapter2/loop_detection.hpp"

typename CCircularSinglyLinkedList::node_ptr_t CCircularSinglyLinkedList::getLoopStart() const {
    // Let fast and slow runner pointers to traverse the list and get the collision point. 
    node_ptr_t collisionNode = twoPointerTraversal(head, 1, head, 2);

    if (collisionNode == nullptr) {
        // No loop detected and returning nullptr
        return nullptr;
    }

    // The head of the list has the same distance to the loop start, as the collisionNode
    node_ptr_t loopStart = twoPointerTraversal(head, 1, collisionNode, 1);
    return loopStart;
}

typename CCircularSinglyLinkedList::node_ptr_t CCircularSinglyLinkedList::twoPointerTraversal(node_ptr_t first, size_t firstSpeed, node_ptr_t second, size_t secondSpeed) const {
    if (first == nullptr || second == nullptr || firstSpeed == 0 || secondSpeed == 0) {
        return nullptr;
    }

    if (first == second && firstSpeed == secondSpeed) {
        return first; // If both pointers are the same and speeds are equal, return the node
    }

    do {
        for (size_t i = 0; i < firstSpeed && first != nullptr; ++i) {
            first = first->getNext();
        }
        for (size_t i = 0; i < secondSpeed && second != nullptr; ++i) {
            second = second->getNext();
        }
    } while (first != second && first != nullptr && second != nullptr);
    return first == second ? first : nullptr;
}
