cmake_minimum_required(VERSION 3.14)

# Create the INTERFACE library for header-only implementation
add_library(binarySearchTree INTERFACE)

# Create an alias target for the library
add_library(dataStructures::binarySearchTree ALIAS binarySearchTree)

# Set include directories for the interface library
target_include_directories(binarySearchTree
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
        $<INSTALL_INTERFACE:inc>
)

# Add tests
if(BUILD_DATASTRUCTURES_TESTING)
    add_subdirectory(test)
endif()

