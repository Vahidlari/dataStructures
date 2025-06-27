#ifndef FLEXIBLE_MULTI_STACK_HPP
#define FLEXIBLE_MULTI_STACK_HPP

#include <vector>
#include <stdexcept>

namespace dataStructures
{
/**
 * @brief Class representing a flexible multi-stack data structure.
 * This class allows for multiple stacks to be managed within a single
 * vector, dynamically resizing as needed. The stacks can be accessed
 * and manipulated independently, via their respective indices.
 * @tparam Ttype Type of elements stored in the stacks
 * @note The overal size of the data vector is specified by the constructor's overalCapacity parameter.
 * @note The overal capacity can be increased dynamically by an explicit call to increaseCapacity(size_t newCapacity).
 */
template <typename Ttype>
class CFlexibleMultiStack
{
public:
    using size_t = std::size_t; ///< Type alias for size_t
    constexpr static size_t defaultCapacity = 10; ///< Default initial capacity for each stack
    constexpr static size_t invalidStackIndex = static_cast<size_t>(-1); ///< Invalid stack index constant

    /**
     * @brief Constructor for CFlexibleMultiStack
     * @param overalCapacity Initial capacity for the entire data vector
     * @note The overalCapacity specifies the initial size of the data vector.
     * If the capacity is exceeded, the vector will automatically resize.
     */
    explicit CFlexibleMultiStack(size_t overalCapacity = defaultCapacity);

    /**
     * @brief Default destructor for CFlexibleMultiStack
     * @note The destructor does not need to do anything special since std::vector manages its own memory.
     */
    ~CFlexibleMultiStack();

    /**
     * @brief Creates a new stack and returns its index
     * @return Index of the newly created stack
     * @note The stack is initialized with the initial capacity specified in the constructor.
     * @note If the initial capacity is exceeded, the stack will automatically resize.
     */
    size_t createStack();

    /**
     * @brief Creates a new stack with a specified initial capacity
     * @param initialCapacity Initial capacity for the new stack
     * @return Index of the newly created stack
     * @note If the reserved capacity is exceeded, the function will return an invalid stack index.
     * @note The stack is initialized with the specified initial capacity.
     */
    size_t createStack(size_t initialCapacity);

    /**
     * @brief Increases the capacity of the specified stack
     * @param stackIndex Index of the stack to increase capacity for
     * @param newCapacity New capacity for the stack
     * @return true if the capacity was successfully increased, false otherwise
     * @throws std::out_of_range if the stack index is invalid or if the new
     * @note If the new capacity is less than the current size, it will throw an exception.
     */
    bool increaseCapacity(size_t stackIndex, size_t newCapacity);

    /**
     * @brief Deletes the specified stack
     * @param stackIndex Index of the stack to delete
     * @note This will remove the stack and its elements from the data vector.
     * @note After deletion, the indices of stacks may change.
     */
    void deleteStack(size_t stackIndex);

    /**
     * @brief Pushes a value onto the specified stack
     * @param stackIndex Index of the stack to push the value onto
     * @param value Value to push onto the stack
     * @note If the stack is full, it will automatically resize.
     */
    void push(size_t stackIndex, const Ttype& value);

    /**
     * @brief Pops a value from the specified stack
     * @param stackIndex Index of the stack to pop the value from
     * @return The value popped from the stack
     * @note If the stack is empty, it will throw an exception.
     */
    Ttype pop(size_t stackIndex);

    /**
     * @brief Peeks at the top value of the specified stack without removing it
     * @param stackIndex Index of the stack to peek at
     * @return The value at the top of the stack
     * @note If the stack is empty, it will throw an exception.
     */
    Ttype peek(size_t stackIndex) const;

    /**
     * @brief Checks if the specified stack is empty
     * @param stackIndex Index of the stack to check
     * @return true if the stack is empty, false otherwise
     */
    bool isEmpty(size_t stackIndex) const;

private:

    /**
     * @brief Resizes the data vector to accommodate a new stack
     * @param newCapacity New capacity for the data vector
     * @note This will increase the overall capacity of the data vector.
     */
    void shiftStack(size_t stackIndex);

    /**
     * @brief Gets the base index of the specified stack
     * @param stackIndex Index of the stack to get the base index for
     * @return The base index of the stack
     */
    size_t getStackBaseIndex(size_t stackIndex) const;

    /**
     * @brief Gets the top index of the specified stack
     * @param stackIndex Index of the stack to get the top index for
     * @return The top index of the stack
     */
    size_t getStackTopIndex(size_t stackIndex) const;

    /**
     * @brief Checks if the specified stack index is valid
     * @param stackIndex Index of the stack to check
     * @return true if the stack index is valid, false otherwise
     */
    bool isValidStackIndex(size_t stackIndex) const;

    /**
     * @brief Calculates the top index of the specified stack for push/pop operations
     * @param stackIndex Index of the stack to calculate the top index for
     * @param pushOperation Indicates if the operation is a push (true) or pop (false)
     * @return The top index of the stack
     * @note This function is used internally to determine the current top index of a stack.
     * It takes into account the base index and the current size of the stack. If needed, it treats the 
     * data vector as a circular buffer to manage the stacks efficiently.
     * @note The top index is calculated based on the current size of the stack and its base index.
     * If the stack is empty, the top index will be equal to the base index.
     * If the stack has elements, the top index will be one less than the next available index
     * in the data vector, effectively pointing to the last element of the stack.
     * @throws std::out_of_range if the stack index is invalid or if the stack is empty.
     */
    size_t calculateTopIndex(size_t stackIndex, bool pushOperation) const;

    /**
     * @brief Calculates the used capacity of the specified stack
     * @param stackIndex Index of the stack to calculate the used capacity for
     * @return The number of elements currently in the stack
     * @note This function is used to determine how many elements are currently stored in a specific stack.
     * It calculates the difference between the top index and the base index of the stack.
     */
    size_t calculateUsedCapacity(size_t stackIndex) const;

    /**
     * @brief Metadata structure for each stack
     * Contains information about the top index, capacity, and base index of the stack.
     */
    struct TStackMetadata
    {
        constexpr static size_t stackInitialCapacity = 10; ///< Initial capacity for each stack
        TStackMetadata(size_t baseIndex, size_t capacity)
            : top(baseIndex), capacity(capacity), baseIndex(baseIndex) {};
        TStackMetadata() : top(0), capacity(stackInitialCapacity), baseIndex(0) {};
        size_t top;
        size_t capacity;
        size_t baseIndex;
    };


    std::vector<Ttype> data; ///< Vector to hold all stack elements
    size_t totalReservedCapacity; ///< Total reserved capacity for the stacks
    size_t stackCount;       ///< Number of stacks managed by this structure
    std::vector<TStackMetadata> stacks; ///< Vector to hold stack metadata (top index, capacity, base index)
};

} // namespace dataStructures
#endif // FLEXIBLE_MULTI_STACK_HPP