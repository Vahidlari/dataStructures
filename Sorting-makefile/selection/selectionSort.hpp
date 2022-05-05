#ifndef SELECTIONSORTING_INCLUDED_
#define SELECTIONSORTING_INCLUDED_

#include "../printArray.hpp"

template <typename Ttype>
class CSelectionSort  {
public:
    CSelectionSort(): swapCount(0)
    {
    };
    void sort(Ttype inArray[], int size);
    void sayHello();
private:
    void swap(Ttype inArray[], int x, int y);
    int swapCount;
};

template<typename Ttype>
void CSelectionSort<Ttype>::sayHello(){
    std::cout << "Hello!" << std::endl;
}

template<typename Ttype> 
void CSelectionSort<Ttype>::swap(Ttype inArray[], int x, int y){
    Ttype tmp = inArray[x];
    inArray[x] = inArray[y];
    inArray[y] = tmp;
    ++swapCount;
}

template<typename Ttype>
void CSelectionSort<Ttype>::sort(Ttype inArray[], int arraySize){
    for(int i = 0; i < arraySize; i++){
        int min = i;
        for(int j = i+1; j < arraySize; j++){
            if(inArray[j] < inArray[min]){
                min = j;
            }
        }
        swap(inArray, i, min);
#ifdef PRINT_ENABLED
            printArray(inArray, arraySize);
#endif
    }
#ifdef PRINT_ENABLED
        cout << "number of swaps: " << swapCount << std::endl;
#endif
}
#endif //SELECTIONSORTING_INCLUDED_