# Binary Heap

A template-based max-heap implementation that maintains the heap property: each node is greater than or equal to its children.

## Features

### Template Class `CBinaryHeap<Ttype>`

Inherits from `CBaseDataType<std::vector<Ttype>>` and implements a max-heap:

```cpp
template <typename Ttype>
class CBinaryHeap : public CBaseDataType<std::vector<Ttype>> {
public:
    CBinaryHeap() = default;
    Ttype delMax();
    void insert(Ttype item);
protected:
    void swim(int idx);
    void sink(int idx);
    std::vector<Ttype> heapArray;
};
```

#### Public Methods

- `insert`: Adds a new element to the heap
  - Time complexity: O(log n)
  - Parameters:
    - `item`: Value to insert
  - Usage example:
    ```cpp
    CBinaryHeap<int> heap;
    heap.insert(5);  // Heap now contains 5
    heap.insert(3);  // Heap maintains max-heap property
    ```

- `delMax`: Removes and returns the maximum element
  - Time complexity: O(log n)
  - Returns: The maximum element in the heap
  - Usage example:
    ```cpp
    CBinaryHeap<int> heap;
    heap.insert(5);
    heap.insert(3);
    int max = heap.delMax();  // Returns 5
    ```

#### Protected Methods

- `swim`: Moves an element up the heap to maintain the heap property
  - Used internally after insertion
  - Time complexity: O(log n)

- `sink`: Moves an element down the heap to maintain the heap property
  - Used internally after deleting the maximum
  - Time complexity: O(log n)

## Implementation Details

The heap is implemented using a vector where for any index i:
- Left child is at 2i + 1
- Right child is at 2i + 2
- Parent is at (i-1)/2

## Testing

The implementation includes tests covering:
- Basic heap operations (insert and delMax)
- Heap property maintenance
- Different insertion orders (ascending, descending)
- Duplicate values

Run tests with:
```bash
./build.sh -s binaryHeap -t true
```

## Performance

- Space complexity: O(n)
- Time complexity:
  - Insert: O(log n)
  - Delete maximum: O(log n)
  - Get maximum: O(1) 