// Implementation of template functions for permutation_checker.hpp

template <PermutationMethod method>
bool isPermutation(std::string s1, std::string s2) {
    if constexpr (method == PermutationMethod::CharCount) {
        return isPermutation_usingCharCount(s1, s2);
    } else if constexpr (method == PermutationMethod::Sort) {
        return isPermutation_usingSort(s1, s2);
    } else {
        return isPermutation_usingHashTable(s1, s2);
    }
}
