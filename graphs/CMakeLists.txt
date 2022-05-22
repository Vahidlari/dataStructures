cmake_minimum_required(VERSION 3.20.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(testGraph C CXX)

add_executable(${PROJECT_NAME} testGraph.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(undirectedGraph)
add_subdirectory(directedGraph)
add_subdirectory(depthFirstSearch)
add_subdirectory(breathFirstSearch)
add_subdirectory(connectedComponents)
add_subdirectory(stronglyConnectedComponents)
add_subdirectory(weightedGraph)

target_include_directories(${PROJECT_NAME} PUBLIC 
    depthFirstSearch/inc 
    breathFirstSearch/inc 
    connectedComponents/inc 
    stronglyConnectedComponents/inc 
    weightedGraph/inc
‚) 

target_link_directories(${PROJECT_NAME} PUBLIC 
    undirectedGraph/ 
    directedGraph/ 
    depthFirstSearch/ 
    breathFirstSearch/
    connectedComponents/ 
    stronglyConnectedComponents/ 
    weightedGraph/
)

#target_compile_options(${PROJECT_NAME} PUBLIC -target x86_64-apple-darwin)

#add_custom_target(build-time-make-directory ALL
#    COMMAND ${CMAKE_COMMAND} -E make_directory build)

add_compile_definitions(${PROJECT_NAME} PRINT_ENABLED)

target_link_libraries(${PROJECT_NAME} 
    undirectedGraph 
    directedGraph 
    depthFirstSearch 
    breathFirstSearch 
    connectedComponents 
    stronglyConnectedComponents
    weightedGraph
)
