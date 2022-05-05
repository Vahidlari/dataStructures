#ifndef HASHSORT_INCLUDED_
#define HASHSORT_INCLUDED_
#include "../printArray.hpp"

template <typename Ttype>
class CShellSort  {
public:
    CShellSort(): swapCount(0)
    {

    };
    void sort(Ttype inArray[], int arraySize);
    void hSort(Ttype inArray[], int arraySize, int h);
private:
    void swap(Ttype inArray[], int x, int y);
    int swapCount;
};

template<typename Ttype> 
void CShellSort<Ttype>::swap(Ttype inArray[], int x, int y){
    Ttype tmp = inArray[x];
    inArray[x] = inArray[y];
    inArray[y] = tmp;
    ++swapCount;
}

template<typename Ttype>
void CShellSort<Ttype>::sort(Ttype inArray[], int arraySize){
    int h = 1; 
    while(h < arraySize/3){
        h = 3*h + 1;
    }
    while (h >= 1){
#ifdef PRINT_ENABLED
            cout << "-------------------------\n";
            cout << "Sorting for h = " << h << "\n";
#endif
        hSort(inArray, arraySize, h);
        h = static_cast<int>(h/3);
    }
#ifdef PRINT_ENABLED
        cout << "number of swaps: " << swapCount << std::endl;
#endif
}

template<typename Ttype>
void CShellSort<Ttype>::hSort(Ttype inArray[], int arraySize, int h){
    cout << "Running\n";
    for(int i = h; i < arraySize; i++){
        for(int j = i; j >= h; j -= h ){
            if(inArray[j] < inArray[j-h]){
                swap(inArray, j, j-h);
            } else {
                break;
            }
        }
#ifdef PRINT_ENABLED
            printArray(inArray, arraySize);
#endif
    }
}
#endif //HASHSORT_INCLUDED_