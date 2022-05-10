# Base Data Type

A template-based utility class providing common functionality for other data structures in the library.

## Features

### Template Class `CBaseDataType<Ttype>`

Base class providing common operations for container types:

```cpp
template <typename Ttype>
class CBaseDataType {
public:
    static void swap(Ttype& a, int srcIdx, int dstIdx);
    static void print(Ttype a);       
};
```

#### Methods

- `swap`: Exchanges elements at given indices in a container
  - Parameters:
    - `a`: Reference to the container
    - `srcIdx`: Source index
    - `dstIdx`: Destination index
  - Usage example:
    ```cpp
    std::vector<int> vec = {1, 2, 3};
    CBaseDataType<std::vector<int>>::swap(vec, 0, 2);  // vec becomes {3, 2, 1}
    ```

- `print`: Outputs container elements to standard output
  - Parameters:
    - `a`: Container to print
  - Usage example:
    ```cpp
    std::vector<int> vec = {1, 2, 3};
    CBaseDataType<std::vector<int>>::print(vec);  // Outputs: 1, 2, 3
    ```

## Usage

This class is designed to be inherited by other data structures that need common container operations. For example:

```cpp
template <typename Ttype>
class CBinaryHeap : public CBaseDataType<std::vector<Ttype>> {
    // Implementation using inherited swap and print methods
};
```

## Testing

The implementation includes comprehensive tests covering:
- Element swapping with different types
- Edge cases (swapping element with itself)
- Different container types

Run tests with:
```bash
./build.sh -s baseDataType -t true
``` 