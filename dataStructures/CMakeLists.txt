cmake_minimum_required(VERSION 3.14)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Get all subdirectories
file(GLOB COMPONENT_DIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} */CMakeLists.txt)
list(TRANSFORM COMPONENT_DIRS REPLACE "/CMakeLists.txt" "")

# Component selection logic
if(SELECTED_COMPONENT)
    if(NOT SELECTED_COMPONENT IN_LIST COMPONENT_DIRS)
        message(FATAL_ERROR "Invalid component selected: ${SELECTED_COMPONENT}. Available components: ${COMPONENT_DIRS}")
    endif()
    message(STATUS "Building component: ${SELECTED_COMPONENT}")
    add_subdirectory(${SELECTED_COMPONENT})
else()
    message(STATUS "Building all components in ${CMAKE_CURRENT_SOURCE_DIR}")
    foreach(component ${COMPONENT_DIRS})
        add_subdirectory(${component})
    endforeach()
endif()