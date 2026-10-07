#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** rows = malloc(numRows * sizeof(int*));
    *returnColumnSizes = malloc(numRows * sizeof(int));
    *returnSize = numRows;
    for (int r = 0; r < numRows; ++r) {
        (*returnColumnSizes)[r] = r + 1;
        rows[r] = malloc((r + 1) * sizeof(int));
        rows[r][0] = rows[r][r] = 1;
        for (int c = 1; c < r; ++c) {
            rows[r][c] = rows[r - 1][c - 1] + rows[r - 1][c];
        }
    }
    return rows;
}
