// https://leetcode.com/problems/basic-calculator-ii/

class Solution {
public:
    int calculate(string s) {
        int d = 0;
        char sign = '+';
        stack<int> stk;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0') {
                d = d * 10 + s[i] - '0';
            }
            if ((s[i] < '0' && s[i] != ' ') || i == s.size() - 1) {
                if (sign == '+') stk.push(d);
                if (sign == '-') stk.push(-d);
                if (sign == '/' || sign == '*') {
                    int tmp = sign == '/' ? stk.top() / d: stk.top() * d;
                    stk.pop();
                    stk.push(tmp);
                }
                d = 0;
                sign = s[i];
            }
        }
        int res = 0;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};
