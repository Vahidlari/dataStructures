#ifndef CHAPTER2_PARTITION_AROUND_A_VALUE_HPP
#define CHAPTER2_PARTITION_AROUND_A_VALUE_HPP

#include "dataStructures/singlyLinkedList.hpp"

/**
 * @file partition_around_a_value.hpp
 * @brief Solution for Cracking the Coding Interview 2.4: Partition
 *
 * @problem
 * Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x.
 * If x is contained within the list, the values of x only need to be after the elements less than x (see below).
 * The partition element x can appear anywhere in the "right partition"; it does not need to appear between the left and right partitions.
 *
 * EXAMPLE
 * Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition = 5]
 * Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
 */

/**
 * @brief Enum to choose the method to partition the linked list
 */
enum class EPartitionMethod {
    USING_TWO_SUB_LISTS,
    USING_MOVE_TO_HEAD
};

/**
 * @brief Class to partition a linked list around a value
 * @tparam Ttype The type of the data in the linked list
 */
template <typename Ttype>
class CPartitionAroundAValue: public dataStructures::CSinglyLinkedList<Ttype> {
public:
    using data_t = typename dataStructures::CSinglyLinkedList<Ttype>::data_t;
    using node_ptr_t = typename dataStructures::CSinglyLinkedList<Ttype>::node_ptr_t;
    using node_t = typename dataStructures::CSinglyLinkedList<Ttype>::node_t;

    CPartitionAroundAValue() = default;
    ~CPartitionAroundAValue() = default;

    template <EPartitionMethod partitionMethod>
    void partitionAroundAValue(data_t value);

    node_ptr_t getHead() const;
    node_ptr_t getTail() const;
    void appendList(const CPartitionAroundAValue<Ttype>& list);

private:
    using dataStructures::CSinglyLinkedList<Ttype>::head;
    using dataStructures::CSinglyLinkedList<Ttype>::count;
    using dataStructures::CSinglyLinkedList<Ttype>::tail;

    /**
     * @brief Partition the linked list using two sub lists 
     * @param value The value to partition the linked list around
     * @note This method uses two sub lists to partition the linked list and then merges them together
     * @note This method is O(n) time and O(n) space
     */
    void partitionAroundAValue_usingTwoSubLists(data_t value);

    /**
     * @brief Partition the linked list using move to head
     * @param value The value to partition the linked list around
     * @note This method uses move to head to partition the linked list
     * @note This method is O(n) time and O(1) space
     */
    void partitionAroundAValue_usingMoveToHead(data_t value);
    
};

#include "chapter2/partition_around_a_value.inl"

#endif // CHAPTER2_PARTITION_AROUND_A_VALUE_HPP