// https://leetcode.com/problems/house-robber-ii/

int rob(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 0) return 0; 
    if (numsSize == 1) return nums[0];
    return max(rob_line(nums, 0, numsSize - 1), rob_line(nums, 1, numsSize));
}

int rob_line(int* nums, int left, int right) {
//   if (right - left == 0) return nums[left];
  if (nums == NULL) return 0;
  int *maxa = malloc (sizeof(int)* right);
  memset(maxa, 0, sizeof(int) * right);
  int i;
  maxa[left] = nums[left];
  maxa[left + 1] = max(nums[left], nums[left + 1]);
  for (i = left + 2; i < right; i++) {
    maxa[i] = max(maxa[i-1], maxa[i-2] + nums[i]);
  }
  return maxa[right - 1];
}

int max(int a, int b) {
  return a > b? a: b;
}
