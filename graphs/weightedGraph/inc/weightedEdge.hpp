#ifndef WEIGHTEDEDGE_INCLUDED_
#define WEIGHTEDEDGE_INCLUDED_

class CEdge
{
public:
    using vertix_index_t = unsigned int;
    using edge_weight_t = float;

    CEdge() = default;
    CEdge(vertix_index_t src, vertix_index_t dst, edge_weight_t weight)
        : srcV(src), dstV(dst), w(weight)
    {
    }
    CEdge(const CEdge& other)
        : srcV(other.srcV), dstV(other.dstV), w(other.w)
    {
    }
    
    const vertix_index_t either() const;
    const vertix_index_t other(vertix_index_t v) const;
    const edge_weight_t weight() const;
    bool operator>(const CEdge& other);
    bool operator<(const CEdge& other);
    bool operator==(const CEdge& other);
    CEdge& operator=(const CEdge& other);
    static int compareTo(const CEdge& lhs, const CEdge& rsh);
    void print() const;

private:
    vertix_index_t srcV, dstV;
    edge_weight_t w;
};
#endif //WEIGHTEDEDGE_INCLUDED_