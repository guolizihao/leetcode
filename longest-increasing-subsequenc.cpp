%https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        vector<int> len(nums.size(), 1);
        int res = 1;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] < nums[j]) {
                    len[j] = max(len[j], len[i] + 1);
                }
            if (len[j] > res) res = len[j];
            }
        }
        return res;
    }
};


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        vector<int> v;
        v.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            int n = nums[i];
            if (n > v.back()) v.push_back(n);
            else {
                *lower_bound(v.begin(),v.end(),n) = n;
            }
        }
        return v.size();
    }
};
