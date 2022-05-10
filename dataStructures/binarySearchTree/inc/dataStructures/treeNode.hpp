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
    using size_t = uint32_t;

    CNode()
        : key(), value(), left(nullptr), right(nullptr), count(1)
    {
    };
    
    CNode(key_t _key, value_t _value)
        : key(_key), value(_value), count(1)

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

        std::cout << ", size: " << count << ")";
    }

    void printLineBreaked(){
        print();
        std::cout << std::endl;
    }

    size_t size(){
        return count;        
    }

    size_t updateSize()
    {
        count = 1;
        if(left != nullptr)
        {
            count += left->size();
        }
        if(right != nullptr)
        {
            count += right->size();
        }
        return count;
    }

    key_t    key;
    value_t  value;
    cnodeptr_t  left;
    cnodeptr_t  right;

private:
    size_t  count;
};

#endif //TREENODE_INCLUDED_