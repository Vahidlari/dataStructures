# chapter1

cmake_minimum_required(VERSION 3.20.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable debug symbols for all targets in this directory (and subdirectories)
set(CMAKE_BUILD_TYPE Debug)

project(chapter1 C CXX)

# Globe source and header files
file(GLOB_RECURSE CPP_FILES "src/*.cpp")

# Create the library
add_library(${PROJECT_NAME}_lib STATIC ${CPP_FILES})

# Set include directories for the library
target_include_directories(${PROJECT_NAME}_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

# Add source files
target_sources(${PROJECT_NAME}_lib
    PRIVATE
        ${CPP_FILES}
)

set_target_properties(${PROJECT_NAME}_lib PROPERTIES LINKER_LANGUAGE CXX)

# Add the test directory if testing is enabled
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()

