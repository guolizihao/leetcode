// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        if (nums.empty()) return res;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(target - nums[i]) != m.end()) {
                res.push_back(m[target-nums[i]] + 1);
                res.push_back(i + 1);
            }
            m[nums[i]] = i;
        }
        return res;
    }
};
