#ifndef TREENODE_INCLUDED_
#define TREENODE_INCLUDED_

#include <iostream>
#define nullptr 0

template <typename Tkey, typename Tvalue>
class CNode{
public:
    using key_t = Tkey;
    using value_t = Tvalue;
    using cnodeptr_t = CNode<key_t, value_t>*;

    CNode()
        : key(), value(), left(nullptr), right(nullptr)
    {
    };
    
    CNode(key_t _key, value_t _value)
        : key(_key), value(_value)
    {
        left = right = nullptr;
    }
    CNode(CNode& node)
        : key(node.key), value(node.value), left(node.left), right(node.right)
    {
    }

    void print(){
        std::cout << "(" << key << ", " << value;
        if (left)
        {
            std::cout << ", left active";
        }
        if (right)
        {
            std::cout << ", right active";
        }
        std::cout << ")";
    }

    void printLineBreaked(){
        print();
        std::cout << std::endl;
    }

    key_t    key;
    value_t  value;
    cnodeptr_t  left;
    cnodeptr_t  right;
};

#endif //TREENODE_INCLUDED_