#ifndef SINGLEY_LINKED_LIST_INCLUDED_
#define SINGLEY_LINKED_LIST_INCLUDED_

#include "dataStructures/linkedNode.hpp"

namespace dataStructures {

/**
    * @brief A singly linked list that can store elements of type Ttype.
    * @tparam Ttype The type of the data in the linked list.
    * @tparam PtrType The type of pointer used to manage node ownership (default is raw pointer).
    * @note This class implements a singly linked list with basic operations such as push, pop, remove, and search.
    * @note Nodes are linked using raw pointers, and the list does not support shared ownership of nodes.
    * @note The list does not support concurrent access, so it is not thread-safe.
    * @note The list does not support memory management, so it is the user's responsibility to manage the memory of the nodes.
 */
template <typename Ttype, template<typename> class PtrType = dataStructures::raw_ptr>
class CSinglyLinkedList {
public:
    using data_t = Ttype;
    using node_t = typename CLinkedNode<data_t, PtrType>::node_t;
    using node_ptr_t = typename node_t::node_ptr_t;
    using size_t = std::size_t;

    /**
     * @brief Default Constructor
     */
    CSinglyLinkedList(); 

    /**
     * @brief Copy Constructor
     * @param other The other list to copy from
     */
    CSinglyLinkedList(const CSinglyLinkedList& other);

    /**
     * @brief Default destructor
     */
    ~CSinglyLinkedList();

    /**
     * @brief Assignment operator
     * @param other The other list to assign from
     * @return Reference to this list
     */
    CSinglyLinkedList& operator=(const CSinglyLinkedList& other);

    /**
     * @brief Equality operator
     * @param other The other list to compare with
     * @return true if both lists are equal, false otherwise
     * @note Two lists are considered equal if they have the same elements in the same order
     */
    bool operator==(const CSinglyLinkedList& other) const;

    /**
     * @brief Inequality operator
     * @param other The other list to compare with
     * @return true if both lists are not equal, false otherwise
     */
    bool operator!=(const CSinglyLinkedList& other) const;

    /**
     * @brief Adds a new element to the front of the list
     * @param value The value to add
     */
    void pushFront(const data_t& value);

    /**
     * @brief Adds a new element to the back of the list
     * @param value The value to add
     */
    void pushBack(const data_t& value);

    /**
     * @brief Removes and returns the first element
     * @return The value of the removed element
     */
    data_t popFront();

    /**
     * @brief Removes and returns the last element
     * @return The value of the removed element
     */
    data_t popBack();

    /**
     * @brief Removes the first occurrence of value in the list
     * @param value The value to remove
     * @return true if value was found and removed, false otherwise
     */
    bool remove(const data_t& value);

    /**
     * @brief Returns the element at the specified position
     * @param position The index of the element to return
     * @return Reference to the element at position
     */
    const data_t& at(size_t position) const;

    /**
     * @brief Checks if a value exists in the list
     * @param value The value to search for
     * @return true if value is found, false otherwise
     */
    bool contains(const data_t& value) const;

    /**
     * @brief Returns the number of elements in the list
     * @return Number of elements
     */
    size_t size() const;

    /**
     * @brief Checks if the list is empty
     * @return true if empty, false otherwise
     */
    bool empty() const;

    /**
     * @brief Reverses the order of elements in the list
     */
    void reverse();

    /**
     * @brief Removes all elements from the list
     */
    void clear();

    /**
     * @brief Inserts a new element at the specified position
     * @param position The index at which to insert the new element
     * @param value The value to insert
     */
    void insert(size_t position, const data_t& value);

protected:
    node_ptr_t head{}; ///< Pointer to the first node in the list
    node_ptr_t tail{}; ///< Pointer to the last node in the list
    size_t count{}; ///< Number of elements in the list

}; //class CSinglyLinkedList

} //namespace dataStructures

#include "dataStructures/singlyLinkedList.inl"

#endif // SINGLEY_LINKED_LIST_INCLUDED_
