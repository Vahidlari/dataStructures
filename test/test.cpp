#include "selection/selectionSort.hpp"
#include "insertion/insertionSort.hpp"
#include "shell/shellSort.hpp"
#include "merge/mergeSort.hpp"
#include "printArray.hpp" 

int main()
{
    std::cout << "Hello world!\n";
    CSelectionSort<int> mySelectionSort;
    CInsertionSort<int> myInsertionSort;
    CShellSort<int> myShellSort;
    CMergeSort myMergeSort;
    
    int a[10] = {8, 9, 2, 4, 1, 5, 3, 0, 6, 7};
    int b[10], c[10], d[10];
    for (int i  = 0; i < 10; i++){
        b[i] = c[i] = d[i] = a[i];
    }
    printArray(a, 10);

    cout << "----- SELECTION SORT ------\n";
    mySelectionSort.sort(a, 10, true);
    printArray(a, 10);

    cout << "----- INSERTION SORT ------\n";
    myInsertionSort.sort(b, 10, true);
    printArray(b, 10);
    cout << "----- SHELL SORT ------\n";
    myShellSort.sort(c, 10, true);
    printArray(c, 10);
    cout << "----- MERGE SORT ------\n";
    myMergeSort.sort(d, 10, true);
    printArray(d, 10);
}