int compareInts(const void* a, const void* b) {
    int x = *(const int*)a, y = *(const int*)b;
    return (x > y) - (x < y);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), compareInts);
    int best = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < numsSize - 2; i++) {
        int l = i + 1, r = numsSize - 1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (abs(sum - target) < abs(best - target)) {
                best = sum;
            }
            if (sum == target) {
                return sum;
            } else if (sum < target) {
                l++;
            } else {
                r--;
            }
        }
    }
    return best;
}
