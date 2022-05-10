
template <typename Ttype>
inline 
Ttype CBinaryHeap<Ttype>::delMax(){
    Ttype max = heapArray[0];
    this->swap(heapArray, 0, heapArray.size - 1);
    heapArray.pop_back();
    sink(0);
#ifdef PRINT_ENABLED
    std::cout << "Max is " << max << ", the heap content: ";
    this->print(heapArray);
#endif
    return max;    
}

template <typename Ttype>
inline 
void CBinaryHeap<Ttype>::insert(Ttype a){
    heapArray.push_back(a);
    swim(heapArray.size() - 1);
#ifdef PRINT_ENABLED
    std::cout << "Heap content after insering the value " << a << ": ";
    this->print(heapArray);
#endif
}

template <typename Ttype>
inline 
void CBinaryHeap<Ttype>::swim(int idx){
#ifdef PRINT_ENABLED
    std::cout << "Swim index " << idx << " on the content: ";
    this->print(heapArray);
#endif
    int k = idx;
    Ttype key = heapArray[idx];
    while(k > 0)
    {
        if(heapArray[k/2] < key){
            //std::cout << heapArray[k/2] << "<" << key << std::endl;
            this->swap(heapArray, k/2, k);
            k = k/2;
        } else 
        {
            break;
        }
    } 
#ifdef PRINT_ENABLED
    std::cout << " --> after Swim: ";
    this->print(heapArray);
#endif
}

template <typename Ttype>
inline 
void CBinaryHeap<Ttype>::sink(int idx){
 #ifdef PRINT_ENABLED
    std::cout << "Sink index " << idx << " on the content: ";
    this->print(heapArray);
#endif
    int k = idx;
    Ttype key = heapArray[idx];
    while(k < heapArray.size())
    {
        if(heapArray[2*k] > key && heapArray[2*k] > heapArray[2*k + 1]){
            this->swap(heapArray, k, 2*k);
            k *= 2;
        } else if(heapArray[2*k + 1] > key) {
            this->swap(heapArray, k, 2*k);
            k = 2*k + 1;    
        } else {
            break;
        }
    }
#ifdef PRINT_ENABLED
    std::cout << " --> after Sink: ";
    this->print(heapArray);
#endif
}