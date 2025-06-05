#include <gtest/gtest.h>
#include "chapter1/string_compression.hpp"

class StringCompressionTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Any setup code would go here
    }
};

TEST_F(StringCompressionTest, BasicCases) {
    // Test basic compression
    EXPECT_EQ(compressString("aabcccccaaa"), "a2b1c5a3");
    EXPECT_EQ(compressString("abc"), "abc");  // No compression
}
TEST_F(StringCompressionTest, EmptyAndSingleChar) {
    // Test empty string
    EXPECT_EQ(compressString(""), "");
    
    // Test single character
    EXPECT_EQ(compressString("a"), "a");
}
