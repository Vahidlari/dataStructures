#include <iostream>
#include <undirectedGraph.hpp>
#include <directedGraph.hpp>
#include <depthFirstSearch.hpp>
#include <breathFirstSearch.hpp>
#include <connectedComponents.hpp>
#include <depthFirstOrder.hpp>
#include <stronglyConnectedComponents.hpp>
#include <weightedEdgeGraph.hpp>
#include <unionFind.hpp>
#include <minimumSpanningTree.hpp>
#include <util.hpp>
#include <deque>

void printSortedEdgeList(typename CWeightedEdgeGraph::sorted_edge_list_t edgeList)
{
    for(CEdge edge : edgeList)
    {
        edge.print();
        std::cout << std::endl;
    }
}

void testUnionFind()
{
    CUnionFind myUf(10);
    myUf.addUnion(4,3);
    myUf.addUnion(3,8);
    myUf.addUnion(6,5);
    myUf.addUnion(9,4);
    myUf.addUnion(2,1);
    std::cout << "Connected 8, 9: " << myUf.connected(8,9) << std::endl;
    std::cout << "Connected 4, 5: " << myUf.connected(4,5) << std::endl;

}

void testWeightedEdgeGraph()
{
    CWeightedEdgeGraph myGraph(8);
    myGraph.addEdge(CEdge(0, 7, 0.16));
    myGraph.addEdge(CEdge(2, 3, 0.17));
    myGraph.addEdge(CEdge(1, 7, 0.19));
    myGraph.addEdge(CEdge(0, 2, 0.26));
    myGraph.addEdge(CEdge(5, 7, 0.28));
    myGraph.addEdge(CEdge(1, 3, 0.29));
    myGraph.addEdge(CEdge(1, 5, 0.32));
    myGraph.addEdge(CEdge(2, 7, 0.34));
    myGraph.addEdge(CEdge(4, 5, 0.35));
    myGraph.addEdge(CEdge(1, 2, 0.36));
    myGraph.addEdge(CEdge(4, 7, 0.37));
    myGraph.addEdge(CEdge(0, 4, 0.38));
    myGraph.addEdge(CEdge(6, 2, 0.40));
    myGraph.addEdge(CEdge(3, 6, 0.52));
    myGraph.addEdge(CEdge(6, 0, 0.58));
    myGraph.addEdge(CEdge(6, 4, 0.93));

    myGraph.print();
    auto sortedEdgeList = myGraph.getWeightSortedEdges();
    printSortedEdgeList(sortedEdgeList);

    CMinimumSpanningTree myMST(myGraph);
    myMST.printMst();

}

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
    testWeightedEdgeGraph();
    return 0;
}