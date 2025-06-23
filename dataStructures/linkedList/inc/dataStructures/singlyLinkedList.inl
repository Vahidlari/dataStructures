#include <stdexcept>

namespace dataStructures {

template <typename Ttype>
CSinglyLinkedList<Ttype>::CSinglyLinkedList() : head(nullptr), tail(nullptr), count(0) {}

template <typename Ttype>
CSinglyLinkedList<Ttype>::~CSinglyLinkedList() {
    clear();
}

template <typename Ttype>
CSinglyLinkedList<Ttype>::CSinglyLinkedList(const CSinglyLinkedList& other)
    : head(nullptr), tail(nullptr), count(0) {
    node_ptr_t current = other.head;
    while (current != nullptr) {
        pushBack(current->getData());
        current = current->getNext();
    }
}

template <typename Ttype>
CSinglyLinkedList<Ttype>& CSinglyLinkedList<Ttype>::operator=(const CSinglyLinkedList& other) {
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

template <typename Ttype>
void CSinglyLinkedList<Ttype>::pushFront(const data_t& value) {
    node_ptr_t newNode = new node_t(value);
    newNode->setNext(head);
    head = newNode;
    
    if (tail == nullptr) {
        tail = head;
    }
    count++;
}

template <typename Ttype>
void CSinglyLinkedList<Ttype>::pushBack(const data_t& value) {
    node_ptr_t newNode = new node_t(value);

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->setNext(newNode);
        tail = newNode;
    }
    count++;
}

template <typename Ttype>
typename CSinglyLinkedList<Ttype>::data_t CSinglyLinkedList<Ttype>::popFront() {
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

template <typename Ttype>
auto CSinglyLinkedList<Ttype>::popBack() -> data_t {
	if(head == nullptr) {
		throw std::runtime_error("List is empty!");
	}
	
	data_t tailValue = tail->getData();
	if(tail == head) {
		// The list has a single element
		delete tail;
		head = tail = nullptr;
	} else {
		node_ptr_t oneButLastNode = head;
		while(oneButLastNode->getNext() != tail) {
			oneButLastNode = oneButLastNode->getNext();
		}
		delete tail;
		tail = oneButLastNode;
		tail->setNext(nullptr);
	}
	count--;
	return tailValue;
}

template <typename Ttype>
bool CSinglyLinkedList<Ttype>::remove(const data_t& value) {
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
		delete currentNode;
		count--;
	}
	return found;
}

template <typename Ttype>
auto CSinglyLinkedList<Ttype>::at(size_t position) const -> const data_t& {
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

template <typename Ttype>
bool CSinglyLinkedList<Ttype>::contains(const data_t& value) const {
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

template <typename Ttype>
inline auto CSinglyLinkedList<Ttype>::size() const -> size_t {
	return count;
}

template <typename Ttype>
inline bool CSinglyLinkedList<Ttype>::empty() const {
	return (head == nullptr || count == 0);
}

template <typename Ttype>
void CSinglyLinkedList<Ttype>::reverse() {
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

template <typename Ttype>
void CSinglyLinkedList<Ttype>::clear() {
	if (head == nullptr) {
		return;
	}

	node_ptr_t current = head;
	while(current != nullptr) {
		node_ptr_t temp = current;
		current = current->getNext();
		delete temp;
	}
	head = tail = nullptr;
	count = 0;
}

template <typename Ttype>
void CSinglyLinkedList<Ttype>::insert(size_t position, const data_t& value) {
	if(position > count) {
		throw std::out_of_range("Position out of range");
	}

    node_ptr_t newNode = new node_t(value);
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

} // namespace dataStructures
