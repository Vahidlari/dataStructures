#include "insertionSort.hpp"

template<typename Ttype> 
void CInsertionSort<Ttype>::swap(Ttype inArray[], int x, int y){
    Ttype tmp = inArray[x];
    inArray[x] = inArray[y];
    inArray[y] = tmp;
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
    }
}