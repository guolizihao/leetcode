// https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for (auto num: nums) {
            res ^= num;
        }
        for (int i = 0; i < nums.size() + 1; ++i) {
            res ^= i;
        }
        return res;
    }
};

// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int sum = 0;
//         for (int i = 0; i < nums.size(); ++i) {
//             sum += nums[i];
//         }
//         int len = nums.size();
//         return (1 + len) * len / 2 - sum;
//     }
// };
