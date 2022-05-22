#ifndef UTIL_INCLUDED_
#define UTIL_INCLUDED_
#include <iostream>

template<typename T> 
inline 
void print(T q)
{
    for(auto& v : q)
    {
        std::cout << v << ", ";
    }
    std::cout << std::endl;
}

#endif //UTIL_INCLUDED_