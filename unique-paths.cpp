// https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);  //第0行每个位置的走法都为1
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};

// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         double dom = 1;
//         double dedom = 1;
//         int small = m<n? m-1:n-1;
//         int big = m<n? n-1:m-1;
//         for(int i=1;i<=small;i++) {
//             dedom *= i;
//             dom *= small+big+1-i;
//         }
//         return (int)(dom/dedom);
//     }
// };
