add_library(stronglyConnectedComponents 
    inc/stronglyConnectedComponents.hpp 
    src/stronglyConnectedComponents.cpp
    inc/depthFirstOrder.hpp 
    src/depthFirstOrder.cpp
)
target_include_directories(stronglyConnectedComponents PUBLIC ../directedGraph/inc ../util/inc)