#include <unordered_set>

template <typename Ttype, ERemovalMethod removalMethod>
void CLinkedListDuplicatesRemover<Ttype, removalMethod>::removeDuplicates() {
    if constexpr (removalMethod == ERemovalMethod::HASH) {
        removeDuplicates_usingHash();
    }
    else if constexpr (removalMethod == ERemovalMethod::IN_PLACE) {
        removeDuplicates_inPlace();
    }
}

template <typename Ttype, ERemovalMethod removalMethod>
void CLinkedListDuplicatesRemover<Ttype, removalMethod>::removeDuplicates_usingHash() {
    std::unordered_set<Ttype> existingValues;
    node_ptr_t currentNode = head;
    node_ptr_t previousNode = nullptr;

    while (currentNode != nullptr) {
        if (existingValues.count(currentNode->getData()) > 0) {
            // Value existing --> removing the current node
            previousNode->setNext(currentNode->getNext());
            node_ptr_t tmp = currentNode;
            currentNode = currentNode->getNext();
            delete tmp;
            count--;
        } else {
            // Value not existing --> adding it to the set
            existingValues.insert(currentNode->getData());
            previousNode = currentNode;
            currentNode = currentNode->getNext();
        }
    }
}

template <typename Ttype, ERemovalMethod removalMethod>
void CLinkedListDuplicatesRemover<Ttype, removalMethod>::removeDuplicates_inPlace(){
    node_ptr_t currentNode = head;

    while (currentNode != nullptr) {
        node_ptr_t runner = currentNode;
        while (runner->getNext() != nullptr) {
            if (runner->getNext()->getData() == currentNode->getData()) {
                node_ptr_t tmp = runner->getNext();
                runner->setNext(runner->getNext()->getNext());
                delete tmp;
                count--;
            } else {
                runner = runner->getNext();
            }
        }
        currentNode = currentNode->getNext();
    }
}