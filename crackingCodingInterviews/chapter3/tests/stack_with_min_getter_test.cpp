#include <gtest/gtest.h>
#include "chapter3/stack_with_min_getter.hpp"

class StackMinTest : public ::testing::Test {
protected:
    void SetUp() override {
        stack = new CStackWithMinGetter(100); // Create a stack with overall capacity of 100
    }
    void TearDown() override {
        delete stack;
    }
    CStackWithMinGetter* stack;
};

TEST_F(StackMinTest, TestPushAndGetMin) {
    stack->createStack(0);
    stack->push(0, 5);
    EXPECT_EQ(stack->getMin(), 5);
    
    stack->push(0, 3);
    EXPECT_EQ(stack->getMin(), 3);
    
    stack->push(0, 7);
    EXPECT_EQ(stack->getMin(), 3);
    
    stack->push(0, 2);
    EXPECT_EQ(stack->getMin(), 2);
}

TEST_F(StackMinTest, TestPopAndGetMin) {
    stack->createStack(0);
    stack->push(0, 5);
    stack->push(0, 3);
    stack->push(0, 7);
    stack->push(0, 2);
    stack->push(0, 4);
    stack->push(0, 1);

    EXPECT_EQ(stack->getMin(), 1);
    stack->pop(0);
    EXPECT_EQ(stack->getMin(), 2);
    stack->pop(0);
    EXPECT_EQ(stack->getMin(), 2);
    stack->pop(0);
    EXPECT_EQ(stack->getMin(), 3);
    stack->pop(0);
    EXPECT_EQ(stack->getMin(), 3);
    stack->pop(0);
    EXPECT_EQ(stack->getMin(), 5);
}

TEST_F(StackMinTest, TestGetMinOnEmptyStack) {
    stack->createStack(0);
    EXPECT_THROW(stack->getMin(), std::out_of_range);
}


