
template <typename Ttype>
inline 
Ttype CBinaryHeap<Ttype>::delMax(){
    Ttype max = heapArray[0];
    this->swap(heapArray, 0, heapArray.size() - 1);
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
        int j = (k-1)/2;
        if(heapArray[j] < key){
            //std::cout << heapArray[k/2] << "<" << key << std::endl;
            this->swap(heapArray, j, k);
            k = j;
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
    int j = 0;
    while((2*k+1) < heapArray.size())
    {
        j = 2*k + 1;
        if((heapArray[j] > key) && (heapArray[j] > heapArray[j + 1])){
            this->swap(heapArray, k, j);
            k = j;
        } else if(heapArray[j + 1] > key) {
            this->swap(heapArray, k, j + 1);
            k = j + 1;    
        } else {
            break;
        }
    }
#ifdef PRINT_ENABLED
    std::cout << " --> after Sink: ";
    this->print(heapArray);
#endif
}