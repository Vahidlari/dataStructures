#ifndef INSERTIONSORTING_INCLUDED_
#define INSERTIONSORTING_INCLUDED_

#include "../printArray.hpp"

template <typename Ttype>
class CInsertionSort  {
public:
    CInsertionSort(): swapCount(0)
    {
    };
    void sort(Ttype inArray[], int arraySize);
private:
    void swap(Ttype inArray[], int x, int y);
    int swapCount;
};

template<typename Ttype> 
void CInsertionSort<Ttype>::swap(Ttype inArray[], int x, int y){
    Ttype tmp = inArray[x];
    inArray[x] = inArray[y];
    inArray[y] = tmp;
    ++swapCount;
}

template<typename Ttype>
void CInsertionSort<Ttype>::sort(Ttype inArray[], int arraySize){
    for(int i = 0; i < arraySize; i++){
        for(int j = i; j > 0; j--){
            if(inArray[j] < inArray[j-1]){
                swap(inArray, j, j-1);
            } else {
                break;
            }
        }
#ifdef PRINT_ENABLED
            printArray(inArray, arraySize);
#endif
    }
#ifdef PRINT_ENABLED
        cout << "number of swaps: " << swapCount << std::endl;
#endif
}

#endif // INSERTIONSORTING_INCLUDED_