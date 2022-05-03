#ifndef HASHSORT_INCLUDED_
#define HASHSORT_INCLUDED_
#include "../printArray.hpp"

template <typename Ttype>
class CShellSort  {
public:
    CShellSort(): swapCount(0)
    {

    };
    void sort(Ttype inArray[], int arraySize, bool print);
    void sort(Ttype inArray[], int arraySize, int h, bool print);
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
void CShellSort<Ttype>::sort(Ttype inArray[], int arraySize, bool print){
    int h = 1; 
    while(h < arraySize/3){
        h = 3*h + 1;
    }
    while (h >= 1){
        if(print){
            cout << "-------------------------\n";
            cout << "Sorting for h = " << h << "\n";
        }
        sort(inArray, arraySize, h, print);
        h = static_cast<int>(h/3);
    }
    if(print){
        cout << "number of swaps: " << swapCount << std::endl;
    }
}

template<typename Ttype>
void CShellSort<Ttype>::sort(Ttype inArray[], int arraySize, int h, bool print){
    cout << "Running\n";
    for(int i = h; i < arraySize; i++){
        for(int j = i; j >= h; j -= h ){
            if(inArray[j] < inArray[j-h]){
                swap(inArray, j, j-h);
            } else {
                break;
            }
        }
        if(print)
            printArray(inArray, arraySize);
    }
}
#endif //HASHSORT_INCLUDED_