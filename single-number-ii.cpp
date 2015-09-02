// https://leetcode.com/problems/single-number-ii/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0, three = 0;
        for (int i = 0; i < nums.size(); ++i) {
            three = two & nums[i];
            two |= one & nums[i];
            one |= nums[i];
            
            two &= ~three;
            one &= ~three;
        }
        return one;
    }
};

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int res = 0;
//         int count[32] = {0};
//         for (int i = 0; i < 32; ++i) {
//             for (int j = 0; j < nums.size(); ++j) {
//                 count[i] += (nums[j] >> i) & 1;
//             }
//             res |= (count[i] % 3) << i;
//         }
//         return res;
//     }
// }; 
