// https://leetcode.com/problems/wildcard-matching/

class Solution {
public:
    bool isMatch(string s, string p) {
        int s_idx = 0, p_idx = 0, s_star_idx = INT_MIN, p_star_idx = INT_MIN;
        while (s_idx < s.size()) {
            if (s[s_idx] == p[p_idx] || p[p_idx] == '?') {
                s_idx++;
                p_idx++;
            } else if (p[p_idx] == '*') {
                p_star_idx = p_idx++;
                s_star_idx = s_idx;
            } else if (p_star_idx != INT_MIN) {
                p_idx = p_star_idx + 1;
                s_idx = ++s_star_idx;
            } else return false;
        }
        while (p[p_idx] == '*') ++p_idx;
        return p_idx == p.size();
    }
};


// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         int m = s.size(), n = p.size();
//         vector<bool> dp(m + 1, false);
//         dp[0] = true;
//         for (int j = 0; j < n; ++j) {
//             if (p[j] != '*') {
//                 for (int i = m - 1; i >= 0 ; --i) {
//                     dp[i + 1] = dp[i] && (p[j] == s[i] || p[j] == '?');
//                 }
//             } else {
//                 int i = 0;
//                 while (i <= m && !dp[i]) ++i;
//                 while (i <= m) dp[i++] = true;
//             }
//           dp[0] = dp[0] && p[j] == '*';  
//         }
//         return dp[m];
//     }
// };
