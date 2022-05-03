#include "../inc/selectionSort.hpp"
#include <iostream>

template<typename Ttype>
void CSelectionSort<Ttype>::sayHello(){
    std::cout << "Hello!" << std::endl;
}

template<typename Ttype> 
void CSelectionSort<Ttype>::swap(Ttype inArray[], int x, int y){
    Ttype tmp = inArray[x];
    inArray[x] = inArray[y];
    inArray[y] = tmp;
}

template<typename Ttype>
void CSelectionSort<Ttype>::sort(Ttype inArray[], int arraySize){
    for(int i = 0; i < arraySize; i++){
        int min = i;
        for(int j = i+1; j < arraySize; j++){
            if(inArray[j] < inArray[min]){
                min = j;
            }
            swap(inArray, i, min);
        }
    }
}