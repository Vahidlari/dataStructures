# chapter2

cmake_minimum_required(VERSION 3.20.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable debug symbols for all targets in this directory (and subdirectories)
set(CMAKE_BUILD_TYPE Debug)

project(chapter2 C CXX)

# Globe source files under the src directory and add them to the library if the folder is not empty
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/src)
    file(GLOB_RECURSE CPP_FILES "src/*.cpp")
endif()

# Create the library if there are source files
add_library(${PROJECT_NAME}_lib)

# Set include directories for the library
target_include_directories(${PROJECT_NAME}_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

# Add source files
if(CPP_FILES)
    target_sources(${PROJECT_NAME}_lib
        PRIVATE
            ${CPP_FILES}
    )
endif()

set_target_properties(${PROJECT_NAME}_lib PROPERTIES LINKER_LANGUAGE CXX)

# Link required libraries to the project
target_link_libraries(${PROJECT_NAME}_lib
    PUBLIC
        dataStructures::linkedList
)

# Add the test directory if testing is enabled
if(BUILD_CRACKINGCODINGINTERVIEWS_TESTING)
    add_subdirectory(tests)
endif()
