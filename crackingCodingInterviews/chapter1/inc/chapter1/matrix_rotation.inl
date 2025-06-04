template<std::size_t SIZE>
MatrixType<SIZE> matrixRotation_return_matrix(const MatrixType<SIZE>& inputMatrix) {
    MatrixType<SIZE> rotatedMatrix;
    // Rotate the matrix by 90 degrees
    // The new element at (i, j) in the rotated matrix comes from (SIZE - 1 - j, i) in the input matrix

    for (std::size_t i = 0; i < SIZE; i++) {
        for (std::size_t j = 0; j < SIZE; j++) {
            // Assign the rotated position
            rotatedMatrix[j][SIZE - 1 - i] = inputMatrix[i][j];
        }
    }
    return rotatedMatrix;
}


template<std::size_t SIZE>
void matrixRotation_inplace_circular(MatrixType<SIZE>& inputMatrix){
	if constexpr (SIZE <= 1)
	    return;
	auto swap = inputMatrix[0][0]; // Use auto to match the matrix element type
    // Rotate the matrix in place by swapping elements in layers
    // We will swap elements in a circular manner for each layer
    for (std::size_t i = 0; i < SIZE / 2; i++) {
        for (std::size_t j = i; j < SIZE - 1 - i; j++) {
            swap = inputMatrix[i][j];
            inputMatrix[i][j] = inputMatrix[SIZE - 1 - j][i];
            inputMatrix[SIZE - 1 - j][i] = inputMatrix[SIZE - 1 - i][SIZE - 1 - j];
            inputMatrix[SIZE - 1 - i][SIZE - 1 - j] = inputMatrix[j][SIZE - 1 - i];
            inputMatrix[j][SIZE - 1 - i] = swap;
        }
    }
}

template<std::size_t SIZE>
void matrixRotation_inplace_transpose(MatrixType<SIZE>& matrix) {
    // Transpose
    for (std::size_t i = 0; i < SIZE; ++i) {
        for (std::size_t j = i + 1; j < SIZE; ++j) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
    // Reverse each row
    for (std::size_t i = 0; i < SIZE; ++i) {
        std::reverse(matrix[i].begin(), matrix[i].end());
    }
}

template<MatrixRotationMethod method, typename MatrixType>
auto matrixRotation(MatrixType& inputMatrix) {
    if constexpr (method == MatrixRotationMethod::ReturnMatrix) {
        return matrixRotation_return_matrix(inputMatrix);
    } else if constexpr (method == MatrixRotationMethod::InPlaceCircular) {
        matrixRotation_inplace_circular(inputMatrix);
        return inputMatrix;
    } else if constexpr (method == MatrixRotationMethod::InPlaceTranspose) {
        matrixRotation_inplace_transpose(inputMatrix);
        return inputMatrix;
    }
}
