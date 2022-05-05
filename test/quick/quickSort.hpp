#ifndef QUICKSORT_INCLUDED_
#define QUICKSORT_INCLUDED_

#include "../baseSort.hpp"

class CQuickSort: public CBaseSort
{
public:
    enum class EImplementationComplexity{
        simple,
        efficient 
    };

    CQuickSort()
        : CBaseSort(), implementation(EImplementationComplexity::simple)
    {
    }
    CQuickSort(EImplementationComplexity _impl)
        : CBaseSort(), implementation(_impl)
    {
    }

    void sort(int inArray[], int arraySize);
private:
    int partitionEfficient(int subArray[], int low, int high);
    void quickSortEfficient(int subArray[], int low, int high);
    int partitionSimplified(int subArray[], int low, int high);
    void quickSortSimplified(int subArray[], int low, int high);

    EImplementationComplexity implementation;
};

void CQuickSort::sort(int inArray[], int arraySize){
    if(implementation == EImplementationComplexity::efficient){
        quickSortEfficient(inArray, 0, arraySize-1);
    } else {
        quickSortSimplified(inArray, 0, arraySize-1);
    }
#ifdef PRINT_ENABLED
    std::cout << "number of swapps: " << swapCount << std::endl;
#endif
}

int CQuickSort::partitionEfficient(int subArray[], int low, int high){
    int pivot = low;
    int i = low + 1, j = high;
    bool _cont = true;
#ifdef PRINT_ENABLED
    std::cout << "Efficient partitioning " << low << " to " << high << ": ";
    printArray(subArray, low, high);
#endif
    while(_cont){
        while(subArray[i] < subArray[pivot] && i < high){
            ++i;
        }
        while(subArray[j] > subArray[pivot] && j > low){
            --j;
        }
        if(i >= high || j <= low || j <= i){
            _cont = false;
        } else {
            swap(subArray, i, j);
        }
    }
    swap(subArray, pivot, j);
#ifdef PRINT_ENABLED
    std::cout << "After partitioning with pivot index = " << j << ": ";
    printArray(subArray, low, high);
#endif
    return j;
}

void CQuickSort::quickSortEfficient(int subArray[], int low, int high){
    if(low < high){
        int p = partitionEfficient(subArray, low, high);
        quickSortEfficient(subArray, low, p - 1);
        quickSortEfficient(subArray, p+1, high);
    }
}

int CQuickSort::partitionSimplified(int subArray[], int low, int high){
    int pivot = high;
    int i = low - 1;
#ifdef PRINT_ENABLED
    std::cout << "Simplified partitioning " << low << " to " << high << ": ";
    printArray(subArray, low, high);
#endif
    for(int j = low; j < high; j++){
        if(subArray[j] <= subArray[pivot]){
            ++i;
            swap(subArray, i, j);
        }
    }
    ++i;
    swap(subArray, i, pivot);
#ifdef PRINT_ENABLED
    std::cout << "After partitioning with pivot index = " << i << ": ";
    printArray(subArray, low, high);
#endif
    return i;
}

void CQuickSort::quickSortSimplified(int subArray[], int low, int high){
    if(low < high){
        int p = partitionSimplified(subArray, low, high);
        quickSortSimplified(subArray, low, p - 1);
        quickSortSimplified(subArray, p+1, high);
    }
}



#endif //QUICKSORT_INCLUDED_