#include <stdio.h>
#include <iostream>

#include "insertionSort.hpp"
#include "selectionSort.hpp"

using namespace std;

template<typename T>
class CTest{
    public:
    void sayHello();
};

template<typename T>
void CTest<T>::sayHello(){
    std::cout << "Hello!\n";
};

template<typename Ttype>
void printArray(Ttype a[], int size){
    for(int i = 0; i < size; i++){
        cout << a[i] << ", ";
    }
    cout << std::endl;
}

int main()
{
    std::cout << "Hello World!" << std::endl;
    CSelectionSort<int> selectionSort;
    CTest<int> myTest;
    myTest.sayHello();
    //int a[10] = {8, 9, 2, 4, 1, 5, 3, 0, 6, 7};
    //printArray(a, 10);
    //
    selectionSort.sayHello();
    //printArray(a, 10);

    return 0;
}