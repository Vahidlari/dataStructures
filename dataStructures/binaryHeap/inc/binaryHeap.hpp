#ifndef BINARYHEAP_INCLUDED_H
#define BINARYHEAP_INCLUDED_H

#include <baseDataType.hpp>

template <typename Ttype>
class CBinaryHeap:public CBaseDataType<std::vector<Ttype> >
{
public:
    //using CBaseDataType::swap; //(std::vector<Ttype> a, int srcIdx, int dstIdx);
    //using CBaseDataType::print; //(std::vector<Ttype> a a);
    CBinaryHeap() = default;
    Ttype delMax();
    void insert(Ttype item);
private:
    void swim(int idx);
    void sink(int idx);

    std::vector<Ttype> heapArray;
};

#include "binaryHeap.inl"

#endif //BINARYHEAP_INCLUDED_H