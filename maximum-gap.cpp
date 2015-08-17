// https://leetcode.com/problems/maximum-gap/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int n = nums.size();
        int min_n = nums[0];
        int max_n = nums[0];
        for (int i = 1; i < n; ++i) {
            min_n = min(min_n, nums[i]);
            max_n = max(max_n, nums[i]);
        }
        int len = (max_n - min_n) / n + 1; // why + 1
        int bucket_num = (max_n - min_n) / len + 1; // why + 1
        vector<int> bucket_min(bucket_num, INT_MAX);
        vector<int> bucket_max(bucket_num, INT_MIN);
        for (int i = 0; i < n; ++i) {
            int idx = (nums[i] - min_n) / len;
            bucket_min[idx] = min(bucket_min[idx], nums[i]);
            bucket_max[idx] = max(bucket_max[idx], nums[i]);
        }
        int pre = 0, res = 0;
        for (int i = 1; i < bucket_num; ++i) {
            if (bucket_min[i] == INT_MAX || bucket_max[i] == INT_MIN) continue;
            res = max(res, bucket_min[i] - bucket_max[pre]);
            pre = i;
        }
        return res;
    }
};
