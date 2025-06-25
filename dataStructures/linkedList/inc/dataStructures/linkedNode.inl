#include <iostream>

namespace dataStructures
{
template<typename Ttype, template<typename> class PtrType>
CLinkedNode<Ttype, PtrType>& CLinkedNode<Ttype, PtrType>::operator=(const CLinkedNode<Ttype, PtrType>& other){
    if (this != &other) {
        data = other.data;
        next = other.next;
        previous = other.previous;
    }
    return *this;
}

template<typename Ttype, template<typename> class PtrType>
inline const Ttype& CLinkedNode<Ttype, PtrType>::getData() const{
    return data;
}

template<typename Ttype, template<typename> class PtrType>
inline void CLinkedNode<Ttype, PtrType>::setData(Ttype _data){
    data = _data;
}

template<typename Ttype, template<typename> class PtrType>
inline typename CLinkedNode<Ttype, PtrType>::node_ptr_t CLinkedNode<Ttype, PtrType>::getNext() const{
    return next;
}

template<typename Ttype, template<typename> class PtrType>
inline void CLinkedNode<Ttype, PtrType>::setNext(node_ptr_t _next){
    next = _next;
}

template<typename Ttype, template<typename> class PtrType>
inline typename CLinkedNode<Ttype, PtrType>::node_ptr_t CLinkedNode<Ttype, PtrType>::getPrevious() const{
    return previous;
}

template<typename Ttype, template<typename> class PtrType>
inline void CLinkedNode<Ttype, PtrType>::setPrevious(node_ptr_t _previous){
    previous = _previous;
}

template<typename Ttype, template<typename> class PtrType>
inline void CLinkedNode<Ttype, PtrType>::print() const{
    std::cout << "Data: " << data << std::endl;
}

} // namespace dataStructures
