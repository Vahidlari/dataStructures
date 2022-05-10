cmake_minimum_required(VERSION 3.14)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add each data structure as a subdirectory
add_subdirectory(baseDataType)
add_subdirectory(binarySearchTree)
add_subdirectory(binaryHeap)
