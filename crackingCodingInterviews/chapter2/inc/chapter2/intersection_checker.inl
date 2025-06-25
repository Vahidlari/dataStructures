template <typename Ttype>
void CAppendableSinglyLinkedList<Ttype>::append(node_ptr_t node) {
    if (head == nullptr) {
        head = node;
    } else {
        tail->setNext(node);
        node_ptr_t newTail = node;
        while (newTail->getNext() != nullptr) {
            newTail = newTail->getNext();
            count++;
        }
        tail = newTail;
    }
}

template <typename Ttype>
typename CAppendableSinglyLinkedList<Ttype>::node_ptr_t CAppendableSinglyLinkedList<Ttype>::getHead() const {
    return head;
}

template <typename Ttype>
typename CAppendableSinglyLinkedList<Ttype>::node_ptr_t CAppendableSinglyLinkedList<Ttype>::getTail() const {
    return tail;
}

template <typename Ttype>
typename CAppendableSinglyLinkedList<Ttype>::node_ptr_t CAppendableSinglyLinkedList<Ttype>::getNodeAt(size_t n) const {
    if (n >= this->count) {
        return nullptr; // Index out of bounds
    }
    node_ptr_t current = head;
    for (size_t i = 0; i < n && current != nullptr; ++i) {
        current = current->getNext();
    }
    return current;
}

template <typename Ttype>
typename CAppendableSinglyLinkedList<Ttype>::node_ptr_t checkIntersection(
    const CAppendableSinglyLinkedList<Ttype>& list1,
    const CAppendableSinglyLinkedList<Ttype>& list2
) {
    using node_ptr_t = typename CAppendableSinglyLinkedList<Ttype>::node_ptr_t;
    if (list1.empty() || list2.empty() || list1.getTail() != list2.getTail()) {
        return nullptr; // If either list is empty, they cannot intersect
    }

    // Assume we know the size of the lists
	node_ptr_t currentList1 = list1.size() >= list2.size()? list1.getNodeAt(list1.size() - list2.size()) : list1.getHead();
	node_ptr_t currentList2 = list2.size() >= list1.size()? list2.getNodeAt(list2.size() - list1.size()) : list2.getHead();
	
	node_ptr_t intersectingNode = nullptr;
	
	while (intersectingNode == nullptr && currentList1 != nullptr && currentList2 != nullptr) {
		if (currentList1 == currentList2) {
			intersectingNode = currentList1;
		} else {
			currentList1 = currentList1->getNext();
			currentList2 = currentList2->getNext();
		}
	}
	
	return intersectingNode;
}