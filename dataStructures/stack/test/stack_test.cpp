#include <gtest/gtest.h>
#include <dataStructures/flexibleMultiStack.hpp>

class FlexibleMultiStackTest : public ::testing::Test {
protected:
    void SetUp() override {
        stack = new dataStructures::CFlexibleMultiStack<int>(100);
    }
    void TearDown() override {
        delete stack;
    }

    dataStructures::CFlexibleMultiStack<int>* stack;
};

TEST_F(FlexibleMultiStackTest, TestStackCreationWithDefaultCapacity) {
    stack->createStack(0);
    EXPECT_EQ(stack->getStackSize(0), 0);
    EXPECT_EQ(stack->getStackCapacity(0), 10);
    
}

TEST_F(FlexibleMultiStackTest, TestStackCreationWithCapacity) {
    stack->createStack(1, 50);
    EXPECT_EQ(stack->getStackSize(1), 0);
    EXPECT_EQ(stack->getStackCapacity(1), 50);
}

TEST_F(FlexibleMultiStackTest, TestStackCreationWithInvalidCapacity) {
    EXPECT_EQ(stack->createStack(0, 0), dataStructures::CFlexibleMultiStack<int>::EStackCreationResult::INVALID_CAPACITY);
}

TEST_F(FlexibleMultiStackTest, TestStackCreationWithInvalidStackID) {
    stack->createStack(0);
    EXPECT_EQ(stack->createStack(0, 10), dataStructures::CFlexibleMultiStack<int>::EStackCreationResult::INVALID_STACK_ID);
}

TEST_F(FlexibleMultiStackTest, TestStackCreationWithOverflow) {
    stack->createStack(0, 100);
    EXPECT_EQ(stack->createStack(1, 100), dataStructures::CFlexibleMultiStack<int>::EStackCreationResult::OVERFLOW);
}

TEST_F(FlexibleMultiStackTest, TestPushAndPop) {
    stack->createStack(0, 10);
    stack->push(0, 1);
    EXPECT_EQ(stack->getStackSize(0), 1);
    EXPECT_EQ(stack->peek(0), 1);
    auto poppedValue = stack->pop(0);
    EXPECT_EQ(poppedValue, 1);
    EXPECT_EQ(stack->getStackSize(0), 0);
}

TEST_F(FlexibleMultiStackTest, TestMultiplePushesAndPops) {
    stack->createStack(0, 10);
    stack->push(0, 1);
    stack->push(0, 2);
    stack->push(0, 3);
    EXPECT_EQ(stack->getStackSize(0), 3);
    EXPECT_EQ(stack->peek(0), 3);
    EXPECT_EQ(stack->pop(0), 3);
    EXPECT_EQ(stack->getStackSize(0), 2);
    EXPECT_EQ(stack->peek(0), 2);
    EXPECT_EQ(stack->pop(0), 2);
    EXPECT_EQ(stack->getStackSize(0), 1);
    EXPECT_EQ(stack->peek(0), 1);
    EXPECT_EQ(stack->pop(0), 1);
    EXPECT_EQ(stack->getStackSize(0), 0);
}
