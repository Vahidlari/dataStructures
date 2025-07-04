#include "chapter3/stack_of_plates.hpp"

CStackOfPlates::CStackOfPlates(size_t overalCapacity)
    : stack_t(overalCapacity, static_cast<size_t>((overalCapacity + stack_t::TStackMetadata::stackInitialCapacity - 1) / stack_t::TStackMetadata::stackInitialCapacity)) {
        // A stack is created to track the stacks of plates. This stack will hold the IDs of the stacks created.
        // The top of this stack will be the last stack created.
        createStack(stackTrackingStackID, static_cast<size_t>((overalCapacity + stack_t::TStackMetadata::stackInitialCapacity - 1) / stack_t::TStackMetadata::stackInitialCapacity));

        // Create the first stack to hold the actual data
        createStack(firstStackID, stack_t::TStackMetadata::stackInitialCapacity);
        stack_t::push(stackTrackingStackID, firstStackID);
}

void CStackOfPlates::push(const data_t& value) {
    try {
        stack_t::push(stack_t::peek(stackTrackingStackID), value);
    } catch (const std::out_of_range& e) {
        size_t newStackID = stack_t::peek(stackTrackingStackID) + 1;
        stack_t::createStack(newStackID, stack_t::TStackMetadata::stackInitialCapacity);
        stack_t::push(stackTrackingStackID, newStackID);
        stack_t::push(newStackID, value);
    }
}

typename CStackOfPlates::data_t CStackOfPlates::pop() {
    try {
        return stack_t::pop(stack_t::peek(stackTrackingStackID));
    } catch (const std::out_of_range& e) {
        size_t stackID = stack_t::pop(stackTrackingStackID);
        stack_t::deleteStack(stackID);
        return stack_t::pop(stack_t::peek(stackTrackingStackID));
    }
}

typename CStackOfPlates::data_t CStackOfPlates::peek() {
    return stack_t::peek(stack_t::peek(stackTrackingStackID));
}

bool CStackOfPlates::isEmpty() const {
    return stack_t::isEmpty(stack_t::peek(stackTrackingStackID));
}

size_t CStackOfPlates::getStackSize() const {
    // The stack size is the sum of the sizes of all stacks
    size_t stackSize = 0;
    for (size_t stackID = firstStackID; stackID < stack_t::getStackCount(); stackID++) {
        stackSize += stack_t::getStackSize(stackID);
    }
    return stackSize;
}