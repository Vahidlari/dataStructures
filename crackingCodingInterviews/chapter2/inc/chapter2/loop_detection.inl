
inline void CCircularSinglyLinkedList::setLoop(size_t loopStartIndex) {
    if (loopStartIndex >= count) {
        return;
    }

    node_ptr_t loopStart = getNodeAt(loopStartIndex);
    if (loopStart == nullptr) {
        return;
    }

    tail->setNext(loopStart);
}

inline typename CCircularSinglyLinkedList::node_ptr_t CCircularSinglyLinkedList::getNodeAt(size_t n) const {
    if (n >= count || head == nullptr) {
        return nullptr;
    }

    node_ptr_t current = head;

    for (size_t i = 0; i < n; ++i) {
        current = current->getNext();
    }
    return current;
}