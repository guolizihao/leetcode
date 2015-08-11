// https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        unordered_map<string, int> m;
        queue<string> q;
        m[beginWord] = 1;
        q.push(beginWord);
        while (!q.empty()) {
            string word = q.front(); 
            q.pop();
            for (int i = 0; i < (int) word.size(); ++i) {
                string new_word = word;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    new_word[i] = ch;
                    if (new_word == endWord) return m[word] + 1;
                    if (wordDict.find(new_word) != wordDict.end() && m.find(new_word) == m.end()) {
                        q.push(new_word);
                        m[new_word] = m[word] + 1;
                    }
                }
            }
        }
        return 0;
    }
};
