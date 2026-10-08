static void build(int* a, int n, int start, int left, int* path, int depth, int*** out, int** cols, int* count, int* capacity) {
    if (left == 0) {
        if (*count == *capacity) {
            *capacity *= 2;
            *out = realloc(*out, *capacity * sizeof(int*));
            *cols = realloc(*cols, *capacity * sizeof(int));
            }
            (*out)[*count] = malloc(depth * sizeof(int));
            memcpy((*out)[*count], path, depth * sizeof(int));
            (*cols)[(*count)++] = depth;
            return;
            }
            for (int i = start; i < n; i++) {
                if (a[i] > left) continue;
                path[depth] = a[i];
                build(a, n, i, left - a[i], path, depth + 1, out, cols, count, capacity);
            }
}
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int capacity = 16;
    int** out = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));
    *returnSize = 0;
    int* path = malloc((target + 1) * sizeof(int));
    build(candidates, candidatesSize, 0, target, path, 0, &out, returnColumnSizes, returnSize, &capacity);
    free(path);
    return out;
}