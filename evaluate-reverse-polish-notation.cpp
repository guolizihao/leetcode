// https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int result = 0;
        stack<int> stk;
        for (int i = 0; i < (int)tokens.size(); i++) {
            const char *p = tokens[i].c_str();
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                //这里使用isdigit(*p)不行，当tokens[i]为-1时候，*p = -；
                stk.push(atoi(p));
            } else {
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                result = 0;
                switch (*p) {
                    case '+': result = num1 + num2; break;
                    case '-': result = num1 - num2; break;
                    case '*': result = num1 * num2; break;
                    case '/': result = num1 / num2; break;
                }
                stk.push(result);
            }
        }
        return stk.top();
    }
};
