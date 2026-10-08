static int cmp(const void* a, const void* b) {
    return (*(const int*)a > *(const int*)b) - (*(const int*)a < *(const int*)b);
    }
    static void generate(int* nums, int n, int* used, int* path, int depth, int** out, int* cols, int* count) {
        if (depth == n) {
            out[*count] = malloc(n * sizeof(int));
            memcpy(out[*count], path, n * sizeof(int));
            cols[(*count)++] = n;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            used[i] = 1;
            path[depth] = nums[i];
            generate(nums, n, used, path, depth + 1, out, cols, count);
            used[i] = 0;
        }
        }
        int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
            qsort(nums, numsSize, sizeof(int), cmp);
            int capacity = 1;
            for (int i = 2; i <= numsSize; i++) capacity *= i;
            int** out = malloc(capacity * sizeof(int*));
            *returnColumnSizes = malloc(capacity * sizeof(int));
            *returnSize = 0;
            int used[8] = {0}, path[8];
            generate(nums, numsSize, used, path, 0, out, *returnColumnSizes, returnSize);
            return out;
            }