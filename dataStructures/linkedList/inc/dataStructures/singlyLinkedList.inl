#include <stdexcept>

namespace dataStructures {

template <typename Ttype, template<typename> class PtrType>
CSinglyLinkedList<Ttype, PtrType>::CSinglyLinkedList() : head(nullptr), tail(nullptr), count(0) {}

template <typename Ttype, template<typename> class PtrType>
CSinglyLinkedList<Ttype, PtrType>::~CSinglyLinkedList() {
    clear();
}

template <typename Ttype, template<typename> class PtrType>
CSinglyLinkedList<Ttype, PtrType>::CSinglyLinkedList(const CSinglyLinkedList& other)
    : head(nullptr), tail(nullptr), count(0) {
    node_ptr_t current = other.head;
    while (current != nullptr) {
        pushBack(current->getData());
        current = current->getNext();
    }
}

template <typename Ttype, template<typename> class PtrType>
CSinglyLinkedList<Ttype, PtrType>& CSinglyLinkedList<Ttype, PtrType>::operator=(const CSinglyLinkedList& other) {
    if (this != &other) {
        clear();
        node_ptr_t current = other.head;
        while (current != nullptr) {
            pushBack(current->getData());
            current = current->getNext();
        }
    }
    return *this;
}

template <typename Ttype, template<typename> class PtrType>
void CSinglyLinkedList<Ttype, PtrType>::pushFront(const data_t& value) {
    node_ptr_t newNode = PtrType<node_t>(new node_t(value));
    newNode->setNext(head);
    head = newNode;
    
    if (tail == nullptr) {
        tail = head;
    }
    count++;
}

template <typename Ttype, template<typename> class PtrType>
void CSinglyLinkedList<Ttype, PtrType>::pushBack(const data_t& value) {
    node_ptr_t newNode = PtrType<node_t>(new node_t(value));

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->setNext(newNode);
        tail = newNode;
    }
    count++;
}


template <typename Ttype, template<typename> class PtrType>
typename CSinglyLinkedList<Ttype, PtrType>::data_t CSinglyLinkedList<Ttype, PtrType>::popFront() {
    if (head == nullptr) {
        throw std::runtime_error("List is empty!");
    }

    node_ptr_t lastHead = head;
    data_t headValue = lastHead->getData();
    head = head->getNext();
    if (head == nullptr) {
        tail = nullptr;
    }
    delete lastHead;
    count--;
    return headValue;
}

template <typename Ttype, template<typename> class PtrType>
auto CSinglyLinkedList<Ttype, PtrType>::popBack() -> data_t {
    if(head == nullptr) {
        throw std::runtime_error("List is empty!");
    }
    
    data_t tailValue = tail->getData();
    if(tail == head) {
        // The list has a single element
        if constexpr (std::is_same_v<PtrType<node_t>, dataStructures::raw_ptr<node_t>>) {
            // If using raw pointers, we need to delete it manually
            delete tail;
        }
        head = tail = nullptr;
    } else {
        node_ptr_t oneButLastNode = head;
        while(oneButLastNode->getNext() != tail) {
            oneButLastNode = oneButLastNode->getNext();
        }
        if constexpr (std::is_same_v<PtrType<node_t>, dataStructures::raw_ptr<node_t>>) {
            // If using raw pointers, we need to delete it manually
            delete tail;
        }

        tail = oneButLastNode;
        tail->setNext(nullptr);
    }
    count--;
    return tailValue;
}

template <typename Ttype, template<typename> class PtrType>
bool CSinglyLinkedList<Ttype, PtrType>::remove(const data_t& value) {
    if(head == nullptr) {
        return false;
    }
    
    node_ptr_t currentNode = head;
    node_ptr_t previousNode = head;

    bool found = false;
    while(!found && currentNode != nullptr) {
        if(currentNode->getData() == value) {
            found = true;
        } else {
            previousNode = currentNode;
            currentNode = currentNode->getNext();
        }
    }

    if(found) {
        if(currentNode == head) {
            // The first node to be removed
            if(head == tail) {
                // The list has only one element
                head = tail = nullptr;
            } else {
                head = head->getNext();
            }
        } else if(currentNode == tail) {
            tail = previousNode;
            tail->setNext(nullptr);
        } else {
            previousNode->setNext(currentNode->getNext());
        }
        if constexpr (std::is_same_v<PtrType<node_t>, dataStructures::raw_ptr<node_t>>) {
            // If using raw pointers, we need to delete it manually
            delete currentNode;
        }
        count--;
    }
    return found;
}

