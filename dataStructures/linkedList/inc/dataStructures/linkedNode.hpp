#ifndef BASENODE_INCLUDED_
#define BASENODE_INCLUDED_

#include <memory>

namespace dataStructures
{

template <typename T> using raw_ptr = T*;

/**
 * @brief A node for singly or doubly linked list
 * 
 * This class represents a node in a singly linked list.
 * 
 * @tparam Ttype The type of data stored in the node
 */
template<typename Ttype, template<typename> class PtrType = raw_ptr>
class CLinkedNode
{
public:
    using node_data_t = Ttype; // The type of data stored in the node
    using node_t = CLinkedNode<Ttype, PtrType>; // The type of the node itself
    using node_ptr_t = PtrType<node_t>; // Pointer to the node type

    /**
     * @brief Default constructor
     */
    CLinkedNode() = default;

    /**
     * @brief Destructor
     */
    virtual ~CLinkedNode() = default;

    /**
     * @brief Constructor
     * @param _data The data to store in the node
     */
    CLinkedNode(node_data_t _data) : data(_data) {}

    /**
     * @brief Copy constructor
     * @param other The node to copy
     */
    CLinkedNode(const node_t& other) : data(other.data) {}

    /**
     * @brief Assignment operator
     * @param other The node to assign
     * @return The assigned node
     */
    CLinkedNode& operator=(const node_t& other);

    /**
     * @brief Get the data stored in the node
     * @return The data stored in the node
     */
    const node_data_t& getData() const;

    /**
     * @brief Set the data stored in the node
     * @param _data The data to store in the node
     */
    void setData(node_data_t _data);

    /** 
     * @brief Set the data stored in the node
     * @param _data The data to store in the node
     */
    node_ptr_t getNext() const;

    /**
     * @brief Set the next node in the list
     * @param _next The next node in the list
     */
    void setNext(node_ptr_t _next);

    /**
     * @brief Get the previous node in the list
     * @return The previous node in the list
     */
    node_ptr_t getPrevious() const;

    /**
     * @brief Set the previous node in the list
     * @param _previous The previous node in the list
     */
    void setPrevious(node_ptr_t _previous);

    /**
     * @brief Print the data stored in the node
     */
    void print() const;

private:
    node_data_t data{}; // The data stored in the node
    node_ptr_t next{nullptr}; // The next node in the list
    node_ptr_t previous{nullptr}; // The previous node in the list

};
} // namespace dataStructures

#include "dataStructures/linkedNode.inl"

#endif //BASENODE_INCLUDED_