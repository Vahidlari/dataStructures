#ifndef SHORTESTPATH_INCLUDED_
#define SHORTESTPATH_INCLUDED_

#include <directedWeightedEdgeGraph.hpp>
#include "vertixDistanceSet.hpp"
#include <deque>
#include <vector>
#include <limits>


enum class EShortPathAlgorithm
{
    dijkstra
};

class CShortestPath
{
public:
    using short_path_algorith_t = EShortPathAlgorithm;
    using graph_t = CDirectedWeightedEdgeGraph;
    using path_t = std::deque<graph_t::edge_t>;
    using edge_t = CDirectedWeightedEdgeGraph::edge_t;
    using edge_weight_t = edge_t::edge_weight_t;
    using vertix_distance_pair_cmp = TVertixDistancePairCompare;
    using vertix_distance_pair_t = vertix_distance_pair_cmp::vertix_distance_pair_t;
    using vertix_distance_pair_list_t = CVertixDistancePriorityList;
    using weightLimits_t = std::numeric_limits<edge_weight_t>;


    CShortestPath() = default;

    CShortestPath(graph_t& graph, int src, short_path_algorith_t algorithm);
    
    path_t getPathTo(int dst);
    void   printEdgeTo();
    void   printDistanceTo();
    
private:
    /// The algorithm maintains an array of distances from source to each vertix
    /// and an array indicating which input edge to a vertix contains in the shortest path.
    /// Starting from the source vertix, the algorithm updates a sorted list of distances to 
    /// unvisited vertices. The list gets updated when a vertix is visited, in which, the distances to 
    /// its destination vertices are updated if they could be reached in a shorter path compared to
    /// existing values in the distanceTo list. Each time a distance to a vertix is updated, the sorted
    /// list of distance to unvisited vertices gets updated. 
    /// the iterations continue till there is no item in vertix distance sorted list.
    void dijkstra(graph_t& graph, int src);
    void relax(const edge_t& e, vertix_distance_pair_list_t& distancePriorityList);


    std::vector<edge_weight_t> distanceTo;
    std::vector<edge_t> edgeTo;
    edge_t::vertix_index_t source;


};


#endif //SHORTESTPATH_INCLUDED_