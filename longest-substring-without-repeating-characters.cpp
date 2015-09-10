// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int map[256] = {0}, left = 0, res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (map[s[i]] == 0 || map[s[i]] < left) {
                res = max(res, i - left + 1);
            } else {
                left = map[s[i]];
            }
            map[s[i]] = i + 1;
        }
        return res;
    }
    
//class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int locs[256];
//         memset(locs, -1, sizeof(locs));
//         int idx = -1, max = 0; //idx为当前子串的开始位置-1
//         for (int i = 0; i < s.size(); i++) {
//             if (locs[s[i]] > idx) {//如果当前字符出现过，那么当前子串的起始位置为这个字符上一次出现的位置+1
//                 idx = locs[s[i]];
//             }
//             if (i - idx > max) { // i-(idx+1)+1 = i - idx
//                 max = i - idx;
//             }
//             locs[s[i]] = i;
//         }
//         return max;
//     }
// };
