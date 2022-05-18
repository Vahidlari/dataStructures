cmake_minimum_required(VERSION 3.20.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(testGraph C CXX)

add_executable(${PROJECT_NAME} testGraph.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(undirectedGraph)
add_subdirectory(depthFirstSearch)
add_subdirectory(breathFirstSearch)

target_include_directories(${PROJECT_NAME} PUBLIC depthFirstSearch/inc breathFirstSearch/inc)

target_link_directories(${PROJECT_NAME} PUBLIC undirectedGraph/ depthFirstSearch/ breathFirstSearch/)

#target_compile_options(${PROJECT_NAME} PUBLIC -target x86_64-apple-darwin)

#add_custom_target(build-time-make-directory ALL
#    COMMAND ${CMAKE_COMMAND} -E make_directory build)

add_compile_definitions(${PROJECT_NAME} PRINT_ENABLED)

target_link_libraries(${PROJECT_NAME} undirectedGraph depthFirstSearch breathFirstSearch)
