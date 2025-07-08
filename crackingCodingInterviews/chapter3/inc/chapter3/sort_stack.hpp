#ifndef CHAPTER3_SORT_STACK_HPP
#define CHAPTER3_SORT_STACK_HPP

#include "dataStructures/flexibleMultiStack.hpp"


/**
 * @file sort_stack.hpp
 * @brief Solution for Cracking the Coding Interview 3.5: Sort Stack (using a temporary stack)
 * @problem
 * Write a program to sort a stack such that the smallest items are on the top.
 * You can use an additional temporary stack, but you may not copy the elements into any other data structure (such as an array).
 * The stack supports the following operations: push, pop, peek, and isEmpty.
 * @note The implementation is based on the CFlexibleMultiStack class.
 * @note For the sake of simplicity, the implementation is based on integer values.
 */

class CSortStack : public dataStructures::CFlexibleMultiStack<int> {
public:
    using stack_t = dataStructures::CFlexibleMultiStack<int>; ///< Type alias for the base stack type
    using size_t  = typename stack_t::size_t; ///< Type alias for size_t
    using data_t  = typename stack_t::data_t; ///< Type alias for the data type

    CSortStack(size_t overalCapacity = stack_t::defaultCapacity);

    ~CSortStack() = default;
    
    void push(const data_t& value);

    data_t pop();

    data_t peek();

    bool isEmpty() const;

private:
    constexpr static size_t stackCount = 2; ///< Number of stacks used in the queue
    constexpr static size_t mainStackID = 0; ///< ID of the main stack
    constexpr static size_t tempStackID = 1; ///< ID of the temporary stack

    using stack_t::createStack;
    using stack_t::deleteStack;
    using stack_t::push;
    using stack_t::pop;
    using stack_t::peek;
    using stack_t::isEmpty;
    using stack_t::getStackSize;
    using stack_t::getStackCapacity;
};


#endif // CHAPTER3_SORT_STACK_HPP