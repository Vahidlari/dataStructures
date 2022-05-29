#ifndef VERTIXDISTANCESET_INCLUDED_
#define VERTIXDISTANCESET_INCLUDED_

#include <utility>
#include <set>
#include <directedWeightedEdge.hpp>

using namespace std;

struct TVertixDistancePairCompare
{
    using vertix_index_t = CDWEdge::vertix_index_t;
    using edge_weight_t = CDWEdge::edge_weight_t;
    using vertix_distance_pair_t = std::pair<vertix_index_t, edge_weight_t>;

    bool operator()(const vertix_distance_pair_t& a, const vertix_distance_pair_t& b) const
    {
        return a.second < b.second;
    }
};


class CVertixDistancePriorityList
{
public:
    using vertix_distance_pair_cmp = TVertixDistancePairCompare;
    using vertix_distance_pair_t = vertix_distance_pair_cmp::vertix_distance_pair_t;
    using vertix_distance_pair_list_t = std::set<vertix_distance_pair_t, vertix_distance_pair_cmp>;
    using vertix_index_t = CDWEdge::vertix_index_t;
    using edge_weight_t = CDWEdge::edge_weight_t;

    CVertixDistancePriorityList()
    {
    };

    void insert(vertix_index_t idx, edge_weight_t w);
    void update(vertix_index_t idx, edge_weight_t w);
    bool contains(vertix_index_t idx);
    bool isEmpty();
    vertix_distance_pair_t popMin();
    vertix_distance_pair_list_t::iterator get(vertix_index_t idx);
    void print();

private:
    vertix_distance_pair_list_t priorityList;
    

};


#endif //VERTIXDISTANCESET_INCLUDED_