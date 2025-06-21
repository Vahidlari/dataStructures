
template <typename Ttype, EGetKthToLastMethod method>
inline typename CGetKthToLast<Ttype, method>::node_ptr_t CGetKthToLast<Ttype, method>::getKthToLast(size_t k) {
    if constexpr (method == EGetKthToLastMethod::TWO_POINTERS) {
        return k > count || k == 0 ? nullptr : getKthToLast_twoPointers(k);
    } else if constexpr (method == EGetKthToLastMethod::RECURSIVE) {
        size_t index = 0;
        return k > count || k == 0 ? nullptr : getKthToLast_recursive(k, head, index);
    }
}

template <typename Ttype, EGetKthToLastMethod method>
inline typename CGetKthToLast<Ttype, method>::node_ptr_t CGetKthToLast<Ttype, method>::getKthToLast_twoPointers(size_t k) {
    node_ptr_t current = head;
    node_ptr_t runner = current;

    for (size_t i = 0; i < k; i++) {
        if (runner == nullptr) {
            return nullptr;
        }
        runner = runner->getNext();
    }

    while (runner != nullptr) {
        current = current->getNext();
        runner = runner->getNext();
    }

    return current;
}

template <typename Ttype, EGetKthToLastMethod method>
inline typename CGetKthToLast<Ttype, method>::node_ptr_t CGetKthToLast<Ttype, method>::getKthToLast_recursive(size_t k, node_ptr_t currentNode, size_t& index) {
    node_ptr_t ret = nullptr;
    if(currentNode->getNext() != nullptr) {
        ret = getKthToLast_recursive(k, currentNode->getNext(), index);
        index++;
    } else {
        index = 1;
    }
    if (index == k) {
        ret = currentNode;
    }
    return ret;
}
