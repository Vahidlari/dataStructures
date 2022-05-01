cmake_minimum_required(VERSION 3.23.1)
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")

project(sort)

add_subdirectory(insertion)
add_subdirectory(selection)

add_executable(${PROJECT_NAME} sortArray.cpp)

#target_compile_options(${PROJECT_NAME} PUBLIC -target x86_64-apple-darwin)

#add_custom_target(build-time-make-directory ALL
#    COMMAND ${CMAKE_COMMAND} -E make_directory build)

target_link_libraries(${PROJECT_NAME} insertionSort selectionSort)
target_link_directories(${PROJECT_NAME} PUBLIC selection/)