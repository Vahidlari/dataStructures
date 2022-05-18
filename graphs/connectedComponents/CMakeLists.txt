add_library(connectedComponents inc/connectedComponents.hpp src/connectedComponents.cpp)
target_include_directories(connectedComponents PUBLIC ../undirectedGraph/inc)