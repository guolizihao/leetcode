// https://leetcode.com/problems/reverse-bits/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0, power = 1 << 31;
        while(n) {
            res += n % 2 * power;
            n /= 2;
            power /= 2;
        }
        return res;
    }
};
