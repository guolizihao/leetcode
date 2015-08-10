// https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    void reverseWords(string &s) {
        if (s.empty()) return;
        int i = 0, j = 0, k = 0, word_count = 0;
        while (true) {
            while (i < s.size() && s[i] == ' ') ++i;
            if (i == s.size()) break;
            if (word_count != 0) s[j++] = ' ';
            k = j;
            while (i < s.size() && s[i] != ' ') {
                s[j++] = s[i++];
            }
            ReverseWord(s, k, j - 1);
            ++word_count;
        }
        s.resize(j);
        ReverseWord(s, 0, j - 1);
    }
    void ReverseWord(string &s, int i, int j) {
        while (i < j) {
            char tmp = s[i];
            s[i++] = s[j];
            s[j--] = tmp;
        }
    }
};
