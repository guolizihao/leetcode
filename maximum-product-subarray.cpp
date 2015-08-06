//https://leetcode.com/problems/maximum-product-subarray/

// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         if (nums.size() == 0) return 0;
//         int cur_max = nums[0], cur_min = nums[0], max_res = nums[0];
//         for (int i = 1; i < nums.size(); i++) {
//             int old_max = cur_max, old_min = cur_min;
//             cur_max = max(nums[i], max(nums[i] * old_max, nums[i] * old_min));
//             cur_min = min(nums[i], min(nums[i] * old_max, nums[i] * old_min));
//             max_res = max(max_res, cur_max);
//         }
//         return max_res;
//     }
// };

class Solution {
public:
    int maxProduct (vector<int>& A) {
        int n = A.size();
        if (n == 0) return 0;
        
        int max_val = 1, min_val = 1;
        int out = A[0];
        for (int i = 0; i < n; ++i) {
            int old_max_val = max(max_val, 1);
            if (A[i] > 0) {
                max_val = old_max_val * A[i];
                min_val *= A[i];
            } else {
                max_val = min_val * A[i];
                min_val = old_max_val * A[i];
            }
            out = max(out, max_val);
        }
        return out;
    }
};
