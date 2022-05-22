add_library(minimumSpanningTree 
    inc/minimumSpanningTree.hpp 
    src/minimumSpanningTree.cpp
    inc/unionFind.hpp
    src/unionFind.cpp
)
target_include_directories(minimumSpanningTree PUBLIC ../weightedGraph/inc ../util/inc)