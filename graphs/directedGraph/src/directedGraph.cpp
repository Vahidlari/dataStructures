#include "../inc/directedGraph.hpp"
#include <iostream>

CDirectedGraph::CDirectedGraph(int numberOfVertices)
{
    adjacencyListArray.resize(numberOfVertices);
}

CDirectedGraph::CDirectedGraph(const CDirectedGraph& _graph)
{
    adjacencyListArray = _graph.adjacencyListArray;
}

CDirectedGraph::CDirectedGraph(const adjacencyListArray_t& _adjancencyListArray)
{
    adjacencyListArray = _adjancencyListArray;
}


void CDirectedGraph::addEdge(int src, int dst)
{
    if(src < adjacencyListArray.size() && dst < adjacencyListArray.size())
    {
        adjacencyListArray[src].push_back(dst);
    }
}

const typename CDirectedGraph::adjacencyList_t&  CDirectedGraph::getAdjacents(int v)
{
    return adjacencyListArray[v];
}

uint32_t CDirectedGraph::getVertixCount()
{
    return adjacencyListArray.size();
}

uint32_t CDirectedGraph::getEdgeCount()
{
    uint32_t size = 0;
    for(auto& v : adjacencyListArray)
    {
        size += v.size();
    }
    return size;
}

void CDirectedGraph::print()
{
    for(int src = 0; src < adjacencyListArray.size(); src++)
    {
        for(auto& dst : adjacencyListArray[src])
        {
            std::cout << "(" << src << " --> " << dst << "), "; 
        }
        std::cout << std::endl;
    }
}

CDirectedGraph& CDirectedGraph::operator=(const CDirectedGraph& right){
    if(this == &right){
        return *this;
    }
    adjacencyListArray = right.adjacencyListArray;
    return *this;
}

typename CDirectedGraph::adjacencyListArray_t CDirectedGraph::getReverseAdjListArray(){
    adjacencyListArray_t reverseAdjListArray(adjacencyListArray.size());
    for(int i = 0; i < adjacencyListArray.size(); i++)
    {
        for(int j = 0; j < adjacencyListArray[i].size(); j++)
        {
            reverseAdjListArray[adjacencyListArray[i][j]].push_back(i);
        }
    }
    return reverseAdjListArray; 
}

CDirectedGraph CDirectedGraph::reverse()
{
    return CDirectedGraph(getReverseAdjListArray());
}