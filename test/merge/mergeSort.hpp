#ifndef MERGESORT_INCLUDED_
#define MERGESORT_INCLUDED_

#include "../baseSort.hpp"

class CMergeSort: public CBaseSort
{
public:
    CMergeSort()
        : CBaseSort()
    {
    }
    void sort(int inArray[], int arraySize, bool print);

private:
    void merge(int inArray[], int auxArray[], int low, int mid, int high, bool print);
    void subArraySort(int subArray[], int auxArray[], int low, int high, bool print);
};

void CMergeSort::sort(int inArray[], int arraySize, bool print){
    int auxArray[arraySize];

    for(int i = 0; i < arraySize; i++){
        auxArray[i] = inArray[i];
    }
    subArraySort(inArray, auxArray, 0, arraySize - 1, print);
}

void CMergeSort::merge(int inArray[], int auxArray[], int low, int mid, int high, bool print){
    if(print){
        std::cout << "Merging from " << low << " to " << high << ": ";
        printArray(inArray, low, high);
    }

    for (int k = low; k <= high; k++){
        auxArray[k] = inArray[k];
    }

    int i = low, j = mid + 1;
    for (int k = low; k <= high; k++){
        if(i > mid){
            inArray[k] = auxArray[j];
            ++j; 
        } else if (j > high){
            inArray[k] = auxArray[i];
            ++i; 
        } else if (auxArray[i] <= auxArray[j]) {
            inArray[k] = auxArray[i];
            ++i; 
        } else {
            inArray[k] = auxArray[j];
            ++j; 
        }
    }

    if(print){
        std::cout << "Subarray values after merge: ";
        printArray(inArray, low, high);
    }
}

void CMergeSort::subArraySort(int subArray[], int auxArray[], int low, int high, bool print){
    if(print){
        std::cout << "Sorting for " << low << ", " << high << std::endl;
    }
    if(high <= low){
        return;
    } else {
        int mid = low + (high - low)/2;
        subArraySort(subArray, auxArray, low, mid, print);
        subArraySort(subArray, auxArray, mid + 1, high, print);
        merge(subArray, auxArray, low, mid, high, print);
    }
}

#endif //MERGESORT_INCLUDED_