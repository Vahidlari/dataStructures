#include <iostream>
#include <undirectedGraph.hpp>
#include <directedGraph.hpp>
#include <depthFirstSearch.hpp>
#include <breathFirstSearch.hpp>
#include <connectedComponents.hpp>
#include <depthFirstOrder.hpp>
#include <stronglyConnectedComponents.hpp>
#include <util.hpp>
#include <deque>

void testSCC()
{
    CDirectedGraph myGraph(13);
    myGraph.addEdge(0,1);
    myGraph.addEdge(0,5);
    myGraph.addEdge(2,0);
    myGraph.addEdge(2,3);
    myGraph.addEdge(3,2);
    myGraph.addEdge(3,5);
    myGraph.addEdge(4,2);
    myGraph.addEdge(4,3);
    myGraph.addEdge(5,4);
    myGraph.addEdge(6,0);
    myGraph.addEdge(6,4);
    myGraph.addEdge(6,8);
    myGraph.addEdge(6,9);
    myGraph.addEdge(7,6);
    myGraph.addEdge(7,9);
    myGraph.addEdge(8,6);
    myGraph.addEdge(9,10);
    myGraph.addEdge(9,11);
    myGraph.addEdge(10,12);
    myGraph.addEdge(11,12);
    myGraph.addEdge(11,4);
    myGraph.addEdge(12,9);
    std::cout << "number of vertices: " << myGraph.getVertixCount() << std::endl;
    std::cout << "number of edges: " << myGraph.getEdgeCount() << std::endl;
    // CDepthFirstOrder myReverse;
    // CDirectedGraph myReverseGraph = myGraph.reverse();
    // myReverseGraph.print();
    // print(myReverse.postOrderList(myReverseGraph));
    CStronglyConnectedComponents myScc(myGraph);
    std::cout << "Number of connected components: " << myScc.getNumberOfComponents() << std::endl;
    myScc.printConnectedComponents();

}

void testUnDirectedGraph()
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

void testDirectedGraph()
{
    CDirectedGraph myGraph(7);
    myGraph.addEdge(0,1);
    myGraph.addEdge(0,2);
    myGraph.addEdge(0,5);
    myGraph.addEdge(1,4);
    myGraph.addEdge(3,2);
    myGraph.addEdge(3,4);
    myGraph.addEdge(3,5);
    myGraph.addEdge(3,6);
    myGraph.addEdge(5,2);
    myGraph.addEdge(6,0);
    std::cout << "number of vertices: " << myGraph.getVertixCount() << std::endl;
    std::cout << "number of edges: " << myGraph.getEdgeCount() << std::endl;
    myGraph.print();
    myGraph.reverse().print();
    CDepthFirstOrder myPostOrder;
    print(myPostOrder.postOrderList(myGraph));

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
    std::cout << "Does it have a path to " << dst << ": " << myDfs.hasPathTo(dst) << std::endl;
    deque<uint32_t> path = myDfs.getPathTo(dst);
    print(path);
}

void testBfs(){
    CUndirectedGraph myGraph(11);
    myGraph.addEdge(1,3);
    myGraph.addEdge(1,2);
    myGraph.addEdge(3,5);
    myGraph.addEdge(3,4);
    myGraph.addEdge(4,6);
    myGraph.addEdge(5,6);
    //myGraph.addEdge(6,7);
    myGraph.addEdge(7,8);
    myGraph.addEdge(7,9);
    std::cout << "number of vertices: " << myGraph.getVertixCount() << std::endl;
    std::cout << "number of edges: " << myGraph.getEdgeCount() << std::endl;
    CBfs myBfs(myGraph,1);
    uint32_t dst = 9;
    std::cout << "Does it have a path to " << dst << ": " << myBfs.hasPathTo(dst) << std::endl;
    deque<uint32_t> path = myBfs.getPathTo(dst);
    for(auto& v : path)
    {
        std::cout << v << " -> ";
    }
    std::cout << std::endl;
    CConnectedComponents myConnectedComponents(myGraph);
    std::cout << "Number of connected components: " << myConnectedComponents.getNumberOfComponents();
    myConnectedComponents.printConnectedComponents();
}

int main()
{
    testSCC();
    return 0;
}