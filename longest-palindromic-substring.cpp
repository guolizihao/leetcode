//https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        string longest;
        if (s.size() == 0) return longest;
        longest = s.substr(0, 1); // a single char itself is a palindrome  
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i + 1]) {
                string p2 = ExpandFromCenter(s, i, i + 1); //长度为偶数的候选回文字符串 
                if (p2.size() > longest.size()) {
                    longest = p2;
                }
            }
            string p1 = ExpandFromCenter(s, i, i); //长度为奇数的候选回文字符串 
            if (p1.size() > longest.size()) {
                longest = p1;
            }
        }
        return longest;
    }
    string ExpandFromCenter(string s, int left, int right) {
        int len = s.size();
        while (left >= 0 && right <= len - 1 && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - 1 -left);
    }
};
