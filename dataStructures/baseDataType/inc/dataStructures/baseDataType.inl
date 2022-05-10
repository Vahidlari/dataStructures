#include <vector>
#include <iostream>

namespace dataStructures
{
template<typename Ttype>
inline 
void CBaseDataType<Ttype>::swap(Ttype& a, int srcIdx, int dstIdx){
#ifdef PRINT_ENABLED2
    std::cout << "Swapping " << a[srcIdx] << " with " << a[dstIdx] << ": ";
#endif
    auto tmp = a[dstIdx];
    a[dstIdx] = a[srcIdx];
    a[srcIdx] = tmp;
#ifdef PRINT_ENABLED2
    std::cout << a[srcIdx] << " <--> " << a[dstIdx] << "\n";
#endif
}

template<typename Ttype>
inline 
void CBaseDataType<Ttype>::print(Ttype a){
    for(auto element: a){
        std::cout << element << ", ";
    }
    std::cout << "\n";
}
} // namespace dataStructures
