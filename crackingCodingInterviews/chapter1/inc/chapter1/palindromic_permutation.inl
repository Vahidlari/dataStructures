// Implementation of template functions for palindromic_permutation.hpp

template <PalindromicPermutationMethod method>
bool isPalindromicPermutation(std::string s) {
    if constexpr (method == PalindromicPermutationMethod::HashTable) {
        return isPalindromicPermutation_usingHashTable(s);
    } else {
        return isPalindromicPermutation_usingBitManipulation(s);
    }
}
