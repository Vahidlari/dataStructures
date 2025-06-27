#include <gtest/gtest.h>
#include <dataStructures/flexibleMultiStack.hpp>

class FlexibleMultiStackTest : public ::testing::Test {
protected:
    void SetUp() override {
        stack = new dataStructures::CFlexibleMultiStack<int>(100, 100); // Create a stack with overall capacity of 100 and max 5 stacks
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

TEST_F(FlexibleMultiStackTest, TestPushOnFullStack) {
    stack->createStack(0, 2);
    stack->push(0, 1);
    stack->push(0, 2);
    EXPECT_THROW(stack->push(0, 3), std::out_of_range);
}

TEST_F(FlexibleMultiStackTest, TestPopFromEmptyStack) {
    stack->createStack(0, 10);
    EXPECT_THROW(stack->pop(0), std::out_of_range);
}

TEST_F(FlexibleMultiStackTest, TestPeekAtEmptyStack) {
    stack->createStack(0, 10);
    EXPECT_THROW(stack->peek(0), std::out_of_range);
}

TEST_F(FlexibleMultiStackTest, TestPeekAfterPush) {
    stack->createStack(0, 10);
    stack->push(0, 42);
    EXPECT_EQ(stack->peek(0), 42);
}

TEST_F(FlexibleMultiStackTest, TestIsEmpty) {
    stack->createStack(0, 10);
    EXPECT_TRUE(stack->isEmpty(0));
    stack->push(0, 1);
    EXPECT_FALSE(stack->isEmpty(0));
    stack->pop(0);
    EXPECT_TRUE(stack->isEmpty(0));
}

TEST_F(FlexibleMultiStackTest, TestMultipleStacks) {
    stack->createStack(0, 10);
    stack->createStack(1, 20);
    stack->push(0, 1);
    stack->push(1, 2);
    EXPECT_EQ(stack->getStackSize(0), 1);
    EXPECT_EQ(stack->getStackSize(1), 1);
    EXPECT_EQ(stack->peek(0), 1);
    EXPECT_EQ(stack->peek(1), 2);
    
    auto poppedValue0 = stack->pop(0);
    auto poppedValue1 = stack->pop(1);
    
    EXPECT_EQ(poppedValue0, 1);
    EXPECT_EQ(poppedValue1, 2);
    EXPECT_EQ(stack->getStackSize(0), 0);
    EXPECT_EQ(stack->getStackSize(1), 0);
}

TEST_F(FlexibleMultiStackTest, TestMemoryTetris) {
    // Create multiple stacks with different capacities to fill the memory
    std::vector<size_t> stackIDs = {0, 1, 2, 3, 4};
    std::vector<size_t> capacities = {10, 20, 20, 30, 20};

    for (size_t i = 0; i < stackIDs.size(); ++i) {
        stack->createStack(stackIDs[i], capacities[i]);
        for (size_t j = 0; j < capacities[i]; ++j) {
            stack->push(stackIDs[i], stackIDs[i] * 10 + j + 1);
        }
    }

    // Check if all stacks are full
    for (size_t i = 0; i < stackIDs.size(); ++i) {
        EXPECT_EQ(stack->getStackSize(stackIDs[i]), capacities[i]);
    }


    // Remove one stack in front to trigger memory tetris
    stack->deleteStack(stackIDs[1]);
    stack->deleteStack(stackIDs[3]);

    // Check if the stack count is correct
    EXPECT_EQ(stack->getStackCount(), stackIDs.size() - 2);

    // Check if the remaining stacks are still intact
    for (size_t i = 0; i < stackIDs.size(); ++i) {
        if (i == 1 || i == 3) continue; // Skip the deleted stack
        EXPECT_EQ(stack->getStackSize(stackIDs[i]), capacities[i]);
        // Check if the data is still intact
        for (size_t j = capacities[i]; j > 0; --j) {
            auto poppedValue = stack->pop(stackIDs[i]);
            EXPECT_EQ(poppedValue, stackIDs[i] * 10 + j);
        }
    }
    // Check if the stack is empty after popping all elements
    for (size_t i = 0; i < stackIDs.size(); ++i) {
        if (i == 1 || i == 3) continue; // Skip the deleted stack
        EXPECT_TRUE(stack->isEmpty(stackIDs[i]));
    }
}