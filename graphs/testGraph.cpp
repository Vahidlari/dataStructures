#include <iostream>
#include <undirectedGraph.hpp>
#include <depthFirstSearch.hpp>
#include <deque>



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

void testDfs(){
    CUndirectedGraph myGraph(11);
    myGraph.addEdge(1,3);
    myGraph.addEdge(1,2);
    myGraph.addEdge(3,5);
    myGraph.addEdge(3,4);
    myGraph.addEdge(4,6);
    myGraph.addEdge(5,6);
    myGraph.addEdge(6,7);
    myGraph.addEdge(7,8);
    myGraph.addEdge(7,9);
    std::cout << "number of vertices: " << myGraph.getVertixCount() << std::endl;
    std::cout << "number of edges: " << myGraph.getEdgeCount() << std::endl;
    CDfs myDfs(myGraph,1);
    uint32_t dst = 4;
    std::cout << "Does is has path to " << dst << ": " << myDfs.hasPathTo(dst) << std::endl;
    deque<uint32_t> path = myDfs.getPathTo(dst);
    for(auto& v : path)
    {
        std::cout << v << " -> ";
    }
    std::cout << std::endl;
}

int main()
{
    testDfs();
    return 0;
}