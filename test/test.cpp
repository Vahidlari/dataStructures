#include "selection/selectionSort.hpp"
#include "insertion/insertionSort.hpp"
#include "shell/shellSort.hpp"
#include "merge/mergeSort.hpp"
#include "quick/quickSort.hpp"
#include "printArray.hpp" 

#define ARRAY_SIZE 10 

int main()
{
    using complexity_t = CQuickSort::EImplementationComplexity;
    std::cout << "Hello world!\n";
    CSelectionSort<int> mySelectionSort;
    CInsertionSort<int> myInsertionSort;
    CShellSort<int> myShellSort;
    CMergeSort myMergeSort;
    CQuickSort mySimpleQuickSort(complexity_t::simple);
    CQuickSort myEfficientQuickSort(complexity_t::efficient);
    CQuickSort my3WayQuickSort(complexity_t::threeWay);

    int a[] = {8, 9, 2, 4, 1, 5, 3, 0, 6, 7};
    int b[ARRAY_SIZE], c[ARRAY_SIZE], d[ARRAY_SIZE], e[ARRAY_SIZE], f[ARRAY_SIZE];
    for (int i  = 0; i < ARRAY_SIZE; i++){
        b[i] = c[i] = d[i] = e[i] = f[i] = a[i];
    }
    printArray(a, ARRAY_SIZE);

    cout << "----- SELECTION SORT ------\n";
    mySelectionSort.sort(a, ARRAY_SIZE);
    printArray(a, ARRAY_SIZE);

    cout << "----- INSERTION SORT ------\n";
    myInsertionSort.sort(b, ARRAY_SIZE);
    printArray(b, ARRAY_SIZE);
    cout << "----- SHELL SORT ------\n";
    myShellSort.sort(c, ARRAY_SIZE);
    printArray(c, ARRAY_SIZE);
    cout << "----- MERGE SORT ------\n";
    myMergeSort.sort(d, ARRAY_SIZE);
    printArray(d, ARRAY_SIZE);
    cout << "----- QUICK SORT SIMPLE ------\n";
    mySimpleQuickSort.sort(e, ARRAY_SIZE);
    printArray(e, ARRAY_SIZE);
    cout << "----- QUICK SORT EFFICIENT ------\n";
    int rtn = myEfficientQuickSort.selectKthSmallestElement(f, ARRAY_SIZE, 3);
    cout << "Kth smallest element is : " << rtn << std::endl;
    printArray(f, ARRAY_SIZE);
    cout << "----- QUICK SORT EFFICIENT ------\n";
    int equalValues[] = { 0, 12, 3, 7, 20, 3, 1, 7, 0, 3, 8, 7};
    mySimpleQuickSort.resetCounter();
    my3WayQuickSort.sort(equalValues, 12);
    printArray(equalValues, 12);
    
}