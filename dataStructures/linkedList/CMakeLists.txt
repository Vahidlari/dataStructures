cmake_minimum_required(VERSION 3.14)

# Create the INTERFACE library for header-only implementation
add_library(linkedList INTERFACE)

# Create an alias target for the library
add_library(dataStructures::linkedList ALIAS linkedList)

# Set include directories for the interface library
target_include_directories(linkedList
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
        $<INSTALL_INTERFACE:inc>
)


# Add tests
if(BUILD_DATASTRUCTURES_TESTING)
    enable_testing()
    add_subdirectory(test)
endif()

