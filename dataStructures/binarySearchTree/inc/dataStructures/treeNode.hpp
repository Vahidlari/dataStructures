#ifndef TREENODE_INCLUDED_
#define TREENODE_INCLUDED_

#include <iostream>

/**
 * @brief A node in a binary search tree
 * @tparam Tkey The type of the key
 * @tparam Tvalue The type of the value
 * @note This class is used to store a key-value pair in a binary search tree
 * @note The key is used to store the key of the node
 * @note The value is used to store the value of the node
 * @note The left and right pointers are used to store the left and right children of the node
 * @note The count is used to store the number of nodes in the subtree
 */
template <typename Tkey, typename Tvalue>
class CNode{
public:
    using key_t = Tkey;
    using value_t = Tvalue;
    using cnodeptr_t = CNode<key_t, value_t>*;
    using size_t = uint32_t;

    /**
     * @brief Default constructor
     * @note This constructor is used to construct a new node with the default values
     */
    CNode()
        : key(), value(), left(nullptr), right(nullptr), count(1)
    {
    };
    
    /**
     * @brief Constructor
     * @param _key The key of the node
     * @param _value The value of the node
     * @note This constructor is used to construct a new node with the given key and value
     */
    CNode(key_t _key, value_t _value)
        : key(_key), value(_value), count(1)

    {
        left = right = nullptr;
    }

    /**
     * @brief Copy constructor
     * @param node The node to copy
     * @note This constructor is used to copy a node
     */
    CNode(CNode& node)
        : key(node.key), value(node.value), left(node.left), right(node.right)
    {
    }

    /**
     * @brief Print the node
     * @note This function is used to print the node
     */
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

    /**
     * @brief Print the node with a line break
     * @note This function is used to print the node with a line break
     */
    void printLineBreaked(){
        print();
        std::cout << std::endl;
    }

    /**
     * @brief Get the size of the node
     * @note This function is used to get the size of the node
     */
    size_t size(){
        return count;        
    }

    /**
     * @brief Update the size of the node
     * @note This function is used to update the size of the node
     */
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

    key_t    key;   //!< The key of the node
    value_t  value; //!< The value of the node
    cnodeptr_t  left; //!< The left child of the node
    cnodeptr_t  right; //!< The right child of the node

private:
    size_t  count;
};

#endif //TREENODE_INCLUDED_