#ifndef SELECTIONSORTING_INCLUDED_
#define SELECTIONSORTING_INCLUDED_

template <typename Ttype>
class CSelectionSort  {
public:
    CSelectionSort() = default;
    void sort(Ttype inArray[], int size);
    void sayHello();
private:
    void swap(Ttype inArray[], int x, int y);
};

#include "selectionSort.inl"

#endif //SELECTIONSORTING_INCLUDED_