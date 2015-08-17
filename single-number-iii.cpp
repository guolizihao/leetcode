// https://leetcode.com/problems/single-number-iii/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        int len = nums.size();
        if (len == 0) return res;
        int AxorB = 0;
        for (int i = 0; i < len; ++i) {
            AxorB ^= nums[i];
        }
        int mask = AxorB & (~(AxorB - 1));
        int A = 0, B = 0;
        for (int i = 0; i < len; ++i) {
            if ((mask & nums[i]) == 0) {
                A ^= nums[i];
            } else {
                B ^= nums[i];
            }
        }
        res.push_back(A);
        res.push_back(B);
        return res;
    }
};
