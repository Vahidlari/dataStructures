#include <gtest/gtest.h>
#include "chapter2/remove_linked_list_duplicates.hpp"

class RemoveLinkedListDuplicatesTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Any setup code would go here
    }
};

TEST_F(RemoveLinkedListDuplicatesTest, RemoveDuplicatesUsingHash) {
    CLinkedListDuplicatesRemover<int, ERemovalMethod::HASH> myList;
    myList.pushBack(1);
    myList.pushBack(2);
    myList.pushBack(3);
    myList.pushBack(2);
    myList.pushBack(4);
    myList.pushBack(3);
    myList.removeDuplicates();
    EXPECT_EQ(myList.size(), 4);
}

TEST_F(RemoveLinkedListDuplicatesTest, RemoveDuplicatesInPlace) {
    CLinkedListDuplicatesRemover<int, ERemovalMethod::IN_PLACE> myList;
    myList.pushBack(1);
    myList.pushBack(2);
    myList.pushBack(3);
    myList.pushBack(2);
    myList.pushBack(4);
    myList.pushBack(3);
    myList.removeDuplicates();
    EXPECT_EQ(myList.size(), 4);
}

TEST_F(RemoveLinkedListDuplicatesTest, NoDuplicatesInPlace) {
    CLinkedListDuplicatesRemover<int, ERemovalMethod::IN_PLACE> myList;
    myList.pushBack(1);
    myList.pushBack(2);
    myList.pushBack(3);
    myList.removeDuplicates();
    EXPECT_EQ(myList.size(), 3);
}

TEST_F(RemoveLinkedListDuplicatesTest, noDuplicatesUsingHash) {
    CLinkedListDuplicatesRemover<int, ERemovalMethod::HASH> myList;
    myList.pushBack(1);
    myList.pushBack(2);
    myList.pushBack(3);
    myList.removeDuplicates();
    EXPECT_EQ(myList.size(), 3);
}
