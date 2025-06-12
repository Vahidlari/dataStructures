#include <iostream>

namespace dataStructures
{
template<typename Ttype>
CLinkedNode<Ttype>& CLinkedNode<Ttype>::operator=(const CLinkedNode<Ttype>& other){
    if (this != &other) {
        data = other.data;
        next = other.next;
        previous = other.previous;
    }
    return *this;
}

template<typename Ttype>
inline const Ttype& CLinkedNode<Ttype>::getData() const{
    return data;
}

template<typename Ttype>
inline void CLinkedNode<Ttype>::setData(Ttype _data){
    data = _data;
}

template<typename Ttype>
inline CLinkedNode<Ttype>* CLinkedNode<Ttype>::getNext() const{
    return next;
}

template<typename Ttype>
inline void CLinkedNode<Ttype>::setNext(CLinkedNode<Ttype>* _next){
    next = _next;
}

template<typename Ttype>
inline CLinkedNode<Ttype>* CLinkedNode<Ttype>::getPrevious() const{
    return previous;
}

template<typename Ttype>
inline void CLinkedNode<Ttype>::setPrevious(CLinkedNode<Ttype>* _previous){
    previous = _previous;
}

template<typename Ttype>
inline void CLinkedNode<Ttype>::print() const{
    std::cout << "Data: " << data << std::endl;
}

} // namespace dataStructures
