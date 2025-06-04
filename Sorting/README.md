# Sorting Algorithms

This directory contains implementations of various sorting algorithms in C++.

## Implemented Algorithms

The following sorting algorithms are implemented (or planned to be implemented):

### Comparison-based Sorting
- Bubble Sort
- Selection Sort
- Insertion Sort
- Merge Sort
- Quick Sort
- Heap Sort
- Shell Sort

### Non-comparison Sorting
- Counting Sort
- Radix Sort
- Bucket Sort

## Features

Each sorting algorithm implementation includes:
- Clean, well-documented source code
- Time and space complexity analysis
- Performance benchmarks
- Comparison with other sorting algorithms
- Unit tests

## Performance Analysis

Each implementation includes performance measurements for different input sizes and types:
- Random data
- Nearly sorted data
- Reverse sorted data
- Data with many duplicates

## Usage

Each sorting algorithm is implemented as a template function that can work with any comparable data type. Example usage:

```cpp
#include "quick_sort.hpp"

std::vector<int> arr = {5, 2, 8, 1, 9};
quickSort(arr.begin(), arr.end());
```

## Building and Testing

```bash
mkdir _build
cd _build
cmake ..
make
./run_tests  # Run unit tests
./benchmark  # Run benchmarks
``` 