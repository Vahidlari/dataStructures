#ifndef INSERTIONSORTING_INCLUDED_
#define INSERTIONSORTING_INCLUDED_

template <typename Ttype>
class CInsertionSort  {
public:
    //CInsertionSort(){};
    void sort(Ttype inArray[], int size);
private:
    void swap(Ttype inArray[], int x, int y);
};

#endif // INSERTIONSORTING_INCLUDED_