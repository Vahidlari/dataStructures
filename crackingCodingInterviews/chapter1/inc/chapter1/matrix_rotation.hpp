#ifndef MATRIX_ROTATION_HPP
#define MATRIX_ROTATION_HPP

#include <array>


template<std::size_t SIZE>
using MatrixType = std::array<std::array<int, SIZE>, SIZE>;

/**
    * @file matrix_rotation.hpp
    * @brief Solution for Cracking the Coding Interview 1.7: Rotate Matrix
    *
    * @problem
    * Given an NxN matrix, write a method to rotate the matrix by 90 degrees.
    * Can you do this in place?
    *
    * @example
    * Input: 
    * 1 2 3
    * 4 5 6
    * 7 8 9
    *
    * Output:
    * 7 4 1
    * 8 5 2
    * 9 6 3
    *
    * @approach
    * We can rotate the matrix in layers, swapping elements in a circular manner.
    *
    * @complexity
    * Time: O(N^2) where N is the size of one dimension of the matrix
    * Space: O(N^2) for the output matrix
 */
template<std::size_t SIZE>
MatrixType<SIZE> matrixRotation_return_matrix(const MatrixType<SIZE>& inputMatrix);

template<std::size_t SIZE>
void matrixRotation_inplace_circular(MatrixType<SIZE>& inputMatrix);

template<std::size_t SIZE>
void matrixRotation_inplace_transpose(MatrixType<SIZE>& matrix);

// Enum to specify the method of matrix rotation
enum class MatrixRotationMethod {
    ReturnMatrix,
    InPlaceCircular,
    InPlaceTranspose
};

/*
    * @brief Helper function to rotate a matrix by 90 degrees
    *
    * @param inputMatrix The input matrix to rotate
    * @return The rotated matrix
    * @tparam MatrixType The type of the input matrix, which should be a std::array of std::array
    * @note The input matrix must be square (NxN)
    * @example
    * Input:
    * MatrixType<3> input = {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
    * Output:
    * MatrixType<3> expected = {{{7, 4, 1}, {8, 5, 2}, {9, 6, 3}}};
    *
    * @complexity
    * Time: O(N^2) where N is the size of one dimension of the matrix
*/

template<MatrixRotationMethod method, typename MatrixType>
auto matrixRotation(MatrixType& inputMatrix);

#include "chapter1/matrix_rotation.inl"

#endif // MATRIX_ROTATION_HPP