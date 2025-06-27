cmake_minimum_required(VERSION 3.14)

# Create the INTERFACE library for header-only implementation
add_library(stack INTERFACE)

# Create an alias target for the library
add_library(dataStructures::stack ALIAS stack)

# Set include directories for the interface library
target_include_directories(stack
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
        $<INSTALL_INTERFACE:inc>
)


# Add tests
if(BUILD_DATASTRUCTURES_TESTING)
    enable_testing()
    add_subdirectory(test)
endif()

