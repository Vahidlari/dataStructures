#include "../inc/undirectedGraph.hpp"
#include <iostream>

CUndirectedGraph::CUndirectedGraph(int numberOfVertices)
{
    adjacencyListArray.resize(numberOfVertices);
}

void CUndirectedGraph::addEdge(int src, int dst)
{
    if(src < adjacencyListArray.size() && dst < adjacencyListArray.size())
    {
        adjacencyListArray[src].push_back(dst);
        adjacencyListArray[dst].push_back(src);
    }
}

const vector<typename CUndirectedGraph::vertix_index_t>&  CUndirectedGraph::getAdjacents(int v)
{
    return adjacencyListArray[v];
}

uint32_t CUndirectedGraph::getVertixCount()
{
    return adjacencyListArray.size();
}

uint32_t CUndirectedGraph::getEdgeCount()
{
    uint32_t size = 0;
    for(auto& v : adjacencyListArray)
    {
        size += v.size();
    }
    return size/2;
}

void CUndirectedGraph::print()
{
    for(int src = 0; src < adjacencyListArray.size(); src++)
    {
        for(auto& dst : adjacencyListArray[src])
        {
            std::cout << "(" << src << ", " << dst << "), "; 
        }
        std::cout << std::endl;
    }
}