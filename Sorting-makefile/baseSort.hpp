#ifndef BASESORT_INCLUDED_
#define BASESORT_INCLUDED_
#include <iostream>

using namespace std;


class CBaseSort{
public:
    CBaseSort() 
        : swapCount(0)
    {
    }

    virtual void sort(int inArray[], int arraySize) = 0;
    static void printArray(int a[], int size);
    static void printArray(int a[], int low, int high);
    void resetCounter();

protected:
    void swap(int inArray[], int x, int y);
    int swapCount;
};

void CBaseSort::swap(int inArray[], int x, int y){
    int tmp = inArray[x];
    inArray[x] = inArray[y];
    inArray[y] = tmp;
    ++swapCount;
}

void CBaseSort::printArray(int a[], int size){
    printArray(a, 0, size-1);
}

void CBaseSort::printArray(int a[], int low, int high){
    for(int i = low; i <= high; i++){
        cout << a[i] << ", ";
    }
    cout << std::endl;    
}

void CBaseSort::resetCounter(){
    swapCount = 0;
}
#endif //BASESORT_INCLUDED_

