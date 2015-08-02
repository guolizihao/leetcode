class Solution {
public:
    double myPow(double x, int n) {
        double ans;
        if (n < 0) {
            if (n == INT_MIN) {
                return 1.0 / (myPow(x, INT_MAX) * x); 
            } else {
                return 1.0 / myPow(x, -n);
            }
        }
        if (n == 0) ans = 1.0;
        ans = 1.0;
        for (; n > 0; x *= x, n >>= 1) {
            if (n&1 > 0) {
                ans *= x;
            }
        }
        return ans;
    }
};
