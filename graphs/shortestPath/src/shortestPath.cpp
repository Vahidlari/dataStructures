#include "../inc/shortestPath.hpp"
#include <iostream>
#include <util.hpp>

CShortestPath::CShortestPath(graph_t& graph, int src, short_path_algorith_t algorithm){
    edgeTo.resize(graph.getVertixCount());
    distanceTo.resize(graph.getVertixCount());
    std::fill(distanceTo.begin(), distanceTo.end(), weightLimits_t::max());

    switch (algorithm)
    {
    case short_path_algorith_t::dijkstra:
        dijkstra(graph,src);
        break;    
    default:
        break;
    }
}   
 
typename CShortestPath::path_t CShortestPath::getPathTo(int dst)
{
    path_t path;
    edge_t::vertix_index_t v = dst;
    while(edgeTo[v].from() != edgeTo[v].to())
    {
        path.push_front(edgeTo[v]);
        v = edgeTo[v].from();
    }
    
    return path; 
}

void CShortestPath::dijkstra(graph_t& graph, int src){
    std::cout << "dijkstra's shortest path calculation from " << src << std::endl;
    distanceTo[src] = 0;
    vertix_distance_pair_list_t distancePriorityList;
    distancePriorityList.insert(src, 0);
    while(!distancePriorityList.isEmpty())
    {
        distancePriorityList.print();
        vertix_distance_pair_t minDistVirtex = distancePriorityList.popMin();
        for(const edge_t& edge : graph.getAdjacents(minDistVirtex.first))
        {
            relax(edge, distancePriorityList);
        }
        
    }
}

void CShortestPath::relax(const edge_t& e, vertix_distance_pair_list_t& distancePriorityList){
    edge_t::vertix_index_t src = e.from();
    edge_t::vertix_index_t dst = e.to();

    std::cout << "Relaxing "; 
    e.print();
    std::cout <<  "distanceTo[src]: " << distanceTo[src] << ", distanceTo[dst]: " << distanceTo[dst] << std::endl;
    if(distanceTo[dst] > distanceTo[src] + e.weight())
    {
        distanceTo[dst] = distanceTo[src] + e.weight();
        edgeTo[dst] = e;
        if(distancePriorityList.contains(dst))
        {
            distancePriorityList.update(dst, distanceTo[dst]);
            std::cout << "distancePriorityList updated " << dst << ", " <<  distanceTo[dst] << std::endl;
        } else 
        {
            distancePriorityList.insert(dst, distanceTo[dst]);
            std::cout << "distancePriorityList inserted " << dst << ", " <<  distanceTo[dst] << std::endl;
        }
    }
}

void CShortestPath::printEdgeTo()
{
    int i = 0;
    for(edge_t& edge: edgeTo)
    {
        std::cout << i << ": ";
        edge.print();
        std::cout <<"\n";
        ++i;
    }
}

void CShortestPath::printDistanceTo()
{
    for(int i = 0; i < distanceTo.size(); ++i)
    {
        std::cout << i << ": " << distanceTo[i] << "\n";
    }
}

