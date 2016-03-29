%https://leetcode.com/problems/power-of-three/

class Solution {
public:
    bool isPowerOfThree(int n) {
        double log_res = log10(n) / log10(3);
        return (log_res - int(log_res) == 0) ? true : false;
    }
};
