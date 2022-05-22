#include "../inc/weightedEdge.hpp"
#include <iostream>

const typename CEdge::vertix_index_t CEdge::either() const{
    return srcV;
}

const typename CEdge::vertix_index_t CEdge::other(vertix_index_t v) const{
    return (v == srcV)? dstV: srcV;
}

const typename CEdge::edge_weight_t CEdge::weight() const{
    return w;
}

void CEdge::print() const{
    std::cout << "(" << srcV << ", " << dstV << " | " << w << ")";
}

bool CEdge::operator>(const CEdge& other){
    return w > other.w;
}

bool CEdge::operator<(const CEdge& other){
    return w < other.w;
}

bool CEdge::operator==(const CEdge& other){
    return w == other.w;
}

CEdge& CEdge::operator=(const CEdge& other){
    w = other.w;
    srcV = other.srcV;
    dstV = other.dstV;
    return *this;
}

int CEdge::compareTo(const CEdge& lhs, const CEdge& rhs)
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