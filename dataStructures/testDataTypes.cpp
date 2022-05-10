#include <baseDataType.hpp>
#include <binaryHeap.hpp>
using namespace std;

int main()
{
    vector<int> a = {1,2,3,4,5};
    CBinaryHeap<int> myHeap;
    myHeap.insert(1);
    myHeap.insert(3);
    myHeap.insert(4);
    myHeap.insert(2);
    myHeap.insert(6);
    myHeap.insert(5);


    std::cout << myHeap.delMax() << std::endl;

    myHeap.insert(8);
    myHeap.insert(22);
    myHeap.insert(7);
    myHeap.insert(0);

    std::cout << myHeap.delMax() << std::endl;



}