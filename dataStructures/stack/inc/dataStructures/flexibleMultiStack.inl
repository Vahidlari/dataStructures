#include <algorithm>

namespace dataStructures
{
template <typename Ttype>
CFlexibleMultiStack<Ttype>::CFlexibleMultiStack(size_t initialCapacity, size_t maxStacks)
    : totalReservedCapacity(0),
      stackCount(0),
      maxNumberOfStacks(maxStacks),
      data(),
      stacks()
{
    data.reserve(initialCapacity);
}

template <typename Ttype>
CFlexibleMultiStack<Ttype>::~CFlexibleMultiStack()
{
    // Destructor does not need to do anything special since std::vector manages its own memory
}

template <typename Ttype>
typename CFlexibleMultiStack<Ttype>::EStackCreationResult CFlexibleMultiStack<Ttype>::createStack(size_t stackID) {
    return createStack(stackID, TStackMetadata::stackInitialCapacity);
}

template <typename Ttype>
size_t CFlexibleMultiStack<Ttype>::getStackCount() const {
    return stacks.size();
}

template <typename Ttype>
typename CFlexibleMultiStack<Ttype>::EStackCreationResult CFlexibleMultiStack<Ttype>::createStack(size_t stackID, size_t capacity) {
    if (stacks.size() >= maxNumberOfStacks) {
        return EStackCreationResult::OVERFLOW; // Maximum number of stacks reached
    }

    if (isValidStackID(stackID)) {
        return EStackCreationResult::INVALID_STACK_ID;
    }

    if (capacity < 1) {
        return EStackCreationResult::INVALID_CAPACITY;
    }

    if (totalReservedCapacity + capacity > data.capacity()) {
        // The size of the data vector is not enough to accommodate a new stack
        return EStackCreationResult::OVERFLOW;
    }

    // The new stack is allocated at the end of the data vector. Find the end of the the last stack using its base index and capacity
    // Loop through the stacks and find the stack with the highest base index
    size_t newStackBaseIndex = 0;
    for (const auto& stack : stacks) {
        if (stack.second.baseIndex + stack.second.capacity > newStackBaseIndex) {
            newStackBaseIndex = stack.second.baseIndex + stack.second.capacity;
        }
    }

    if (newStackBaseIndex + capacity > data.capacity()) {
        // The size of the data vector is not enough to accommodate a new stack
        return EStackCreationResult::OVERFLOW;
    }

    stacks.emplace(stackID, TStackMetadata(newStackBaseIndex, capacity));
    totalReservedCapacity += capacity;
    return EStackCreationResult::SUCCESS;
}

template <typename Ttype>
void CFlexibleMultiStack<Ttype>::deleteStack(size_t stackID) {
    if (!isValidStackID(stackID)) {
        throw std::out_of_range("Invalid stack index");
    }

    // Remove the stack from the stacks vector
    totalReservedCapacity -= stacks[stackID].capacity;
    stacks.erase(stackID);
    // Perform memory tetris to make space for new stacks
    performMemoryTetris();
}

template <typename Ttype>
void CFlexibleMultiStack<Ttype>::push(size_t stackID, const Ttype& value) {
    if (!isValidStackID(stackID)) {
        throw std::out_of_range("Invalid stack index");
    }

    if (stacks[stackID].size == stacks[stackID].capacity) {
        throw std::out_of_range("Stack is full");
    }

    size_t topIndex = (stacks[stackID].size == 0) ? stacks[stackID].baseIndex : calculateTopIndex(stackID, true);

    data[topIndex] = value;
    stacks[stackID].top = topIndex;
    stacks[stackID].size++;
}

template <typename Ttype>
Ttype CFlexibleMultiStack<Ttype>::pop(size_t stackID) {
    if (!isValidStackID(stackID)) {
        throw std::out_of_range("Invalid stack index");
    }

    if (isEmpty(stackID)) {
        throw std::out_of_range("Stack is empty");
    }

    data_t value = data[stacks[stackID].top];
    data[stacks[stackID].top] = data_t();
    stacks[stackID].top = calculateTopIndex(stackID, false);
    stacks[stackID].size--;
    return value;
}

template <typename Ttype>
Ttype CFlexibleMultiStack<Ttype>::peek(size_t stackID) const {
    if (!isValidStackID(stackID)) {
        throw std::out_of_range("Invalid stack index");
    }

    if (isEmpty(stackID)) {
        throw std::out_of_range("Stack is empty");
    }

    return data[stacks.at(stackID).top];
}

template <typename Ttype>
bool CFlexibleMultiStack<Ttype>::isEmpty(size_t stackID) const {
    if (!isValidStackID(stackID)) {
        throw std::out_of_range("Invalid stack index");
    }
    return stacks.at(stackID).size == 0;
}

template <typename Ttype>
size_t CFlexibleMultiStack<Ttype>::getStackSize(size_t stackID) const {
    if (!isValidStackID(stackID)) {
        throw std::out_of_range("Invalid stack index");
    }
    return stacks.at(stackID).size;
}

template <typename Ttype>
size_t CFlexibleMultiStack<Ttype>::getStackCapacity(size_t stackID) const {
    if (!isValidStackID(stackID)) {
        throw std::out_of_range("Invalid stack index");
    }
    return stacks.at(stackID).capacity;
}

template <typename Ttype>
bool CFlexibleMultiStack<Ttype>::performMemoryTetris() {
    // Check if the data vector is full
    if (data.size() == totalReservedCapacity) {
        return false;
    }

    // Check if the data vector is empty
    if (totalReservedCapacity == 0) {
        return true;
    }

    // Sort stacks by base index to process them in order
    std::vector<std::pair<size_t, TStackMetadata>> sortedStacks;
    for (const auto& stack : stacks) {
        sortedStacks.push_back(stack);
    }
    std::sort(sortedStacks.begin(), sortedStacks.end(), 
              [](const auto& a, const auto& b) { return a.second.baseIndex < b.second.baseIndex; });

    // Check if there are any gaps by verifying if stacks are contiguous
    size_t expectedBaseIndex = 0;
    bool gapsExist = false;
    
    for (const auto& stack : sortedStacks) {
        if (stack.second.baseIndex > expectedBaseIndex) {
            gapsExist = true;
            break;
        }
        expectedBaseIndex = stack.second.baseIndex + stack.second.capacity;
    }

    if (!gapsExist) {
        return true; // No gaps to fix
    }

    // Perform the shifting to eliminate all gaps
    size_t newBaseIndex = 0;
    for (auto& stackPair : sortedStacks) {
        size_t oldBase = stackPair.second.baseIndex;
        size_t stackSize = stackPair.second.size;
        size_t stackCapacity = stackPair.second.capacity;
        
        // Only shift if the stack is not already at the correct position
        if (oldBase != newBaseIndex) {
            // Move elements to the new position
            for (size_t i = 0; i < stackSize; i++) {
                size_t oldIndex = oldBase + i;
                size_t newIndex = newBaseIndex + i;
                data[newIndex] = std::move(data[oldIndex]);
            }
            
            // Clear the old positions (optional, but good for debugging)
            for (size_t i = stackSize; i < stackCapacity; i++) {
                size_t oldIndex = oldBase + i;
                data[oldIndex] = data_t();
            }
            
            // Update stack metadata
            stacks[stackPair.first].baseIndex = newBaseIndex;
            stacks[stackPair.first].top = newBaseIndex + stackSize - 1;
        }
        
        // Move to the next expected position
        newBaseIndex += stackCapacity;
    }

    return true;
}

template <typename Ttype>
size_t CFlexibleMultiStack<Ttype>::getStackBaseIndex(size_t stackID) const {
    return isValidStackID(stackID) ? stacks.at(stackID).baseIndex : -1;
}

template <typename Ttype>
size_t CFlexibleMultiStack<Ttype>::getStackTopIndex(size_t stackID) const {
    return isValidStackID(stackID) ? stacks.at(stackID).top : -1;
}

template <typename Ttype>
bool CFlexibleMultiStack<Ttype>::isValidStackID(size_t stackID) const {
    return stacks.find(stackID) != stacks.end();
}

template <typename Ttype>
size_t CFlexibleMultiStack<Ttype>::calculateTopIndex(size_t stackID, bool pushOperation) const {
    // If the push operation is true, we need to calculate the top index for the next element
    // If the push operation is false, we need to calculate the top index for the previous element
    // The calculation should consider a circular buffer
    size_t topIndex = stacks.at(stackID).top;
    if (pushOperation) {
        topIndex = (topIndex + 1) % data.capacity();
    } else {
        topIndex = (topIndex - 1) % data.capacity();
    }
    return topIndex;
}
} // namespace dataStructures