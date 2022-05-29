#ifndef DIRECTEDWEIGHTEDEDGE_INCLUDED_
#define DIRECTEDWEIGHTEDEDGE_INCLUDED_

class CDWEdge
{
public:
    using vertix_index_t = unsigned int;
    using edge_weight_t = float;

    CDWEdge() = default;
    CDWEdge(vertix_index_t src, vertix_index_t dst, edge_weight_t weight)
        : srcV(src), dstV(dst), w(weight)
    {
    }
    CDWEdge(const CDWEdge& other)
        : srcV(other.srcV), dstV(other.dstV), w(other.w)
    {
    }
    
    const vertix_index_t from() const;
    const vertix_index_t to() const;
    const edge_weight_t weight() const;
    bool operator>(const CDWEdge& other);
    bool operator<(const CDWEdge& other);
    bool operator==(const CDWEdge& other);
    CDWEdge& operator=(const CDWEdge& other);
    static int compareTo(const CDWEdge& lhs, const CDWEdge& rsh);
    void print() const;

private:
    vertix_index_t srcV, dstV;
    edge_weight_t w;
};
#endif //DIRECTEDWEIGHTEDEDGE_INCLUDED_