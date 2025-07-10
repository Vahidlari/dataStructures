#ifndef BASEDATATYPE_INCLUDED_
#define BASEDATATYPE_INCLUDED_

namespace dataStructures
{
/**
 * @brief Base class providing common operations for container types
 * 
 * This class serves as a base for other data structures, providing common
 * utility functions for container manipulation and display.
 * 
 * @tparam Ttype Container type that supports indexing operator[]
 */
template <typename Ttype>
class CBaseDataType
{
public:
    using index_t = std::size_t;
    /**
     * @brief Swaps two elements in a container
     * 
     * @param[in,out] a Container in which to perform the swap
     * @param[in] srcIdx Source index
     * @param[in] dstIdx Destination index
     * 
     * @note The container must support operator[] for access and modification
     */
    static void swap(Ttype& a, index_t srcIdx, index_t dstIdx);

    /**
     * @brief Prints all elements in the container
     * 
     * @param[in] a Container to print
     * 
     * @note The container must support range-based for loop iteration
     * @note Elements must support operator<< for output stream
     */
    static void print(Ttype a);       
private:
};
} // namespace dataStructures

#include "dataStructures/baseDataType.inl"
#endif //BASEDATATYPE_INCLUDED_