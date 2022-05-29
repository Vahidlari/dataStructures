add_library(shortestPath
    inc/shortestPath.hpp 
    src/shortestPath.cpp
    inc/vertixDistanceSet.hpp 
    src/vertixDistanceSet.cpp
)

target_include_directories(shortestPath PUBLIC ../directedWeightedGraph/inc ../util/inc)