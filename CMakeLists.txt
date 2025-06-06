cmake_minimum_required(VERSION 3.14)
project(DataStructuresAndAlgorithms VERSION 1.0)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable testing
enable_testing()

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

# Project-specific component definitions
set(DATASTRUCTURES_COMPONENTS linkedList binarySearchTree binaryHeap baseDataType)
set(CRACKINGCODINGINTERVIEWS_COMPONENTS chapter1 chapter2)

# Validate selected project if one is specified
if(SELECTED_PROJECT)
    if(NOT SELECTED_PROJECT IN_LIST AVAILABLE_PROJECTS)
        message(FATAL_ERROR "Invalid project selected: ${SELECTED_PROJECT}. Available projects: ${AVAILABLE_PROJECTS}")
    endif()
    message(STATUS "Building project: ${SELECTED_PROJECT}")
    
    # Validate component if specified
    if(SELECTED_COMPONENT)
        if(SELECTED_PROJECT STREQUAL "dataStructures")
            if(NOT SELECTED_COMPONENT IN_LIST DATASTRUCTURES_COMPONENTS)
                message(FATAL_ERROR "Invalid dataStructures component: ${SELECTED_COMPONENT}. Available components: ${DATASTRUCTURES_COMPONENTS}")
            endif()
            if(BUILD_TESTING)
                set(BUILD_DATASTRUCTURES_TESTING ON)
            endif()
        elseif(SELECTED_PROJECT STREQUAL "crackingCodingInterviews")
            if(NOT SELECTED_COMPONENT IN_LIST CRACKINGCODINGINTERVIEWS_COMPONENTS)
                message(FATAL_ERROR "Invalid crackingCodingInterviews component: ${SELECTED_COMPONENT}. Available components: ${CRACKINGCODINGINTERVIEWS_COMPONENTS}")
            endif()
            if(BUILD_TESTING)
                set(BUILD_CRACKINGCODINGINTERVIEWS_TESTING ON)
            endif()
        endif()
        message(STATUS "Building component: ${SELECTED_COMPONENT}")
    endif()
else()
    message(STATUS "Building all projects")
    if(BUILD_TESTING)
        set(BUILD_DATASTRUCTURES_TESTING ON)
        set(BUILD_CRACKINGCODINGINTERVIEWS_TESTING ON)
    endif()
endif()

# Add selected projects with dependency handling
if(SELECTED_PROJECT)
    # Handle cross-project dependencies
    if(SELECTED_PROJECT STREQUAL "crackingCodingInterviews" AND (SELECTED_COMPONENT STREQUAL "chapter2" OR SELECTED_COMPONENT STREQUAL ""))
        message(STATUS "Chapter2 requires dataStructures::linkedList, adding dataStructures project")
        # Set project-specific component variables
        set(DATASTRUCTURES_SELECTED_COMPONENT "linkedList" CACHE STRING "Selected dataStructures component" FORCE)
        set(CRACKINGCODINGINTERVIEWS_SELECTED_COMPONENT ${SELECTED_COMPONENT} CACHE STRING "Selected crackingCodingInterviews component" FORCE)
        add_subdirectory(dataStructures)
    else()
        # Set project-specific component variables for single project builds
        if(SELECTED_PROJECT STREQUAL "dataStructures")
            set(DATASTRUCTURES_SELECTED_COMPONENT ${SELECTED_COMPONENT} CACHE STRING "Selected dataStructures component" FORCE)
        elseif(SELECTED_PROJECT STREQUAL "crackingCodingInterviews")
            set(CRACKINGCODINGINTERVIEWS_SELECTED_COMPONENT ${SELECTED_COMPONENT} CACHE STRING "Selected crackingCodingInterviews component" FORCE)
        endif()
    endif()
    
    add_subdirectory(${SELECTED_PROJECT})
else()
    foreach(proj ${AVAILABLE_PROJECTS})
        if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${proj}/CMakeLists.txt)
            add_subdirectory(${proj})
        endif()
    endforeach()
endif()