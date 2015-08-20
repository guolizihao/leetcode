// https://leetcode.com/problems/palindrome-partitioning-ii/

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        vector<vector<bool>> p(n, vector<bool>(n, false));
        for (int i = 0; i <= n; ++i) {
            dp[i] = n - i - 1; //按照字符串中的每个字母都单独被划分来计算。
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1])) {
                    p[i][j] = true;
                    dp[i] = min(dp[i], dp[j + 1] + 1);
                }
            }
        }
        return dp[0];
    }
};
