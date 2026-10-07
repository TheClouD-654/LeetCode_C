#include <stdlib.h>

int* getRow(int rowIndex, int* returnSize) {
    int* row = calloc(rowIndex + 1, sizeof(int));
    row[0] = 1;
    for (int r = 1; r <= rowIndex; ++r) {
        for (int c = r; c >= 1; --c) {
            row[c] += row[c - 1];
        }
    }
    *returnSize = rowIndex + 1;
    return row;
}