template <typename Ttype, template<typename> class PtrType>
auto CSinglyLinkedList<Ttype, PtrType>::at(size_t position) const -> const data_t& {
    if (position >= count) {
        throw std::out_of_range("Position out of range");
    }

    node_ptr_t current = head;
    for(size_t i = 0; i < position; i++) {
        current = current->getNext();
    }
    const data_t& value = current->getData();
    return value;
}

template <typename Ttype, template<typename> class PtrType>
bool CSinglyLinkedList<Ttype, PtrType>::contains(const data_t& value) const {
    if(head == nullptr) {
        return false;
    }
    bool found = false;
    node_ptr_t current = head;
    while(!found && current != nullptr) {
        if(current->getData() == value) {
            found = true;
        } else {
            current = current->getNext();
        }
    }
    return found;
}

template <typename Ttype, template<typename> class PtrType>
inline auto CSinglyLinkedList<Ttype, PtrType>::size() const -> size_t {
    return count;
}

template <typename Ttype, template<typename> class PtrType>
inline bool CSinglyLinkedList<Ttype, PtrType>::empty() const {
    return (head == nullptr || count == 0);
}

template <typename Ttype, template<typename> class PtrType>
void CSinglyLinkedList<Ttype, PtrType>::reverse() {
    if (head == tail) {
        return;
    }
    node_ptr_t prev = nullptr;
    node_ptr_t current = head;
    tail = head;

    while(current != nullptr) {
        node_ptr_t next = current->getNext();
        current->setNext(prev);
        prev = current;
        current = next;
    }
    head = prev;
}

template <typename Ttype, template<typename> class PtrType>
void CSinglyLinkedList<Ttype, PtrType>::clear() {
    if (head == nullptr) {
        return;
    }

    if constexpr (std::is_same_v<PtrType<node_t>, dataStructures::raw_ptr<node_t>>) {
        // If using raw pointers, we need to delete them manually
        node_ptr_t current = head;
        while(current != nullptr) {
            node_ptr_t temp = current;
            current = current->getNext();
            delete temp;
        }
        head = tail = nullptr;
        count = 0;
    } else {
        // If using smart pointers, they will be automatically cleaned up
        head.reset();
        tail.reset();
        count = 0;
        return;
    }

}

template <typename Ttype, template<typename> class PtrType>
void CSinglyLinkedList<Ttype, PtrType>::insert(size_t position, const data_t& value) {
    if(position > count) {
        throw std::out_of_range("Position out of range");
    }

    
    node_ptr_t newNode;
    if constexpr (std::is_same_v<PtrType<node_t>, dataStructures::raw_ptr<node_t>>) {
        // If using raw pointers, we need to allocate memory manually
        newNode = new node_t(value);
    } else {
        // If using smart pointers, we can use make_shared or make_unique
        newNode = PtrType<node_t>::make_shared(value);
    }
    if(position == 0) {
        newNode->setNext(head);
        head = newNode;
    } else {
        node_ptr_t current = head;
        for(size_t i = 0; i < position - 1; i++) {
            current = current->getNext();
        }
        newNode->setNext(current->getNext());
        current->setNext(newNode);
        if(position == count) {
            tail = newNode;
        }
    }
    count++;
}

template <typename Ttype, template<typename> class PtrType>
bool CSinglyLinkedList<Ttype, PtrType>::operator==(const CSinglyLinkedList& other) const {
    if (count != other.count) {
        return false;
    }

    node_ptr_t current1 = head;
    node_ptr_t current2 = other.head;

    while (current1 != nullptr && current2 != nullptr) {
        if (current1->getData() != current2->getData()) {
            return false;
        }
        current1 = current1->getNext();
        current2 = current2->getNext();
    }

    return true; // Both lists are equal
}

template <typename Ttype, template<typename> class PtrType>
bool CSinglyLinkedList<Ttype, PtrType>::operator!=(const CSinglyLinkedList& other) const {
    return !(*this == other); // Use the equality operator to determine inequality
}


} // namespace dataStructures
