cmake_minimum_required(VERSION 3.23.1)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(sort)

add_executable(${PROJECT_NAME} sortArray.cpp)

add_subdirectory(insertion)
add_subdirectory(selection)

target_include_directories(${PROJECT_NAME} PUBLIC selection/ insertion/)

target_link_directories(${PROJECT_NAME} PUBLIC selection/ insertion/)

#target_compile_options(${PROJECT_NAME} PUBLIC -target x86_64-apple-darwin)

#add_custom_target(build-time-make-directory ALL
#    COMMAND ${CMAKE_COMMAND} -E make_directory build)

target_link_libraries(${PROJECT_NAME} insertionSort selectionSort)
