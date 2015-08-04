//https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n == 0) return res;
        string solution;
        generateParenthesisDFS(n, n, solution, res);
        return res;
    }
    void generateParenthesisDFS(int left, int right, string solution, vector<string> &res) {
        if (left == 0 && right == 0) {
            res.push_back(solution);
            return;
        }
        if (left > right) return;
        if (left > 0) {
            generateParenthesisDFS(left - 1, right, solution + '(', res);
        }
        if (right > 0) {
             generateParenthesisDFS(left, right - 1, solution + ')', res);
        }
    }
};
