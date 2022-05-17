#include <iostream>
#include <undirectedGraph.hpp>


void testDirectedGraph()
{
    CUndirectedGraph myGraph(5);
    myGraph.addEdge(0,1);
    myGraph.addEdge(1,2);
    myGraph.addEdge(2,3);
    myGraph.addEdge(3,4);
    myGraph.addEdge(4,0);

    std::cout << "number of vertices: " << myGraph.getVertixCount() << std::endl;
    std::cout << "number of edges: " << myGraph.getEdgeCount() << std::endl;

    myGraph.print();
}

int main()
{
    testDirectedGraph();
    return 0;
}