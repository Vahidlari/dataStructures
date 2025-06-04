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
    EXPECT_TRUE(isPalindromicPermutation<PalindromicPermutationMethod::HashTable>("tact coa"));
    
    // Simple palindrome permutations
    EXPECT_TRUE(isPalindromicPermutation<PalindromicPermutationMethod::BitManipulation>("racecar"));
    EXPECT_TRUE(isPalindromicPermutation<PalindromicPermutationMethod::HashTable>("carrace"));
}

TEST_F(PalindromicPermutationTest, EmptyAndSingleChar) {
    // Empty string is considered a palindrome
    EXPECT_TRUE(isPalindromicPermutation<PalindromicPermutationMethod::BitManipulation>(""));
    
    // Single character is always a palindrome
    EXPECT_TRUE(isPalindromicPermutation<PalindromicPermutationMethod::HashTable>("a"));
}

TEST_F(PalindromicPermutationTest, NonPalindromes) {
    // Strings that cannot form palindromes
    EXPECT_FALSE(isPalindromicPermutation<PalindromicPermutationMethod::HashTable>("hello"));
    EXPECT_FALSE(isPalindromicPermutation<PalindromicPermutationMethod::HashTable>("world"));
    EXPECT_FALSE(isPalindromicPermutation<PalindromicPermutationMethod::HashTable>("openai"));
}

TEST_F(PalindromicPermutationTest, CaseSensitive) {
    // Test case sensitivity
    EXPECT_FALSE(isPalindromicPermutation<PalindromicPermutationMethod::HashTable>("Tact Coa"));
    EXPECT_FALSE(isPalindromicPermutation<PalindromicPermutationMethod::HashTable>("TactCoa"));
}

TEST_F(PalindromicPermutationTest, SpecialCharacters) {
    // Test with special characters and spaces
    EXPECT_TRUE(isPalindromicPermutation<PalindromicPermutationMethod::HashTable>("!eye!"));
    EXPECT_TRUE(isPalindromicPermutation<PalindromicPermutationMethod::HashTable>("! eye !"));
    EXPECT_TRUE(isPalindromicPermutation<PalindromicPermutationMethod::HashTable>("$$##@@"));
}

TEST_F(PalindromicPermutationTest, AllSameCharacters) {
    // Strings with all same characters
    EXPECT_TRUE(isPalindromicPermutation<PalindromicPermutationMethod::HashTable>("aaa"));
    EXPECT_TRUE(isPalindromicPermutation<PalindromicPermutationMethod::HashTable>("aaaa"));
    EXPECT_TRUE(isPalindromicPermutation<PalindromicPermutationMethod::HashTable>("     "));
}

TEST_F(PalindromicPermutationTest, MixedCharacters) {
    // Mix of different types of characters
    EXPECT_TRUE(isPalindromicPermutation<PalindromicPermutationMethod::HashTable>("12321"));
    EXPECT_TRUE(isPalindromicPermutation<PalindromicPermutationMethod::HashTable>("a1b2b1a"));
    EXPECT_FALSE(isPalindromicPermutation<PalindromicPermutationMethod::HashTable>("a1b2c3"));
}

TEST_F(PalindromicPermutationTest, LongStrings) {
    // Test with longer strings
    EXPECT_FALSE(isPalindromicPermutation<PalindromicPermutationMethod::BitManipulation>("aaaaabbbbbcccccddddd"));
    EXPECT_TRUE(isPalindromicPermutation<PalindromicPermutationMethod::HashTable>("abcdefggfedcba"));
    EXPECT_FALSE(isPalindromicPermutation<PalindromicPermutationMethod::BitManipulation>("abcdefghijklmnop"));
}

TEST_F(PalindromicPermutationTest, WhitespaceHandling) {
    // Test how whitespace is handled
    EXPECT_TRUE(isPalindromicPermutation<PalindromicPermutationMethod::HashTable>("never odd or even"));
    EXPECT_TRUE(isPalindromicPermutation<PalindromicPermutationMethod::HashTable>("   "));  // All spaces
    EXPECT_TRUE(isPalindromicPermutation<PalindromicPermutationMethod::BitManipulation>(" a  a "));  // Spaces with characters
}

// Optional: Performance test for large strings
TEST_F(PalindromicPermutationTest, PerformanceTest) {
    std::string longString(10000, 'a');  // Create a string of 10000 'a's
    EXPECT_TRUE(isPalindromicPermutation<PalindromicPermutationMethod::BitManipulation>(longString));
    
    // Create a string that's almost a palindrome but not quite
    std::string almostPalindrome(10000, 'a');
    almostPalindrome[100] = 'b';
    almostPalindrome[9900] = 'c';
    EXPECT_FALSE(isPalindromicPermutation<PalindromicPermutationMethod::HashTable>(almostPalindrome));
} 