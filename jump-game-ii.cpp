// https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int i = 0, res = 0, cur = 0;
        while (cur < n - 1) {
            int pre = cur;
            while (pre >= i) {
                cur = max(cur, i + nums[i]);
                i++;
            }
            res++;
        }
        return res;
    }
};
