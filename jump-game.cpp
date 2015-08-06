// https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0) return true;
        int n = nums.size();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; ++i) {
            dp[i] = max(dp[i - 1], nums[i - 1]) - 1;
            if (dp[i] < 0) return false;
        }
        return true;
    }
};
