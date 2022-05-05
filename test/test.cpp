#include "selection/selectionSort.hpp"
#include "insertion/insertionSort.hpp"
#include "shell/shellSort.hpp"
#include "merge/mergeSort.hpp"
#include "quick/quickSort.hpp"
#include "printArray.hpp" 


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

    int a[10] = {8, 9, 2, 4, 1, 5, 3, 0, 6, 7};
    int b[10], c[10], d[10], e[10], f[10];
    for (int i  = 0; i < 10; i++){
        b[i] = c[i] = d[i] = e[i] = f[i] = a[i];
    }
    printArray(a, 10);

    cout << "----- SELECTION SORT ------\n";
    mySelectionSort.sort(a, 10);
    printArray(a, 10);

    cout << "----- INSERTION SORT ------\n";
    myInsertionSort.sort(b, 10);
    printArray(b, 10);
    cout << "----- SHELL SORT ------\n";
    myShellSort.sort(c, 10);
    printArray(c, 10);
    cout << "----- MERGE SORT ------\n";
    myMergeSort.sort(d, 10);
    printArray(d, 10);
    cout << "----- QUICK SORT SIMPLE ------\n";
    mySimpleQuickSort.sort(e, 10);
    printArray(e, 10);
    cout << "----- QUICK SORT EFFICIENT ------\n";
    myEfficientQuickSort.sort(f, 10);
    printArray(f, 10);
}