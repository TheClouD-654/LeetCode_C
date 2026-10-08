int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* result = malloc(2 * sizeof(int));
    *returnSize = 2;
    result[0] = result[1] = -1;
    int left = 0, right = numsSize;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) left = mid + 1;
        else right = mid;
        }
        if (left == numsSize || nums[left] != target) return result;
        result[0] = left;
        right = numsSize;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) left = mid + 1;
            else right = mid;
        }
        result[1] = left - 1;
        return result;
}