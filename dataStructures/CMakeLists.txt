cmake_minimum_required(VERSION 3.20.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(dataTypes C CXX)

add_executable(${PROJECT_NAME} testDataTypes.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(baseDataType)
add_subdirectory(binaryHeap)
add_subdirectory(binarySearchTree)

target_include_directories(${PROJECT_NAME} PUBLIC baseDataType/inc binaryHeap/inc binarySearchTree/inc)

target_link_directories(${PROJECT_NAME} PUBLIC baseDataType/ binaryHeap/ binarySearchTree/)

#target_compile_options(${PROJECT_NAME} PUBLIC -target x86_64-apple-darwin)

#add_custom_target(build-time-make-directory ALL
#    COMMAND ${CMAKE_COMMAND} -E make_directory build)

add_compile_definitions(${PROJECT_NAME} PRINT_ENABLED)

target_link_libraries(${PROJECT_NAME} baseDataType binaryHeap binarySearchTree)
