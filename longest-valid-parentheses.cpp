// https://leetcode.com/problems/longest-valid-parentheses/

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() == 0) return 0;
        stack<int> stk;
        int start = 0, res = 0;
        // start 表示当前不符合要求的'('开始的位置
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            }
            else if (s[i] == ')') {
                if (stk.empty()) {
                    start = i + 1;
                } else {
                    stk.pop();
                    res = stk.empty() ? max(res, i - start + 1) : max(res, i - stk.top()); 
                    // i - stk.top() = i - (stk.top() + 1) + 1 
                    // stk.top() 还在stack中，说明它不符合要求
                    // 那么stk.top() + 1 表示当前符合要求的连续字符串开始的位置
                }
            }
        }
        return res;
    }
};
