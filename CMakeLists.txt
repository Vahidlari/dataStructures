cmake_minimum_required(VERSION 3.14)
project(DataStructuresAndAlgorithms VERSION 1.0)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable ccache for faster builds
find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
    set(CMAKE_CXX_COMPILER_LAUNCHER ${CCACHE_PROGRAM})
    message(STATUS "ccache found and enabled: ${CCACHE_PROGRAM}")
else()
    message(STATUS "ccache not found, builds will not be cached")
endif()

# Enable testing
enable_testing()

# Include FetchContent for downloading dependencies
include(FetchContent)

# Only fetch GoogleTest if testing is enabled
if(BUILD_TESTING)
    # Fetch and make Google Test available with enhanced caching
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
        # Enhanced caching options to improve performance
        GIT_SHALLOW TRUE  # Only fetch the specific tag, not full history
        GIT_PROGRESS TRUE # Show progress during download
        GIT_SUBMODULES "" # Don't fetch submodules
    )
    
    # Configure GoogleTest to avoid rebuilding
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    set(BUILD_GMOCK ON CACHE BOOL "" FORCE)
    set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
    set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
    
    # Only make available if not already available
    FetchContent_GetProperties(googletest)
    if(NOT googletest_POPULATED)
        message(STATUS "Fetching GoogleTest...")
        FetchContent_Populate(googletest)
        add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
        message(STATUS "GoogleTest fetched and configured")
    else()
        message(STATUS "GoogleTest already available, skipping fetch")
    endif()
endif()

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
set(DATASTRUCTURES_COMPONENTS linkedList binarySearchTree binaryHeap baseDataType stack)
set(CRACKINGCODINGINTERVIEWS_COMPONENTS chapter1 chapter2)

# Validate selected project if one is specified
if(SELECTED_PROJECT)
    if(NOT SELECTED_PROJECT IN_LIST AVAILABLE_PROJECTS)
        message(FATAL_ERROR "Invalid project selected: ${SELECTED_PROJECT}. Available projects: ${AVAILABLE_PROJECTS}")
    endif()
    message(STATUS "Building project: ${SELECTED_PROJECT}")
    
    # Set testing variables for the selected project
    if(BUILD_TESTING)
        if(SELECTED_PROJECT STREQUAL "dataStructures")
            set(BUILD_DATASTRUCTURES_TESTING ON)
        elseif(SELECTED_PROJECT STREQUAL "crackingCodingInterviews")
            set(BUILD_CRACKINGCODINGINTERVIEWS_TESTING ON)
        endif()
    endif()
    
    # Validate component if specified
    if(SELECTED_COMPONENT)
        if(SELECTED_PROJECT STREQUAL "dataStructures")
            if(NOT SELECTED_COMPONENT IN_LIST DATASTRUCTURES_COMPONENTS)
                message(FATAL_ERROR "Invalid dataStructures component: ${SELECTED_COMPONENT}. Available components: ${DATASTRUCTURES_COMPONENTS}")
            endif()
        elseif(SELECTED_PROJECT STREQUAL "crackingCodingInterviews")
            if(NOT SELECTED_COMPONENT IN_LIST CRACKINGCODINGINTERVIEWS_COMPONENTS)
                message(FATAL_ERROR "Invalid crackingCodingInterviews component: ${SELECTED_COMPONENT}. Available components: ${CRACKINGCODINGINTERVIEWS_COMPONENTS}")
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