cmake_minimum_required(VERSION 3.14)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Get all subdirectories
file(GLOB COMPONENT_DIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} */CMakeLists.txt)
list(TRANSFORM COMPONENT_DIRS REPLACE "/CMakeLists.txt" "")

# Use project-specific component variable if available, otherwise fall back to global
if(DEFINED DATASTRUCTURES_SELECTED_COMPONENT)
    set(CURRENT_COMPONENT ${DATASTRUCTURES_SELECTED_COMPONENT})
else()
    set(CURRENT_COMPONENT ${SELECTED_COMPONENT})
endif()

# Component selection logic - use project-specific validation from root
if(CURRENT_COMPONENT)
    if(NOT CURRENT_COMPONENT IN_LIST COMPONENT_DIRS)
        message(FATAL_ERROR "Invalid dataStructures component selected: ${CURRENT_COMPONENT}. Available components: ${COMPONENT_DIRS}")
    endif()
    message(STATUS "Building dataStructures component: ${CURRENT_COMPONENT}")
    add_subdirectory(${CURRENT_COMPONENT})
else()
    message(STATUS "Building all dataStructures components")
    foreach(component ${COMPONENT_DIRS})
        add_subdirectory(${component})
    endforeach()
endif()