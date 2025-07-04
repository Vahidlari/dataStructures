#include <gtest/gtest.h>
#include "chapter3/stack_of_plates.hpp"

class StackOfPlatesTest : public ::testing::Test {
protected:
    void SetUp() override {
        stack = new CStackOfPlates(100);
    }
    void TearDown() override {
        delete stack;
    }
    CStackOfPlates* stack;
};

TEST_F(StackOfPlatesTest, TestPushAndPop) {
    stack->push(1);
    stack->push(2);
    stack->push(3);
    EXPECT_EQ(stack->pop(), 3);
    EXPECT_EQ(stack->pop(), 2);
    EXPECT_EQ(stack->pop(), 1);
}

TEST_F(StackOfPlatesTest, TestPushAndPopCrossingStack) {
    for (int i = 0; i < 90; i++) {
        stack->push(i);
    }
    EXPECT_EQ(stack->pop(), 89);
    EXPECT_EQ(stack->pop(), 88);
    EXPECT_EQ(stack->pop(), 87);
}