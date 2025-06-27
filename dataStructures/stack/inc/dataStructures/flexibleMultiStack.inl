CFlexibleMultiStack<Ttype>::CFlexibleMultiStack(size_t initialCapacity)
    : initialCapacity(initialCapacity), totalSize(0), stackCount(0)
{
    data.reserve(initialCapacity);
}

template <typename Ttype>
CFlexibleMultiStack<Ttype>::~CFlexibleMultiStack()
{
    // Destructor does not need to do anything special since std::vector manages its own memory
}

template <typename Ttype>
typename CFlexibleMultiStack<Ttype>::size_t CFlexibleMultiStack<Ttype>::createStack() {
    if (totalReservedCapacity + TStackMetadata::stackInitialCapacity > data.capacity()) {
        // The size of the data vector is not enough to accommodate a new stack
        return invalidStackIndex;
    }

    size_t stackIndex = stackCount++;
    stacks.emplace_back(getStackBaseIndex(stackIndex), TStackMetadata::stackInitialCapacity);
    totalReservedCapacity += stacks[stackIndex].capacity;
    return stackIndex;
}


template <typename Ttype>
typename CFlexibleMultiStack<Ttype>::size_t CFlexibleMultiStack<Ttype>::createStack(size_t initialCapacity) {
    if (totalReservedCapacity + initialCapacity > data.capacity()) {
        // The size of the data vector is not enough to accommodate a new stack
        return invalidStackIndex;
    }

    size_t stackIndex = stackCount++;
    stacks.emplace_back(getStackBaseIndex(stackIndex), initialCapacity);
    totalReservedCapacity += stacks[stackIndex].capacity;
    return stackIndex;
}

template <typename Ttype>
bool CFlexibleMultiStack<Ttype>::increaseCapacity(size_t stackIndex, size_t newCapacity) {
    if (!isValidStackIndex(stackIndex)) {
        throw std::out_of_range("Invalid stack index");
    }

    if (newCapacity < calculateUsedCapacity(stackIndex)) {
        throw std::out_of_range("New capacity is less than current size");
    }

    if ( newCapacity + totalReservedCapacity > data.capacity()) {
        // The size of the data vector is not enough to accommodate the new capacity
        return false;
    }

    totalReservedCapacity += newCapacity - stacks[stackIndex].capacity;
    // Increase the capacity of the stack
    stacks[stackIndex].capacity = newCapacity;
    return true;
}

