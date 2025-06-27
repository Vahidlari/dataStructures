#ifndef FLEXIBLE_MULTI_STACK_HPP
#define FLEXIBLE_MULTI_STACK_HPP

#include <vector>
#include <unordered_map>
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
    using data_t = Ttype; ///< Type alias for the data type
    constexpr static size_t defaultCapacity = 10; ///< Default initial capacity for each stack
    enum class EStackCreationResult {
        SUCCESS,
        INVALID_STACK_ID, ///< The stack ID is invalid or already exists
        INVALID_CAPACITY, ///< The capacity is invalid
        OVERFLOW ///< The stack is full
    };

    /**
     * @brief Constructor for CFlexibleMultiStack
     * @param overalCapacity Initial capacity for the entire data vector
     * @note The overalCapacity specifies the initial size of the data vector.
     * If the capacity is exceeded, the vector will automatically resize.
     */
    explicit CFlexibleMultiStack(size_t overalCapacity = defaultCapacity, size_t maxStacks = 1);

    /**
     * @brief Default destructor for CFlexibleMultiStack
     * @note The destructor does not need to do anything special since std::vector manages its own memory.
     */
    virtual ~CFlexibleMultiStack();

    /**
     * @brief Creates a new stack and returns its index
     * @param stackID ID of the stack to create
     * @return EStackCreationResult::SUCCESS if the stack was created successfully, EStackCreationResult::INVALID_STACK_ID if the stack ID is invalid, EStackCreationResult::INVALID_CAPACITY if the capacity is invalid, EStackCreationResult::OVERFLOW if the stack is full
     * @note The stack is initialized with the initial capacity specified in the constructor.
     * @note If the initial capacity is exceeded, the stack will automatically resize.
     */
    EStackCreationResult createStack(size_t stackID);

    /**
     * @brief Creates a new stack with a specified initial capacity
     * @param capacity the capacity of the new stack
     * @param stackID ID of the stack to create
     * @return EStackCreationResult::SUCCESS if the stack was created successfully, EStackCreationResult::INVALID_STACK_ID if the stack ID is invalid, EStackCreationResult::INVALID_CAPACITY if the capacity is invalid, EStackCreationResult::OVERFLOW if the stack is full
     * @note If the reserved capacity is exceeded, the function will return an invalid stack index.
     * @note The stack is initialized with the specified initial capacity.
     */
    EStackCreationResult createStack(size_t stackID, size_t capacity);

    /**
     * @brief Deletes the specified stack
     * @param stackID ID of the stack to delete
     * @note This will remove the stack and its elements from the data vector.
     * @note After deletion, the indices of stacks may change.
     */
    void deleteStack(size_t stackID);

    /**
     * @brief Pushes a value onto the specified stack
     * @param stackID ID of the stack to push the value onto
     * @param value Value to push onto the stack
     * @note If the stack is full, it will automatically resize.
     */
    virtual void push(size_t stackID, const Ttype& value);

    /**
     * @brief Pops a value from the specified stack
     * @param stackID ID of the stack to pop the value from
     * @return The value popped from the stack
     * @note If the stack is empty, it will throw an exception.
     */
    virtual data_t pop(size_t stackID);

    /**
     * @brief Peeks at the top value of the specified stack without removing it
     * @param stackID ID of the stack to peek at
     * @return The value at the top of the stack
     * @note If the stack is empty, it will throw an exception.
     */
    data_t peek(size_t stackID) const;

    /**
     * @brief Checks if the specified stack is empty
     * @param stackID ID of the stack to check
     * @return true if the stack is empty, false otherwise
     */
    bool isEmpty(size_t stackID) const;

    /**
     * @brief Gets the size of the specified stack
     * @param stackID ID of the stack to get the size for
     * @return The size of the stack
     */
    size_t getStackSize(size_t stackID) const;

    /**
     * @brief Gets the capacity of a specified stack
     * @param stackID ID of the stack to get the capacity for
     * @return The capacity of the stack
     */
    size_t getStackCapacity(size_t stackID) const;

    /**
     * @brief Gets the total number of stacks managed by this structure
     * @return The number of stacks
     */
    size_t getStackCount() const;

private:
    /**
     * @brief Perform memory tetris to make space
     * @return true if the memory tetris was performed successfully, false otherwise
     */
    bool performMemoryTetris();

    /**
     * @brief Checks if the specified stack index is valid
     * @param stackID ID of the stack to check
     * @return true if the stack index is valid, false otherwise
     */
    bool isValidStackID(size_t stackID) const;

    /**
     * @brief Calculates the top index of the specified stack for push/pop operations
     * @param stackID ID of the stack to calculate the top index for
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
    size_t calculateTopIndex(size_t stackID, bool pushOperation) const;

    size_t totalReservedCapacity; ///< Total reserved capacity for the stacks
    size_t stackCount;       ///< Number of stacks managed by this structure
    size_t maxNumberOfStacks; ///< Maximum number of stacks that can be created

protected:

    /**
     * @brief Metadata structure for each stack
     * Contains information about the top index, capacity, and base index of the stack.
     */
    struct TStackMetadata
    {
        constexpr static size_t stackInitialCapacity = 10; ///< Initial capacity for each stack
        TStackMetadata(size_t baseIndex, size_t capacity)
            : top(baseIndex), capacity(capacity), baseIndex(baseIndex), size(0), minValueIndex(baseIndex) {};
        TStackMetadata() : top(0), capacity(stackInitialCapacity), baseIndex(0), size(0), minValueIndex(0) {};
        size_t top;
        size_t capacity;
        size_t baseIndex;
        size_t size;
        size_t minValueIndex;
    };

    /**
     * @brief Gets the base index of the specified stack
     * @param stackID ID of the stack to get the base index for
     * @return The base index of the stack
     */
    size_t getStackBaseIndex(size_t stackID) const;

    /**
     * @brief Gets the top index of the specified stack
     * @param stackID ID of the stack to get the top index for
     * @return The top index of the stack
     */
    size_t getStackTopIndex(size_t stackID) const;

    std::vector<data_t> data; ///< Vector to hold all stack elements
    std::unordered_map<size_t, TStackMetadata> stacks; ///< Map to hold stack metadata (top index, capacity, base index)
};

} // namespace dataStructures

#include "dataStructures/flexibleMultiStack.inl"

#endif // FLEXIBLE_MULTI_STACK_HPP