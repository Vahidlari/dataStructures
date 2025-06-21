template <typename Ttype>
inline bool CRemoveMiddleNode<Ttype>::removeMiddleNode(data_t data) {
    node_ptr_t node = getNode(data);
    if (node != nullptr) {
        return removeMiddleNode(node);
    }
    return false;
}

template <typename Ttype>
typename CRemoveMiddleNode<Ttype>::node_ptr_t CRemoveMiddleNode<Ttype>::getNode(data_t data) const {
    node_ptr_t current = head;
    while (current != nullptr) {
        if (current->getData() == data) {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}

template <typename Ttype>
bool CRemoveMiddleNode<Ttype>::removeMiddleNode(node_ptr_t node){
	if(node->getNext() == nullptr){
		return false;
	}
	node->setData(node->getNext()->getData());
	node_ptr_t tmp = node->getNext();
	node->setNext(node->getNext()->getNext());
	delete tmp;
    count--;
	return true;
}
