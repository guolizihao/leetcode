//https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return GetMaxSubarray(nums, 0, nums.size() - 1);
    }
    
    int GetMaxSubarray(vector<int> &nums, int left, int right) {
        if (left >= right) return nums[left];
        int mid = (left + right ) / 2;
        int left_max = GetMaxSubarray(nums, left, mid - 1);
        int right_max = GetMaxSubarray(nums, mid + 1, right);
        int middle_max = nums[mid], tmp = nums[mid];
        for (int i = mid - 1; i >= left; --i) {
            tmp += nums[i];
            middle_max = max(middle_max, tmp);
        }
        tmp = middle_max;
        for (int i = mid + 1; i <= right; ++i) {
            tmp += nums[i];
            middle_max = max(middle_max, tmp);
        }
        return max(middle_max, max(left_max, right_max));
    }
};

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int tmp = nums[0], res = nums[0];
//         for (int i = 1; i < nums.size(); i++) {
//             tmp = max(tmp + nums[i], nums[i]);
//             res = max(res, tmp);
//         }
//         return res;
//     }
// };
