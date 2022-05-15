#ifndef BINARYSEARCHTREE_INCLUDED_
#define BINARYSEARCHTREE_INCLUDED_

#include "treeNode.hpp"

template<typename Tkey, typename Tvalue>
class CBinarySearchTree
{
public:
    using key_t = Tkey;
    using value_t = Tvalue;
    using cnode_t = CNode<key_t, value_t>*;

    CBinarySearchTree()
        : root(nullptr)
    {
    };

    void put(key_t key, value_t value);
    void printLevelOrderedTraverse();
    int  height();

private:
    cnode_t put(cnode_t node, key_t key, value_t value);
    void printLevelOrderedTraverse(cnode_t node, int level);
    int  height(cnode_t node);

    cnode_t root;

};

#include "binarySearchTree.inl"

#endif //BINARYSEARCHTREE_INCLUDED_