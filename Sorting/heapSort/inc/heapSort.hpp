#ifndef HEAPSORT_INCLUDED_
#define HEAPSORT_INCLUDED_

#include <binaryHeap.hpp>

template <typename Ttype>
class CHeapSort: public CBinaryHeap<Ttype>
{
public:
    CHeapSort() = default;

    void sort(std::vector<Ttype>& a);
};

#include "heapSort.inl"
#endif //HEAPSORT_INCLUDED_