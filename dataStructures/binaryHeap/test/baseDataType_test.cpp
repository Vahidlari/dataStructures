#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "dataStructures/baseDataType.hpp"

class BaseDataTypeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code that will be called before each test
    }

    void TearDown() override {
        // Cleanup code that will be called after each test
    }
};

TEST_F(BaseDataTypeTest, SwapShouldExchangeElementsInVector) {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    // Swap elements at indices 1 and 3
    dataStructures::CBaseDataType<std::vector<int>>::swap(numbers, 1, 3);
    
    // Check that elements were swapped
    EXPECT_EQ(numbers[1], 4);
    EXPECT_EQ(numbers[3], 2);
    
    // Check that other elements remained unchanged
    EXPECT_EQ(numbers[0], 1);
    EXPECT_EQ(numbers[2], 3);
    EXPECT_EQ(numbers[4], 5);
}

TEST_F(BaseDataTypeTest, SwapShouldWorkWithDifferentTypes) {
    std::vector<std::string> words = {"apple", "banana", "cherry"};
    
    // Swap elements at indices 0 and 2
    dataStructures::CBaseDataType<std::vector<std::string>>::swap(words, 0, 2);
    
    // Check that elements were swapped
    EXPECT_EQ(words[0], "cherry");
    EXPECT_EQ(words[2], "apple");
    
    // Check that middle element remained unchanged
    EXPECT_EQ(words[1], "banana");
}

TEST_F(BaseDataTypeTest, SwapShouldHandleSameIndex) {
    std::vector<int> numbers = {1, 2, 3};
    
    // Swap element with itself
    dataStructures::CBaseDataType<std::vector<int>>::swap(numbers, 1, 1);
    
    // Check that nothing changed
    EXPECT_EQ(numbers[0], 1);
    EXPECT_EQ(numbers[1], 2);
    EXPECT_EQ(numbers[2], 3);
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcomment"
/*
 * Note: We don't test print() directly as it's output-only functionality
 * In a real-world scenario, we might want to:
 * 1. Redirect stdout to capture the output
 * 2. Use a mock stream
 * 3. Or refactor print() to return a string instead of printing directly
 */
#pragma GCC diagnostic pop 