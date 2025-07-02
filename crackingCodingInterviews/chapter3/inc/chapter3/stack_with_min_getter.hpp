#ifndef CHAPTER3_STACK_WITH_MIN_GETTER_HPP
#define CHAPTER3_STACK_WITH_MIN_GETTER_HPP

#include "dataStructures/flexibleMultiStack.hpp"

/**
 * @file stack_with_min_getter.hpp
 * @brief Solution for Cracking the Coding Interview 3.2: Stack with Min Getter
 * @problem
 * Implement a stack with a function to get the minimum element in O(1) time.
 *
 **/

/** 
 * @brief Class representing a stack with a function to get the minimum element
 * @note This class extends the CFlexibleMultiStack class to provide an additional method for retrieving the minimum element in O(1) time.
 * @note The stack is implemented using CFlexibleMultiStack<int>, but only allows a single stack creation. The limitation is adopted to
 * simplify the implementation of the getMin function, which is designed to work with a single stack.
 */
class CStackWithMinGetter : public dataStructures::CFlexibleMultiStack<int>
{
public:
    using size_t = dataStructures::CFlexibleMultiStack<int>::size_t; ///< Type alias for size_t
    using data_t = dataStructures::CFlexibleMultiStack<int>::data_t; ///< Type alias for the data type
    using dataStructures::CFlexibleMultiStack<int>::createStack;
    constexpr static size_t defaultMinStackID = 0; ///< Default ID for the minimum stack

    CStackWithMinGetter(size_t overalCapacity = dataStructures::CFlexibleMultiStack<int>::defaultCapacity)
        : dataStructures::CFlexibleMultiStack<int>(overalCapacity, 1) {
            minStack = new dataStructures::CFlexibleMultiStack<size_t>(overalCapacity, 1); ///< Initialize the min stack with the same capacity as the main stack
            minStack->createStack(defaultMinStackID, overalCapacity); ///< Create a single stack for minimum values with the same capacity as the main stack
        } ///< Constructor for CStackWithMinGetter

    CStackWithMinGetter(){
        CStackWithMinGetter(dataStructures::CFlexibleMultiStack<int>::defaultCapacity);
    }

    ~CStackWithMinGetter() override {
        delete minStack;
    } ///< Default destructor for CStackWithMinGetter

    /**
    * @brief Gets the minimum element from the stack
    * @return The minimum element in the stack
    */
    data_t getMin() const;

    /**
     * @brief Pushes an element onto the stack and updates the minimum stack
     * @param value The value to push onto the stack
     * @param stackID ID of the stack to push the value onto
     */
    void push(size_t stackID, const data_t& value) override;

    /**
     * @brief Pops an element from the stack and updates the minimum stack
     * @param stackID ID of the stack to pop the value from
     * @return The value popped from the stack
     */
    data_t pop(size_t stackID) override;

private:
    using dataStructures::CFlexibleMultiStack<int>::getStackTopIndex;

    // Use a stack to keep track of the minimum elements.
    dataStructures::CFlexibleMultiStack<size_t>* minStack;
};

#endif // CHAPTER3_STACK_WITH_MIN_GETTER_HPP