int searchInsert(int* nums, int numsSize, int target) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return (target > nums[0] ? 1:0);
    int low = 0, high = numsSize -1;
    int mid;
    while (low <= high) {
        mid = (high + low) / 2;
        if (target == nums[mid]) {
            return mid;
        } else if (target > nums[mid]) {
            low = mid + 1;
        } else {
            high = mid -1;
        }
    }
    return low;
}
