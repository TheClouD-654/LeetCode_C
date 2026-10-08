int compareInts(const void* a, const void* b) {
    int x = *(const int*)a, y = *(const int*)b;
    return (x > y) - (x < y);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize,
              int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compareInts);
    int capacity = 16;
    int** ans = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        for (int j = i + 1; j < numsSize - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }
            int l = j + 1, r = numsSize - 1;
            while (l < r) {
                long long sum =
                    (long long)nums[i] + nums[j] + nums[l] + nums[r];
                if (sum < target) {
                    l++;
                } else if (sum > target) {
                    r--;
                } else {
                    if (*returnSize == capacity) {
                        capacity *= 2;
                        ans = realloc(ans, capacity * sizeof(int*));
                        *returnColumnSizes =
                            realloc(*returnColumnSizes, capacity * sizeof(int));
                    }
                    int k = *returnSize;
                    ans[k] = malloc(4 * sizeof(int));
                    ans[k][0] = nums[i];
                    ans[k][1] = nums[j];
                    ans[k][2] = nums[l];
                    ans[k][3] = nums[r];
                    (*returnColumnSizes)[k] = 4;
                    (*returnSize)++;
                    int left = nums[l], right = nums[r];
                    while (l < r && nums[l] == left) {
                        l++;
                    }
                    while (l < r && nums[r] == right) {
                        r--;
                    }
                }
            }
        }
    }
    return ans;
}