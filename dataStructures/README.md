# Data Structures Library

This directory contains a collection of template-based C++17 data structure implementations. Each data structure is implemented as a separate library with its own tests and documentation.

## Directory Structure

```
dataStructures/
├── baseDataType/       # Base functionality for data structures
├── binaryHeap/        # Max heap implementation
└── binarySearchTree/  # Binary search tree implementation
```

## Building and Testing

The library uses CMake for building and Google Test for unit testing. Each data structure can be built and tested independently or as part of the whole library.

To build and test all data structures:
```bash
./build.sh -t true
```

To build and test a specific data structure:
```bash
./build.sh -s <structure_name> -t true
```

## Common Features

- All data structures are implemented as header-only libraries
- Each data structure is under the `dataStructures` namespace
- C++17 standard is used throughout the codebase
- Comprehensive unit tests using Google Test
- Template-based implementations for type flexibility

## Available Data Structures

### Base Data Type (`baseDataType`)
Base functionality used by other data structures, providing common operations like:
- Element swapping
- Container printing

### Binary Heap (`binaryHeap`)
A max-heap implementation that:
- Maintains the heap property (parent > children)
- Provides O(log n) insertion and deletion
- Inherits from baseDataType for common operations

### Binary Search Tree (`binarySearchTree`)
A binary search tree implementation offering:
- Key-value storage
- O(log n) average case for operations
- Support for operations like rank and range queries 