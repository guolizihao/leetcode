// https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                if (left > i + 1 && nums[left] == nums[left - 1]) {
                    ++left;
                    continue;
                }
                if (right < nums.size() - 1 && nums[right] == nums[right + 1]) {
                    --right;
                    continue;
                }
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[left]);
                    v.push_back(nums[right]);
                    res.push_back(v);
                    ++left;
                    --right;
                } else if (sum < 0) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return res;
    }
};
