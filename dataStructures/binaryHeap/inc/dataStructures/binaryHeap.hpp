#ifndef BINARYHEAP_INCLUDED_
#define BINARYHEAP_INCLUDED_

#include "dataStructures/baseDataType.hpp"

namespace dataStructures
{
/**
 * @brief Max-heap implementation using a vector as underlying storage
 * 
 * This class implements a binary max-heap where each node is greater than or equal
 * to its children. The heap is stored in a vector where for any index i:
 * - Left child is at 2i + 1
 * - Right child is at 2i + 2
 * - Parent is at (i-1)/2
 * 
 * @tparam Ttype Element type that must support operator< for comparisons
 */
template <typename Ttype>
class CBinaryHeap : public CBaseDataType<std::vector<Ttype>>
{
public:
    //using CBaseDataType::swap; //(std::vector<Ttype> a, int srcIdx, int dstIdx);
    //using CBaseDataType::print; //(std::vector<Ttype> a a);
    using index_t = typename CBaseDataType<std::vector<Ttype>>::index_t;

    /**
     * @brief Default constructor
     */
    CBinaryHeap() = default;

    /**
     * @brief Removes and returns the maximum element from the heap
     * 
     * @return Ttype The maximum element
     * @note Time complexity: O(log n)
     */
    Ttype delMax();

    /**
     * @brief Inserts a new element into the heap
     * 
     * @param[in] item Element to insert
     * @note Time complexity: O(log n)
     */
    void insert(Ttype item);

protected:
    /**
     * @brief Moves an element up the heap to maintain the heap property
     * 
     * @param[in] idx Index of the element to move up
     * @note Time complexity: O(log n)
     */
    void swim(index_t idx);

    /**
     * @brief Moves an element down the heap to maintain the heap property
     * 
     * @param[in] idx Index of the element to move down
     * @note Time complexity: O(log n)
     */
    void sink(index_t idx);

    std::vector<Ttype> heapArray;
};
} // namespace dataStructures

#include "dataStructures/binaryHeap.inl"

#endif //BINARYHEAP_INCLUDED_