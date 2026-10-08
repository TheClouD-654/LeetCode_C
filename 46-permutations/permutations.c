static void generate(int* nums, int n, int* used, int* path, int depth, int** out, int* cols, int* count) {
    if (depth == n) {
        out[*count] = malloc(n * sizeof(int));
        memcpy(out[*count], path, n * sizeof(int));
        cols[(*count)++] = n;
        return;
        }
        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            used[i] = 1;
            path[depth] = nums[i];
            generate(nums, n, used, path, depth + 1, out, cols, count);
            used[i] = 0;
        }
        }
        int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
            int capacity = 1;
            for (int i = 2; i <= numsSize; i++) capacity *= i;
            int** out = malloc(capacity * sizeof(int*));
            *returnColumnSizes = malloc(capacity * sizeof(int));
            *returnSize = 0;
            int used[6] = {0}, path[6];
            generate(nums, numsSize, used, path, 0, out, *returnColumnSizes, returnSize);
            return out;
            }