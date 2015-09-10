// https://leetcode.com/problems/fraction-to-recurring-decimal/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string res;
        if (denominator == 0) return res;
        // if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) res = '-';
        if (numerator < 0 ^ denominator < 0) res = '-';
        long long n = numerator, d = denominator;
        n = abs(n);
        d = abs(d);
        res += to_string(n / d);
        long long r = n % d;
        if (r == 0) return res;
        res += '.';
        unordered_map<long long, int> m;
        while (r) {
            if (m.find(r) != m.end()) {
                res.insert(res.begin() + m[r], '(');
                res += ')';
                break;
            }
            m[r] = res.size();
            r *= 10;
            res += to_string(r / d);
            r %= d;
        }
        return res;
    }
};
