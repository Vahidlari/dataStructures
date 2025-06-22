template <typename Ttype>
template <EPartitionMethod partitionMethod>
inline void CPartitionAroundAValue<Ttype>::partitionAroundAValue(data_t value){
    if constexpr (partitionMethod == EPartitionMethod::USING_TWO_SUB_LISTS) {
        partitionAroundAValue_usingTwoSubLists(value);
    } else if constexpr (partitionMethod == EPartitionMethod::USING_MOVE_TO_HEAD) {
        partitionAroundAValue_usingMoveToHead(value);
    } 
}

template <typename Ttype>
inline typename CPartitionAroundAValue<Ttype>::node_ptr_t 
CPartitionAroundAValue<Ttype>::getHead() const{
    return head;
}

template <typename Ttype>
inline typename CPartitionAroundAValue<Ttype>::node_ptr_t 
CPartitionAroundAValue<Ttype>::getTail() const{
    return tail;
}

template <typename Ttype>
inline void CPartitionAroundAValue<Ttype>::appendList(const CPartitionAroundAValue<Ttype>& list){
    if(list.getHead() == nullptr){
        return;
    }
    node_ptr_t current = list.getHead();
    while(current != nullptr){
        this->pushBack(current->getData());
        current = current->getNext();
    }
}

template <typename Ttype>
void CPartitionAroundAValue<Ttype>::partitionAroundAValue_usingTwoSubLists(data_t value) {
    node_ptr_t current = head;
    CPartitionAroundAValue<Ttype> lessList{};
    CPartitionAroundAValue<Ttype> greaterList{};
    
    while (current != nullptr) {
        if (current->getData() < value) {
            lessList.pushBack(current->getData());
        } else {
            greaterList.pushBack(current->getData());
        }
        current = current->getNext();
    }
    
    lessList.appendList(greaterList);
    current = head;
    node_ptr_t combinedListCurrent = lessList.getHead();
    
    while (current != nullptr) {
        current->setData(combinedListCurrent->getData());
        current = current->getNext();
        combinedListCurrent = combinedListCurrent->getNext();
    }
    
}

template <typename Ttype>
void CPartitionAroundAValue<Ttype>::partitionAroundAValue_usingMoveToHead(data_t value){
    if(head == nullptr || head->getNext() == nullptr){
        return;
    }
    node_ptr_t prev = head;
    node_ptr_t current = head->getNext();
    while(current != nullptr){
        if(current->getData() < value){
            prev->setNext(current->getNext());
            current->setNext(head);
            head = current;
        } else {
            prev = current;
        }
        current = prev->getNext();
    }
}
