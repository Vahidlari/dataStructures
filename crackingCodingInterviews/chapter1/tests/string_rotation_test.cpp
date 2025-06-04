#include <gtest/gtest.h>
#include "chapter1/string_rotation.hpp"

class StringRotationTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Any setup code would go here
    }
};

TEST_F(StringRotationTest, BasicCases) {
    // Test basic rotation
    EXPECT_TRUE(isStringRotation("waterbottle", "erbottlewat"));
    EXPECT_TRUE(isStringRotation("waterbottle", "bottlewater"));
}

TEST_F(StringRotationTest, EmptyAndSingleChar) {
    // Test empty strings
    EXPECT_FALSE(isStringRotation("", ""));
    
    // Test single character strings
    EXPECT_TRUE(isStringRotation("a", "a"));
    EXPECT_FALSE(isStringRotation("a", "b"));
}

TEST_F(StringRotationTest, DifferentLengths) {
    // Test strings of different lengths
    EXPECT_FALSE(isStringRotation("abc", "ab"));
    EXPECT_FALSE(isStringRotation("abc", "abcd"));
}

TEST_F(StringRotationTest, IdenticalStrings) {
    // Test identical strings
    EXPECT_TRUE(isStringRotation("same", "same"));
}

TEST_F(StringRotationTest, NonRotation) {
    // Test non-rotated strings
    EXPECT_FALSE(isStringRotation("hello", "world"));
    EXPECT_FALSE(isStringRotation("abcde", "cdeabf"));
}