template <typename Ttype>
CQueueUsingStacks<Ttype>::CQueueUsingStacks(size_t overalCapacity)
    : stack_t(overalCapacity * 2, stackCount) // Two stacks for the queue
{
    // Create two stacks for the queue
    createStack(pushStackID, overalCapacity);
    createStack(popStackID, overalCapacity);
}

template <typename Ttype>
void CQueueUsingStacks<Ttype>::enqueue(const data_t& value)
{
    if(stack_t::getStackSize(pushStackID) + stack_t::getStackSize(popStackID) >= stack_t::getStackCapacity(pushStackID)) {
        throw std::out_of_range("Queue is full, cannot enqueue.");
    }
    // Push the value onto the first stack
    stack_t::push(pushStackID, value);
}

template <typename Ttype>
typename CQueueUsingStacks<Ttype>::data_t CQueueUsingStacks<Ttype>::dequeue()
{
    if(stack_t::isEmpty(popStackID)) {
        // If the second stack is empty, we need to transfer elements from the first stack
        while(!stack_t::isEmpty(pushStackID)) {
            // Pop from the first stack and push onto the second stack
            data_t value = stack_t::pop(pushStackID);
            stack_t::push(popStackID, value);
        }
    }
    if(stack_t::isEmpty(popStackID)) {
        throw std::out_of_range("Queue is empty, cannot dequeue.");
    }
    // Pop from the second stack and return the value
    return stack_t::pop(popStackID);
}

template <typename Ttype>
typename CQueueUsingStacks<Ttype>::data_t CQueueUsingStacks<Ttype>::peek()
{
    if(stack_t::isEmpty(popStackID)) {
        // If the second stack is empty, we need to transfer elements from the first stack
        if(stack_t::isEmpty(pushStackID)) {
            throw std::out_of_range("Queue is empty, cannot peek.");
        }
        while(!stack_t::isEmpty(pushStackID)) {
            // Pop from the first stack and push onto the second stack
            data_t value = stack_t::pop(pushStackID);
            stack_t::push(popStackID, value);
        }
    }
    // Peek at the top of the second stack
    return stack_t::peek(popStackID);
}

template <typename Ttype>
bool CQueueUsingStacks<Ttype>::isEmpty() const
{
    // The queue is empty if both stacks are empty
    return stack_t::isEmpty(pushStackID) && stack_t::isEmpty(popStackID);
}

template <typename Ttype>
typename CQueueUsingStacks<Ttype>::size_t CQueueUsingStacks<Ttype>::getQueueSize() const
{
    // The size of the queue is the sum of the sizes of both stacks
    return stack_t::getStackSize(pushStackID) + stack_t::getStackSize(popStackID);
}

template <typename Ttype>
typename CQueueUsingStacks<Ttype>::size_t CQueueUsingStacks<Ttype>::getQueueCapacity() const
{
    // The capacity of the queue is the sum of the capacities of both stacks
    return stack_t::getStackCapacity(pushStackID);
}