// https://leetcode.com/problems/shortest-palindrome/

class Solution {
public:
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        string t = s + "#" + r;
        vector<int> prefix(t.size(), 0);
        for (int i = 1; i < t.size(); ++i) {
            int j = prefix[i - 1]; //j (0,1,...,j-1) letters in prefix is matched by string 0,1,...,i-1
            // test if i-th letter matches j-th letter in the prefix
            while (j > 0 && t[i] != t[j]) {
                j = prefix[j - 1];  // the prefix[j - 1] is definitely matched
            }
            if (t[i] == t[j]) {
                ++j;
            }
            prefix[i] = j;
        }
        return r.substr(0, s.size() - prefix[t.size() - 1]) + s;
    }
};

// int GetNext(char *p, int next[]) {
//     int len_p = strlen(p);
//     next[0] = -1;
//     int k = -1;
//     int j = 0;
//     while (j < len_p - 1) {
//         if (k == -1 || p[j] == p[k]) {
//             ++j;
//             ++k;
//             next[j] = k;
//         } else {
//             k = next[k];
//         }
//     }
// }

// int KmpSearch(char *s, char *p) {
//     int len_s = strlen(s);
//     int len_p = strlen(p);
//     int i = 0, j = 0;
//     while (i < len_s && j < len_p) {
//         if (j == -1 || s[i] == p[j]) {
//             ++j;
//             ++i;
//         } else {
//             j = next[j];
//         }
//     }
//     if (j == len_p) {
//         return i - j;
//     } else {
//         retur -1;
//     }
// }
