#include <gtest/gtest.h>
#include "chapter1/palindromic_permutation.hpp"

class PalindromicPermutationTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Any setup code would go here
    }
};

TEST_F(PalindromicPermutationTest, BasicCases) {
    // Test case from the book: "tact coa" can be permuted to "taco cat"
    EXPECT_TRUE(isPalindromicPermutation_usingHashTable("tact coa"));
    
    // Simple palindrome permutations
    EXPECT_TRUE(isPalindromicPermutation_usingHashTable("racecar"));
    EXPECT_TRUE(isPalindromicPermutation_usingHashTable("carrace"));
}

TEST_F(PalindromicPermutationTest, EmptyAndSingleChar) {
    // Empty string is considered a palindrome
    EXPECT_TRUE(isPalindromicPermutation_usingHashTable(""));
    
    // Single character is always a palindrome
    EXPECT_TRUE(isPalindromicPermutation_usingHashTable("a"));
}

TEST_F(PalindromicPermutationTest, NonPalindromes) {
    // Strings that cannot form palindromes
    EXPECT_FALSE(isPalindromicPermutation_usingHashTable("hello"));
    EXPECT_FALSE(isPalindromicPermutation_usingHashTable("world"));
    EXPECT_FALSE(isPalindromicPermutation_usingHashTable("openai"));
}

TEST_F(PalindromicPermutationTest, CaseSensitive) {
    // Test case sensitivity
    EXPECT_FALSE(isPalindromicPermutation_usingHashTable("Tact Coa"));
    EXPECT_FALSE(isPalindromicPermutation_usingHashTable("TactCoa"));
}

TEST_F(PalindromicPermutationTest, SpecialCharacters) {
    // Test with special characters and spaces
    EXPECT_TRUE(isPalindromicPermutation_usingHashTable("!eye!"));
    EXPECT_TRUE(isPalindromicPermutation_usingHashTable("! eye !"));
    EXPECT_TRUE(isPalindromicPermutation_usingHashTable("$$##@@"));
}

TEST_F(PalindromicPermutationTest, AllSameCharacters) {
    // Strings with all same characters
    EXPECT_TRUE(isPalindromicPermutation_usingHashTable("aaa"));
    EXPECT_TRUE(isPalindromicPermutation_usingHashTable("aaaa"));
    EXPECT_TRUE(isPalindromicPermutation_usingHashTable("     "));
}

TEST_F(PalindromicPermutationTest, MixedCharacters) {
    // Mix of different types of characters
    EXPECT_TRUE(isPalindromicPermutation_usingHashTable("12321"));
    EXPECT_TRUE(isPalindromicPermutation_usingHashTable("a1b2b1a"));
    EXPECT_FALSE(isPalindromicPermutation_usingHashTable("a1b2c3"));
}

TEST_F(PalindromicPermutationTest, LongStrings) {
    // Test with longer strings
    EXPECT_FALSE(isPalindromicPermutation_usingHashTable("aaaaabbbbbcccccddddd"));
    EXPECT_TRUE(isPalindromicPermutation_usingHashTable("abcdefggfedcba"));
    EXPECT_FALSE(isPalindromicPermutation_usingHashTable("abcdefghijklmnop"));
}

TEST_F(PalindromicPermutationTest, WhitespaceHandling) {
    // Test how whitespace is handled
    EXPECT_TRUE(isPalindromicPermutation_usingHashTable("never odd or even"));
    EXPECT_TRUE(isPalindromicPermutation_usingHashTable("   "));  // All spaces
    EXPECT_TRUE(isPalindromicPermutation_usingHashTable(" a  a "));  // Spaces with characters
}

// Optional: Performance test for large strings
TEST_F(PalindromicPermutationTest, PerformanceTest) {
    std::string longString(10000, 'a');  // Create a string of 10000 'a's
    EXPECT_TRUE(isPalindromicPermutation_usingHashTable(longString));
    
    // Create a string that's almost a palindrome but not quite
    std::string almostPalindrome(10000, 'a');
    almostPalindrome[100] = 'b';
    almostPalindrome[9900] = 'c';
    EXPECT_FALSE(isPalindromicPermutation_usingHashTable(almostPalindrome));
} 