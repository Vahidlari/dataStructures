cmake_minimum_required(VERSION 3.14)

# Create the INTERFACE library for header-only implementation
add_library(baseDataType INTERFACE)

# Create an alias target for the library
add_library(dataStructures::baseDataType ALIAS baseDataType)

# Set include directories for the interface library
target_include_directories(baseDataType
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
        $<INSTALL_INTERFACE:inc>
)

# Add tests
if(BUILD_TESTING)
    add_subdirectory(test)
endif()

