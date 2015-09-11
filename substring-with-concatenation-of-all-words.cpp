// https://leetcode.com/problems/substring-with-concatenation-of-all-words/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;
        unordered_map<string, int> m1;
        int word_num = words.size();
        for (int i = 0; i < word_num; ++i) ++m1[words[i]];
        int word_len = words[0].size();
        for (int i = 0; i <= (int)s.size() - word_num * word_len; ++i) {
            unordered_map<string, int> m2;
            int j;
            for (j = 0; j < word_num; ++j) {
                string str = s.substr(i + j * word_len, word_len);
                if (m1.find(str) == m1.end()) break;
                ++m2[str];
                if (m2[str] > m1[str]) break;
            }
            if (j == word_num) res.push_back(i);
        }
        return res;
    }
};
