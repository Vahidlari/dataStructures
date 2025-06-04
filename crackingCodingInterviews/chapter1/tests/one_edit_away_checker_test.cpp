#include <gtest/gtest.h>
#include "chapter1/one_edit_away_checker.hpp"

class OneEditAwayCheckerTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Any setup code would go here
    }
};

TEST_F(OneEditAwayCheckerTest, TestOneEditAway) {
    EXPECT_TRUE(isOneEditAway<OneEditAwayMethod::LengthComparison>("pale", "ple"));
    EXPECT_TRUE(isOneEditAway<OneEditAwayMethod::LengthComparison>("pales", "pale"));
    EXPECT_TRUE(isOneEditAway<OneEditAwayMethod::LengthComparison>("pale", "bale"));
    EXPECT_FALSE(isOneEditAway<OneEditAwayMethod::LengthComparison>("pale", "bake"));
}
TEST_F(OneEditAwayCheckerTest, TestZeroEdits) {
    EXPECT_TRUE(isOneEditAway<OneEditAwayMethod::LengthComparison>("pale", "pale"));
    EXPECT_TRUE(isOneEditAway<OneEditAwayMethod::LengthComparison>("", ""));
}
TEST_F(OneEditAwayCheckerTest, TestMultipleEdits) {
    EXPECT_FALSE(isOneEditAway<OneEditAwayMethod::LengthComparison>("pale", "bake"));
    EXPECT_FALSE(isOneEditAway<OneEditAwayMethod::LengthComparison>("pale", "bakes"));
}
TEST_F(OneEditAwayCheckerTest, TestDifferentLengths) {
    EXPECT_TRUE(isOneEditAway<OneEditAwayMethod::LengthComparison>("pale", "pales"));
    EXPECT_FALSE(isOneEditAway<OneEditAwayMethod::LengthComparison>("pale", "pa"));
    EXPECT_FALSE(isOneEditAway<OneEditAwayMethod::LengthComparison>("pale", "paless"));
}
TEST_F(OneEditAwayCheckerTest, TestEmptyStrings) {
    EXPECT_TRUE(isOneEditAway<OneEditAwayMethod::LengthComparison>("", ""));
    EXPECT_TRUE(isOneEditAway<OneEditAwayMethod::LengthComparison>("a", ""));
    EXPECT_TRUE(isOneEditAway<OneEditAwayMethod::LengthComparison>("", "a"));
}
TEST_F(OneEditAwayCheckerTest, TestSingleCharacter) {
    EXPECT_TRUE(isOneEditAway<OneEditAwayMethod::LengthComparison>("a", "a"));
    EXPECT_TRUE(isOneEditAway<OneEditAwayMethod::LengthComparison>("a", "b"));
    EXPECT_TRUE(isOneEditAway<OneEditAwayMethod::LengthComparison>("a", "ab"));
    EXPECT_TRUE(isOneEditAway<OneEditAwayMethod::LengthComparison>("ab", "a"));
}
TEST_F(OneEditAwayCheckerTest, TestSpecialCharacters) {
    EXPECT_FALSE(isOneEditAway<OneEditAwayMethod::LengthComparison>("a!b@c#", "c#b@a!"));
    EXPECT_TRUE(isOneEditAway<OneEditAwayMethod::LengthComparison>("a!b@c#", "a!b@c#"));
    EXPECT_TRUE(isOneEditAway<OneEditAwayMethod::LengthComparison>("a!b@c#", "a!b@c$"));
}
TEST_F(OneEditAwayCheckerTest, TestWhitespace) {
    EXPECT_FALSE(isOneEditAway<OneEditAwayMethod::LengthComparison>("abc ", " abc"));
    EXPECT_TRUE(isOneEditAway<OneEditAwayMethod::LengthComparison>("abc", "abc "));
    EXPECT_FALSE(isOneEditAway<OneEditAwayMethod::LengthComparison>("abc ", "ab c"));
}