class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
             return INT_MAX;
        long long a = abs((double)dividend);
        long long b = abs((double)divisor);
        long long result = 0;
        while (a >= b) {
            long long count = 1;
            long long temp = b;
            while (temp < a) {
                temp <<= 1;
                count <<= 1;
            }
            if (temp != b) {
                temp >>= 1;
                count >>= 1;
            }
            result += count;
            a -= temp;
        }
        return (int)(dividend < 0 ^ divisor < 0 ? -result: result); 
        // return ((dividend ^ divisor) >> 31) ? (-res) : (res);
    }
};
