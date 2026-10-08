void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    for (int r = 0; r < matrixSize; r++) {
        for (int c = r + 1; c < matrixSize; c++) {
            int temp = matrix[r][c];
            matrix[r][c] = matrix[c][r];
            matrix[c][r] = temp;
            }
            }
            for (int r = 0; r < matrixSize; r++) {
            for (int l = 0, h = matrixSize - 1; l < h; l++, h--) {
                int temp = matrix[r][l];
                matrix[r][l] = matrix[r][h];
                matrix[r][h] = temp;
            }
    }
}
