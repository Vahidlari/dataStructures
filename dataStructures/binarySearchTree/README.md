# Binary Search Tree

A template-based binary search tree implementation that stores key-value pairs and supports various operations including rank queries.

## Features

### Template Class `CBinarySearchTree<Tkey, Tvalue>`

A binary search tree implementation that maintains ordering by keys:

```cpp
template<typename Tkey, typename Tvalue>
class CBinarySearchTree {
public:
    using key_t = Tkey;
    using value_t = Tvalue;
    
    CBinarySearchTree();
    void put(key_t key, value_t value);
    value_t get(key_t key);
    bool contains(key_t key);
    uint32_t rank(key_t key);
    uint32_t height();
    uint32_t size(key_t low, key_t high);
};
```

#### Public Methods

- `put`: Inserts or updates a key-value pair
  - Time complexity: O(log n) average case
  - Parameters:
    - `key`: Key to insert/update
    - `value`: Value to associate with the key
  - Usage example:
    ```cpp
    CBinarySearchTree<int, std::string> bst;
    bst.put(5, "five");
    bst.put(3, "three");
    ```

- `get`: Retrieves the value associated with a key
  - Time complexity: O(log n) average case
  - Parameters:
    - `key`: Key to look up
  - Returns: Value associated with the key
  - Usage example:
    ```cpp
    std::string value = bst.get(5);  // Returns "five"
    ```

- `contains`: Checks if a key exists in the tree
  - Time complexity: O(log n) average case
  - Parameters:
    - `key`: Key to check
  - Returns: true if key exists, false otherwise

- `rank`: Returns the number of keys less than the given key
  - Time complexity: O(log n) average case
  - Parameters:
    - `key`: Key to find rank for
  - Returns: Number of keys less than the given key

- `height`: Returns the height of the tree
  - Time complexity: O(n)
  - Returns: Height of the tree (0 for empty tree)

- `size`: Returns the number of keys in a given range
  - Time complexity: O(log n) average case
  - Parameters:
    - `low`: Lower bound key (inclusive)
    - `high`: Upper bound key (inclusive)
  - Returns: Number of keys in the range [low, high]

## Implementation Details

The tree is implemented using nodes where each node contains:
- A key
- An associated value
- Left and right child pointers
- Size information for rank queries

The implementation maintains the binary search tree property:
- All keys in the left subtree are less than the node's key
- All keys in the right subtree are greater than the node's key

## Testing

The implementation includes tests covering:
- Basic operations (put, get, contains)
- Rank calculations
- Tree height measurements
- Range queries
- Edge cases

Run tests with:
```bash
./build.sh -s binarySearchTree -t true
```

## Performance

- Space complexity: O(n)
- Time complexity (average case):
  - Insert: O(log n)
  - Search: O(log n)
  - Rank: O(log n)
  - Range query: O(log n + k) where k is the size of the range

Note: These complexities assume a relatively balanced tree. The actual performance may degrade to O(n) in the worst case with unbalanced insertions. 