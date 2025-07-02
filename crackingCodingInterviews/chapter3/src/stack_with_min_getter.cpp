#include "chapter3/stack_with_min_getter.hpp"

void CStackWithMinGetter::push(size_t stackID, const data_t& value) {

    // Push the value onto the main stack
    dataStructures::CFlexibleMultiStack<int>::push(stackID, value);

    // If the min stack is empty or the value is less then the current minimum (peek value), push it onto the min stack
    if (minStack->isEmpty(defaultMinStackID) || value < data[minStack->peek(defaultMinStackID)]) {
        minStack->push(defaultMinStackID, getStackTopIndex(stackID));
    }
}

typename CStackWithMinGetter::data_t CStackWithMinGetter::pop(size_t stackID) {
    if (!minStack->isEmpty(defaultMinStackID) && getStackTopIndex(stackID) == minStack->peek(defaultMinStackID)) {
        // the current min value is being popped, so we need to pop it from the min stack as well
        minStack->pop(defaultMinStackID);
    }

    // Pop the value from the main stack
    return dataStructures::CFlexibleMultiStack<int>::pop(stackID);

}

typename CStackWithMinGetter::data_t CStackWithMinGetter::getMin() const {
    if (minStack->isEmpty(defaultMinStackID)) {
        throw std::out_of_range("Stack is empty, cannot get minimum value");
    }
    return data[ minStack->peek(defaultMinStackID) ];
}
