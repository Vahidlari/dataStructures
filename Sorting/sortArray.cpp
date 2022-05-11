#include <insertionSort.hpp>
#include <selectionSort.hpp>
#include <heapSort.hpp>

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
void printArray(Ttype a){
    for(auto element: a ){
        cout << element << ", ";
    }
    std::cout << std::endl;
}

int main()
{
    CHeapSort<int> myHeapSort;
    std::vector<int> a = {8, 9, 2, 4, 1, 5, 3, 0, 6, 7};
    myHeapSort.sort(a);
    printArray(a);

    return 0;
}