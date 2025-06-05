#include <gtest/gtest.h>
#include "chapter1/matrix_rotation.hpp"

class MatrixRotationTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Any setup code would go here
    }
};

TEST_F(MatrixRotationTest, BasicRotation) {
    MatrixType<3> input = {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
    MatrixType<3> expected = {{{7, 4, 1}, {8, 5, 2}, {9, 6, 3}}};
    EXPECT_EQ(matrixRotation<MatrixRotationMethod::ReturnMatrix>(input), expected);
    MatrixType<3> inputInPlace = {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
    matrixRotation<MatrixRotationMethod::InPlaceCircular>(inputInPlace);
    EXPECT_EQ(inputInPlace, expected);
}
TEST_F(MatrixRotationTest, SingleElementMatrix) {
    MatrixType<1> input = {{{1}}};
    MatrixType<1> expected = {{{1}}};
    EXPECT_EQ(matrixRotation<MatrixRotationMethod::ReturnMatrix>(input), expected);
}
TEST_F(MatrixRotationTest, TwoByTwoMatrix) {
    MatrixType<2> input = {{{1, 2}, {3, 4}}};
    MatrixType<2> expected = {{{3, 1}, {4, 2}}};
    EXPECT_EQ(matrixRotation<MatrixRotationMethod::ReturnMatrix>(input), expected);
    MatrixType<2> inputInPlace = {{{1, 2}, {3, 4}}};
    matrixRotation<MatrixRotationMethod::InPlaceTranspose>(inputInPlace);
    EXPECT_EQ(inputInPlace, expected);
}
TEST_F(MatrixRotationTest, FourByFourMatrix) {
    MatrixType<4> input = {{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}}};
    MatrixType<4> expected = {{{13, 9, 5, 1}, {14, 10, 6, 2}, {15, 11, 7, 3}, {16, 12, 8, 4}}};
    EXPECT_EQ(matrixRotation<MatrixRotationMethod::ReturnMatrix>(input), expected);
    MatrixType<4> inputInPlace = {{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}}};
    matrixRotation<MatrixRotationMethod::InPlaceCircular>(inputInPlace);
    EXPECT_EQ(inputInPlace, expected);
}

