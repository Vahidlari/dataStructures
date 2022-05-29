#include "../inc/directedWeightedEdge.hpp"
#include <iostream>

const typename CDWEdge::vertix_index_t CDWEdge::from() const{
    return srcV;
}

const typename CDWEdge::vertix_index_t CDWEdge::to() const{
    return dstV;
}

const typename CDWEdge::edge_weight_t CDWEdge::weight() const{
    return w;
}

void CDWEdge::print() const{
    std::cout << "(" << srcV << ", " << dstV << " | " << w << ")";
}

bool CDWEdge::operator>(const CDWEdge& other){
    return w > other.w;
}

bool CDWEdge::operator<(const CDWEdge& other){
    return w < other.w;
}

bool CDWEdge::operator==(const CDWEdge& other){
    return w == other.w;
}

CDWEdge& CDWEdge::operator=(const CDWEdge& other){
    w = other.w;
    srcV = other.srcV;
    dstV = other.dstV;
    return *this;
}

int CDWEdge::compareTo(const CDWEdge& lhs, const CDWEdge& rhs)
{
    if(lhs.w < rhs.w)
    {
        return -1;
    } else if (lhs.w < rhs.w)
    {
        return 1;
    }
    return 0;
}