#include "chapter3/sort_stack.hpp"

CSortStack::CSortStack(size_t overalCapacity)
    : stack_t(overalCapacity * 2, stackCount) {
    createStack(mainStackID, overalCapacity);
    createStack(tempStackID, overalCapacity);
}

void CSortStack::push(const data_t& value) {
    if (getStackSize(mainStackID) >= getStackCapacity(mainStackID)) {
        throw std::out_of_range("Stack is full");
    }

    while(!isEmpty(mainStackID) && peek(mainStackID) < value) {
        push(tempStackID, pop(mainStackID));
    }
    push(mainStackID, value);
    while(!isEmpty(tempStackID)) {
        push(mainStackID, pop(tempStackID));
    }
}

typename CSortStack::data_t CSortStack::pop() {
    return pop(mainStackID);
}

typename CSortStack::data_t CSortStack::peek() {
    return peek(mainStackID);
}

bool CSortStack::isEmpty() const {
    return isEmpty(mainStackID);
}

