#include <gtest/gtest.h>
#include "chapter3/sort_stack.hpp"
#include <algorithm>

class SortStackTest : public ::testing::Test {
    protected:
        void SetUp() override {
            stack = new CSortStack(100);
        }
        void TearDown() override {
            delete stack;
        }
        CSortStack* stack;
};

TEST_F(SortStackTest, TestPushAndPop) {
    stack->push(3);
    stack->push(1);
    stack->push(2);
    EXPECT_EQ(stack->pop(), 1);
    EXPECT_EQ(stack->pop(), 2);
    EXPECT_EQ(stack->pop(), 3);
}

TEST_F(SortStackTest, TestPushAndPopFull) {
    for (int i = 0; i < 100; i++) {
        stack->push(i);
    }
    for (int i = 0; i < 100; i++) {
        EXPECT_EQ(stack->pop(), i);
    }
}

TEST_F(SortStackTest, TestPushAndPopRandom) {
    int randomValues[100] = {0};
    for (int i = 0; i < 100; i++) {
        randomValues[i] = rand() % 100;
    }
    for (int i = 0; i < 100; i++) {
        stack->push(randomValues[i]);
    }
    // sort the random values using the sort function
    std::sort(randomValues, randomValues + 100);
    // pop the values from the stack and compare them with the sorted values
    for (int i = 0; i < 100; i++) {
        EXPECT_EQ(stack->pop(), randomValues[i]);
    }
}