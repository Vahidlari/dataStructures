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

    /// Merge algorithm sorts arrays in recursions. Each run a given array is halved into two sub-arrays, sorted in recursive calls.
    /// On return, the two halves are merged into each other. Merging is performed by traversing through both halves, 
    /// taking a smaller value from each half. It performed using an auxiliary array to hold sorted halves and the main one to 
    /// to contain the final sorted array after merging in each step.
     
    void sort(int inArray[], int arraySize) override;

private:
    void merge(int inArray[], int auxArray[], int low, int mid, int high);
    void subArraySort(int subArray[], int auxArray[], int low, int high);
};

void CMergeSort::sort(int inArray[], int arraySize){
    int auxArray[arraySize];

    for(int i = 0; i < arraySize; i++){
        auxArray[i] = inArray[i];
    }
    subArraySort(inArray, auxArray, 0, arraySize - 1);
}

void CMergeSort::merge(int inArray[], int auxArray[], int low, int mid, int high){
#ifdef PRINT_ENABLED
        std::cout << "Merging from " << low << " to " << high << ": ";
        printArray(inArray, low, high);
#endif

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

#ifdef PRINT_ENABLED
        std::cout << "Subarray values after merge: ";
        printArray(inArray, low, high);
#endif
}

void CMergeSort::subArraySort(int subArray[], int auxArray[], int low, int high){
#ifdef PRINT_ENABLED
        std::cout << "Sorting for " << low << ", " << high << std::endl;
#endif
    if(high <= low){
        return;
    } else {
        int mid = low + (high - low)/2;
        subArraySort(subArray, auxArray, low, mid);
        subArraySort(subArray, auxArray, mid + 1, high);
        merge(subArray, auxArray, low, mid, high);
    }
}

#endif //MERGESORT_INCLUDED_