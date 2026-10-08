static int cmp(const void* x, const void* y) {
    return (*(const int*)x > *(const int*)y) - (*(const int*)x < *(const int*)y);
}
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
        if (i > start && a[i] == a[i - 1]) continue;
        if (a[i] > left) break;
        path[depth] = a[i];
        build(a, n, i + 1, left - a[i], path, depth + 1, out, cols, count, capacity);
        }
}
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    int capacity = 16;
    int** out = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));
    *returnSize = 0;
    int* path = malloc((target + 1) * sizeof(int));
    build(candidates, candidatesSize, 0, target, path, 0, &out, returnColumnSizes, returnSize, &capacity);
    free(path);
    return out;
    }