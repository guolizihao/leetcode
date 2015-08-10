//https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int table[26] = {0};
        for (int i = 0; i < s.size(); ++i) {
            ++table[s[i] - 'a'];
        }
        for (int i = 0; i < s.size(); ++i) {
            if (--table[t[i] - 'a'] < 0) return false;
        }
        return true;
    }
};
