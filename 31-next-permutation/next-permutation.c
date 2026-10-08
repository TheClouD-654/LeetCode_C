void nextPermutation(int* nums, int numsSize) {
    int pivot = numsSize - 2;
    while (pivot >= 0 && nums[pivot] >= nums[pivot + 1]) {
        pivot--;
    }
    if (pivot >= 0) {
        int next = numsSize - 1;
        while (nums[next] <= nums[pivot]) {
            next--;
        }
        int temp = nums[pivot];
        nums[pivot] = nums[next];
        nums[next] = temp;
    }
    int left = pivot + 1;
    int right = numsSize - 1;
    while (left < right) {
        int temp = nums[left];
        nums[left++] = nums[right];
        nums[right--] = temp;
    }
}