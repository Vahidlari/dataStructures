cmake_minimum_required(VERSION 3.14)
project(DataStructuresAndAlgorithms VERSION 1.0)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable testing
enable_testing()

# Set debug flags when testing is enabled
if(BUILD_TESTING)
    message(STATUS "Setting debug flags for test builds")
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Set build type to Debug when testing" FORCE)
    add_compile_options(-g3 -O0)
endif()

# Include FetchContent for downloading dependencies
include(FetchContent)

# Fetch and make Google Test available
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

# Add compiler warnings
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Project selection logic
set(AVAILABLE_PROJECTS dataStructures crackingCodingInterviews)
set(SELECTED_PROJECT "" CACHE STRING "Selected project to build")
set(SELECTED_COMPONENT "" CACHE STRING "Selected component to build")

# Validate selected project if one is specified
if(SELECTED_PROJECT)
    if(NOT SELECTED_PROJECT IN_LIST AVAILABLE_PROJECTS)
        message(FATAL_ERROR "Invalid project selected: ${SELECTED_PROJECT}. Available projects: ${AVAILABLE_PROJECTS}")
    endif()
    message(STATUS "Building project: ${SELECTED_PROJECT}")
    if(SELECTED_COMPONENT)
        message(STATUS "Building component: ${SELECTED_COMPONENT}")
    endif()
else()
    message(STATUS "Building all projects")
endif()

# Add selected projects
if(SELECTED_PROJECT)
    add_subdirectory(${SELECTED_PROJECT})
else()
    foreach(proj ${AVAILABLE_PROJECTS})
        if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${proj}/CMakeLists.txt)
            add_subdirectory(${proj})
        endif()
    endforeach()
endif()