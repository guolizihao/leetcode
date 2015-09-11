// https://leetcode.com/problems/3sum-closest/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res, diff = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < target) {
                    if (target - sum < diff) {
                        diff = target - sum;
                        res = sum;
                    }
                    ++left;
                } else if (sum > target) {
                    if (sum - target < diff) {
                        diff = sum - target;
                        res = sum;
                    }
                    --right;
                } else {
                    return sum;
                }
            }
        }
        return res;
    }
};
