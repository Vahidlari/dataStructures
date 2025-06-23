
template <ESumListsMethod method>
CSummableLists CSummableLists::add(const CSummableLists& first, const CSummableLists& second) {
    if constexpr (method == ESumListsMethod::FORWARD_TRAVERSE_SUM_OF_PRODUCT)
    {
        return forwardTraverseSumOfProduct(first, second);
    }
    else if constexpr (method == ESumListsMethod::FORWARD_TRAVERSE_SUM_OF_DIGITS)
    {
        return forwardTraverseSumOfDigits(first, second);
    }
    else // ESumListsMethod::REVERSE_TRAVERSE_SUM_OF_DIGITS
    {
        return reverseTraverseSumOfDigits(first, second);
    }
}

inline CSummableLists& CSummableLists::operator=(const CSummableLists& other) {
    if (this != &other) {
        dataStructures::CSinglyLinkedList<uint8_t>::operator=(other);
    }
    return *this;
}