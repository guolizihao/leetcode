// https://leetcode.com/problems/house-robber/

int rob(int* nums, int numsSize) {
  if (numsSize == 0) return 0;
  if (nums == NULL) return 0;
  int *maxa = malloc (sizeof(int)* numsSize);
  memset(maxa, 0, sizeof(int) * numsSize);
  int i;
  maxa[0] = nums[0];
  maxa[1] = max(nums[0], nums[1]);
  for (i = 2; i < numsSize; i++) {
    maxa[i] = max(maxa[i-1], maxa[i-2] + nums[i]);
  }
  return maxa[numsSize-1];
}

int max(int a, int b) {
  return a > b? a: b;
}
