#ifndef CHAPTER3_QUEUE_USING_STACKS_HPP
#define CHAPTER3_QUEUE_USING_STACKS_HPP

#include "dataStructures/flexibleMultiStack.hpp"

 /**
  * @file queue_using_stacks.hpp
  * @brief Solution for Cracking the Coding Interview 3.4: Queue using Stacks
  * @problem
  * Implement a MyQueue class which implements a queue using two stacks.
  * @note The implementation is based on the CFlexibleMultiStack class.
  */

template <typename Ttype>
class CQueueUsingStacks: public dataStructures::CFlexibleMultiStack<Ttype>
{
public:
    using stack_t = dataStructures::CFlexibleMultiStack<Ttype>; ///< Type alias for the base stack type
    using size_t  = typename stack_t::size_t; ///< Type alias for size_t
    using data_t  = typename stack_t::data_t; ///< Type alias for the data type

    CQueueUsingStacks(size_t overalCapacity = stack_t::defaultCapacity);

    ~CQueueUsingStacks() = default;

    /**
     * @brief Enqueues a value into the queue
     * @param value The value to enqueue
     */
    void enqueue(const data_t& value);
    
    /**
     * @brief Dequeues a value from the queue
     * @return The value dequeued from the queue
     * @note If the queue is empty, it will throw an exception.
     */
    data_t dequeue();

    /**
     * @brief Peeks at the front value of the queue without removing it
     * @return The value at the front of the queue
     * @note If the queue is empty, it will throw an exception.
     */
    data_t peek();

    /**
     * @brief Checks if the queue is empty
     * @return true if the queue is empty, false otherwise
     */
    bool isEmpty() const;

    /**
     * @brief Gets the size of the queue
     * @return The size of the queue
     */
    size_t getQueueSize() const;

    /**
     * @brief Gets the capacity of the queue
     * @return The capacity of the queue
     */
    size_t getQueueCapacity() const;
private:
    constexpr static size_t pushStackID = 0; ///< ID of the push stack
    constexpr static size_t popStackID = 1; ///< ID of the pop stack
    constexpr static size_t stackCount = 2; ///< Number of stacks used in the queue
    using stack_t::createStack;
    using stack_t::deleteStack;
    using stack_t::push;
    using stack_t::pop;
    using stack_t::peek;
    using stack_t::isEmpty;
    using stack_t::getStackSize;
};

#include "chapter3/queue_using_stacks.inl"

#endif // CHAPTER3_QUEUE_USING_STACKS_HPP