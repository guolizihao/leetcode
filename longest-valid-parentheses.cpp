// https://leetcode.com/problems/longest-valid-parentheses/

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() == 0) return 0;
        stack<int> stk;
        int start = 0, res = 0;
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
                    //i - stk.top() = i - (stk.top() + 1) + 1 
                    // stk.top() + 1 表示当前匹配连续字符串最开始的位置
                }
            }
        }
        return res;
    }
};
