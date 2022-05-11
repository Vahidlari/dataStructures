cmake_minimum_required(VERSION 3.20.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(sort C CXX)

add_executable(${PROJECT_NAME} sortArray.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(insertion)
add_subdirectory(selection)
add_subdirectory(../dataStructures/baseDataType baseDataType)
add_subdirectory(../dataStructures/binaryHeap binaryHeap)
add_subdirectory(heapSort)

target_include_directories(${PROJECT_NAME} PUBLIC selection/inc insertion/inc heapSort/inc ../dataStructures/binaryHeap/inc ../dataStructures/baseDataType/inc)

target_link_directories(${PROJECT_NAME} PUBLIC selection/ insertion/ heapSort/inc ../dataStructures/binaryHeap/inc ../dataStructures/baseDataType/inc)

#target_compile_options(${PROJECT_NAME} PUBLIC -target x86_64-apple-darwin)

#add_custom_target(build-time-make-directory ALL
#    COMMAND ${CMAKE_COMMAND} -E make_directory build)

#add_compile_definitions(${PROJECT_NAME} PRINT_ENABLED2)

target_link_libraries(${PROJECT_NAME} insertionSort selectionSort binaryHeap heapSort baseDataType)
