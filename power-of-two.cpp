// https://leetcode.com/problems/power-of-two/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // int res = 0;
        // while (n > 0) {
        //     res += n & 1;
        //     n >>= 1;
        // }
        // return res == 1;
        return (n > 0) && (!(n & (n - 1)));
    }
};
