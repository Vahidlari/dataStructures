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