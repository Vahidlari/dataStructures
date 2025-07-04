#ifndef CHAPTER3_STACK_OF_PLATES_HPP
#define CHAPTER3_STACK_OF_PLATES_HPP

#include "dataStructures/flexibleMultiStack.hpp"

/**
 * @file stack_of_plates.hpp
 * @brief Solution for Cracking the Coding Interview 3.3: Stack of Plates
 * @problem
 * Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
 * Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold.
 * Implement a data structure SetOfStacks that mimics this. SetOfStacks should be composed of several stacks and should create a new stack once the previous one exceeds capacity.
 * SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single stack (that is, pop() should return the same values as it would if there were just a single stack).
 * FOLLOW UP: Implement a function popAt(int index) which performs a pop operation on a specific sub-stack.
 *
 * @note The implementation is based on the CFlexibleMultiStack class.
 * @note The implementation allows for a single stack to be externally created, however, the internal stacks are created automatically.
 */

/**
 * @brief Implementation of the SetOfStacks data structure
 * @note The implementation is based on the CFlexibleMultiStack class.
 * @note The implementation allows for a single stack to be externally created, however, the internal stacks are created automatically.
 * The solution could be implemented by instantiating multiple objects of CFlexibleMultiStack<int>, each creating a single stack, and managing them in a similiar way. 
 * However, to keep the implementation simple and efficient, we use a single CFlexibleMultiStack<int> instance to manage multiple stacks internally.
 */
class CStackOfPlates: public dataStructures::CFlexibleMultiStack<int>
{
public:
    using stack_t = dataStructures::CFlexibleMultiStack<int>; ///< Type alias for the base stack type
    using size_t  = stack_t::size_t; ///< Type alias for size_t
    using data_t  = stack_t::data_t; ///< Type alias for the data type

    CStackOfPlates(size_t overalCapacity = stack_t::defaultCapacity);

    ~CStackOfPlates() override = default;

    /**
     * @brief Pushes a value onto the stack
     * @param value The value to push onto the stack
     */
    void push(const data_t& value) ;

    /**
     * @brief Pops a value from the stack
     * @return The value popped from the stack
     */
    data_t pop();

    /**
     * @brief Pops a value from the stack at a specific index
     * @param index The index of the stack to pop from
     * @return The value popped from the stack
     */
    data_t popAt(size_t index);

    /**
     * @brief Peeks at the top value of the stack without removing it
     * @return The value at the top of the stack
     */
    data_t peek();

    /**
     * @brief Checks if the stack is empty
     * @return True if the stack is empty, false otherwise
     */
    bool isEmpty() const;

    /**
     * @brief Gets the size of the stack
     * @return The size of the stack
     */
    size_t getStackSize() const;


private: 
    constexpr static size_t stackTrackingStackID = 0; ///< ID of the stack used to track the created stacks as stackOfPlates
    constexpr static size_t firstStackID = 1; ///< ID of the first stack created to store the actual data
    using dataStructures::CFlexibleMultiStack<int>::createStack;
    using dataStructures::CFlexibleMultiStack<int>::deleteStack;
    using dataStructures::CFlexibleMultiStack<int>::push;
    using dataStructures::CFlexibleMultiStack<int>::pop;
    using dataStructures::CFlexibleMultiStack<int>::peek;
    using dataStructures::CFlexibleMultiStack<int>::isEmpty;
    using dataStructures::CFlexibleMultiStack<int>::getStackSize;


};


#endif // CHAPTER3_STACK_OF_PLATES_HPP