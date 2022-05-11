template<typename Ttype>
inline
void CHeapSort<Ttype>::sort(std::vector<Ttype>& a){
    this->heapArray = a;
    for(int i = a.size()/2; i >= 0; i--){
        this->sink(i);
    }
    a = this->heapArray;
}