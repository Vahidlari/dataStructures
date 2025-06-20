# Top level CMakeLists.txt for crackingCodingInterviews

cmake_minimum_required(VERSION 3.20.0)

project(crackingCodingInterviews C CXX)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Only enable testing if testing is enabled for this project
if(BUILD_CRACKINGCODINGINTERVIEWS_TESTING)
    # GoogleTest is already available from root CMakeLists.txt
    enable_testing()
endif()

# Get all chapter directories
file(GLOB COMPONENT_DIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} chapter*/CMakeLists.txt)
list(TRANSFORM COMPONENT_DIRS REPLACE "/CMakeLists.txt" "")

# Use project-specific component variable if available, otherwise fall back to global
if(DEFINED CRACKINGCODINGINTERVIEWS_SELECTED_COMPONENT)
    set(CURRENT_COMPONENT ${CRACKINGCODINGINTERVIEWS_SELECTED_COMPONENT})
else()
    set(CURRENT_COMPONENT ${SELECTED_COMPONENT})
endif()

# Component selection logic
if(CURRENT_COMPONENT)
    if(NOT CURRENT_COMPONENT IN_LIST COMPONENT_DIRS)
        message(FATAL_ERROR "Invalid crackingCodingInterviews component selected: ${CURRENT_COMPONENT}. Available components: ${COMPONENT_DIRS}")
    endif()
    message(STATUS "Building crackingCodingInterviews component: ${CURRENT_COMPONENT}")
    add_subdirectory(${CURRENT_COMPONENT})
    add_compile_definitions(ENABLE_CHAPTER_${CURRENT_COMPONENT})
else()
    message(STATUS "Building all crackingCodingInterviews components")
    foreach(component ${COMPONENT_DIRS})
        add_subdirectory(${component})
        add_compile_definitions(ENABLE_CHAPTER_${component})
    endforeach()
endif()