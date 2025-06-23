#include <gtest/gtest.h>
#include "chapter2/sum_lists.hpp"

class SumListsTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Any setup code would go here
    }
};

TEST_F(SumListsTest, FromIntegerForwardCreatesCorrectList) {
    CSummableLists list = CSummableLists::fromIntegerForward(617);
    EXPECT_EQ(list.forwardToInteger(), 617);
    CSummableLists zeroList = CSummableLists::fromIntegerForward(0);
    EXPECT_EQ(zeroList.forwardToInteger(), 0);
}

TEST_F(SumListsTest, FromIntegerReverseCreatesCorrectList) {
    CSummableLists list = CSummableLists::fromIntegerReverse(295);
    EXPECT_EQ(list.reverseToInteger(), 295);
    CSummableLists zeroList = CSummableLists::fromIntegerReverse(0);
    EXPECT_EQ(zeroList.reverseToInteger(), 0);
}

TEST_F(SumListsTest, ForwardToIntegerReturnsCorrectValue) {
    CSummableLists list = CSummableLists::fromIntegerForward(1234);
    EXPECT_EQ(list.forwardToInteger(), 1234);
}

TEST_F(SumListsTest, ReverseToIntegerReturnsCorrectValue) {
    CSummableLists list = CSummableLists::fromIntegerReverse(4321);
    EXPECT_EQ(list.reverseToInteger(), 4321);
}

TEST_F(SumListsTest, ForwardTraverseSumOfProduct) {
    CSummableLists list1 = CSummableLists::fromIntegerForward(123);
    CSummableLists list2 = CSummableLists::fromIntegerForward(456);
    CSummableLists result = CSummableLists::add<ESumListsMethod::FORWARD_TRAVERSE_SUM_OF_PRODUCT>(list1, list2);
    EXPECT_EQ(result.forwardToInteger(), 579); // 123 + 456 = 579
}

TEST_F(SumListsTest, ForwardTraverseSumOfProductWithZero) {
    CSummableLists list1 = CSummableLists::fromIntegerForward(0);
    CSummableLists list2 = CSummableLists::fromIntegerForward(456);
    CSummableLists result = CSummableLists::add<ESumListsMethod::FORWARD_TRAVERSE_SUM_OF_PRODUCT>(list1, list2);
    EXPECT_EQ(result.forwardToInteger(), 456); // 0 + 456 = 456
}

TEST_F(SumListsTest, ForwardTraverseSumOfProductsWithDIfferentLengths) {
    CSummableLists list1 = CSummableLists::fromIntegerForward(123);
    CSummableLists list2 = CSummableLists::fromIntegerForward(45);
    CSummableLists result = CSummableLists::add<ESumListsMethod::FORWARD_TRAVERSE_SUM_OF_PRODUCT>(list1, list2);
    EXPECT_EQ(result.forwardToInteger(), 168); // 123 + 45 = 168
}

TEST_F(SumListsTest, ForwardTraverseSumOfDigits) {
    CSummableLists list1 = CSummableLists::fromIntegerForward(584);
    CSummableLists list2 = CSummableLists::fromIntegerForward(295);
    CSummableLists result = CSummableLists::add<ESumListsMethod::FORWARD_TRAVERSE_SUM_OF_DIGITS>(list1, list2);
    EXPECT_EQ(result.forwardToInteger(), 879); // 584 + 295 = 879
}

TEST_F(SumListsTest, ForwardTraverseSumOfDigitsWithCarry) {
    CSummableLists list1 = CSummableLists::fromIntegerForward(7); // 7
    CSummableLists list2 = CSummableLists::fromIntegerForward(5); // 5
    CSummableLists result = CSummableLists::add<ESumListsMethod::FORWARD_TRAVERSE_SUM_OF_DIGITS>(list1, list2);
    EXPECT_EQ(result.forwardToInteger(), 12); // 7 + 5 = 12, so we expect the last digit (2)
}

TEST_F(SumListsTest, ForwardTraverseSumOfDigitsWithEmptyList) {
    CSummableLists list1; // Empty list
    CSummableLists list2 = CSummableLists::fromIntegerForward(123); // 123
    CSummableLists result = CSummableLists::add<ESumListsMethod::FORWARD_TRAVERSE_SUM_OF_DIGITS>(list1, list2);
    EXPECT_EQ(result.forwardToInteger(), 123); // 0 + 123 = 123
}

TEST_F(SumListsTest, ReverseTraverseSumOfDigits) {
    CSummableLists list1 = CSummableLists::fromIntegerReverse(345);
    CSummableLists list2 = CSummableLists::fromIntegerReverse(654);
    CSummableLists result = CSummableLists::add<ESumListsMethod::REVERSE_TRAVERSE_SUM_OF_DIGITS>(list1, list2);
    EXPECT_EQ(result.reverseToInteger(), 999); // 345 + 654 = 999
}

TEST_F(SumListsTest, ReverseTraverseSumOfDigitsWithCarry) {
    CSummableLists list1 = CSummableLists::fromIntegerReverse(456);
    CSummableLists list2 = CSummableLists::fromIntegerReverse(789);
    CSummableLists result = CSummableLists::add<ESumListsMethod::REVERSE_TRAVERSE_SUM_OF_DIGITS>(list1, list2);
    EXPECT_EQ(result.reverseToInteger(), 1245); // 456 + 789 = 1245
}

TEST_F(SumListsTest, ReverseTraverseSumOfDigitsWithDifferentLengths) {
    CSummableLists list1 = CSummableLists::fromIntegerReverse(7234); // 7234
    CSummableLists list2 = CSummableLists::fromIntegerReverse(57); // 57
    CSummableLists result = CSummableLists::add<ESumListsMethod::REVERSE_TRAVERSE_SUM_OF_DIGITS>(list1, list2);
    EXPECT_EQ(result.reverseToInteger(), 7291); // 7234 + 57 = 7291
}

TEST_F(SumListsTest, ReverseTraverseSumOfDigitsWithEmptyList) {
    CSummableLists list1; // Empty list
    CSummableLists list2 = CSummableLists::fromIntegerReverse(123); // 123
    CSummableLists result = CSummableLists::add<ESumListsMethod::REVERSE_TRAVERSE_SUM_OF_DIGITS>(list1, list2);
    EXPECT_EQ(result.reverseToInteger(), 123); // 0 + 123 = 123
}
