int compareInts(const void* a, const void* b) {
    int x = *(const int*)a, y = *(const int*)b;
    return (x > y) - (x < y);
}

int** threeSum(int* nums, int numsSize, int* returnSize,
               int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compareInts);
    int capacity = 16;
    int** ans = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        if (nums[i] > 0) {
            break;
        }
        int l = i + 1, r = numsSize - 1;
        while (l < r) {
            long long sum = (long long)nums[i] + nums[l] + nums[r];
            if (sum < 0) {
                l++;
            } else if (sum > 0) {
                r--;
            } else {
                if (*returnSize == capacity) {
                    capacity *= 2;
                    ans = realloc(ans, capacity * sizeof(int*));
                    *returnColumnSizes =
                        realloc(*returnColumnSizes, capacity * sizeof(int));
                }
                int k = *returnSize;
                ans[k] = malloc(3 * sizeof(int));
                ans[k][0] = nums[i];
                ans[k][1] = nums[l];
                ans[k][2] = nums[r];
                (*returnColumnSizes)[k] = 3;
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
    return ans;
}
