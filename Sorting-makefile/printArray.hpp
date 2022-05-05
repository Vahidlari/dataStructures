#ifndef PRINTARRAY_INCLUDED_
#define PRINTARRAY_INCLUDED_
#include <iostream>

using namespace std;

template<typename Ttype>
void printArray(Ttype a[], int size){
    for(int i = 0; i < size; i++){
        cout << a[i] << ", ";
    }
    cout << std::endl;
}

#endif //PRINTARRAY_INCLUDED_

