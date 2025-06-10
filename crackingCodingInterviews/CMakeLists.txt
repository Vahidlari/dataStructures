# Top level CMakeLists.txt for crackingCodingInterviews

cmake_minimum_required(VERSION 3.20.0)

project(crackingCodingInterviews C CXX)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Get all chapter directories
file(GLOB COMPONENT_DIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} chapter*/CMakeLists.txt)
list(TRANSFORM COMPONENT_DIRS REPLACE "/CMakeLists.txt" "")

# Component selection logic
if(SELECTED_COMPONENT)
    if(NOT SELECTED_COMPONENT IN_LIST COMPONENT_DIRS)
        message(FATAL_ERROR "Invalid component selected: ${SELECTED_COMPONENT}. Available components: ${COMPONENT_DIRS}")
    endif()
    message(STATUS "Building component: ${SELECTED_COMPONENT}")
    add_subdirectory(${SELECTED_COMPONENT})
    add_compile_definitions(ENABLE_CHAPTER_${SELECTED_COMPONENT})
else()
    message(STATUS "Building all components in ${CMAKE_CURRENT_SOURCE_DIR}")
    foreach(component ${COMPONENT_DIRS})
        add_subdirectory(${component})
        add_compile_definitions(ENABLE_CHAPTER_${component})
    endforeach()
endif()

# Add option for building tests
option(BUILD_TESTING "Build the testing tree." OFF)

# Only include GoogleTest if testing is enabled
if(BUILD_TESTING)
    # Include FetchContent for downloading GoogleTest
    include(FetchContent)

    # Download and configure GoogleTest
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    # Enable testing
    enable_testing()
endif()