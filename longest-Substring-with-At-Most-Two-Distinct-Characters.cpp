//159	Longest Substring with At Most Two Distinct Characters

//159 Given a string S, find the length of the longest substring T that contains at most two distinct characters.
//For example,
//Given S = “eceba”,
//T is “ece” which its length is 3.

class Solution 
{  
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.size() <= 2) return s.size();
        int begin = 0, end = 0, dif_char_num = 0, max_len = 0;
        int table[128] = {0};
        while (end < s.size()) {
            table[s[end]]++;
            if (table[s[end]] == 1) dif_char_num++;
            while (diff_char_num > 2) {
                table[s[begin]]--;
                if (table[s[begin]] == 0) diff_char_num--;
                begin++;
            }
            if (end - begin + 1 > max_len) {
                max_len = end - begin + 1;
            }
            end++;
        }
        return max_len;
    }
}；


class Solution 
{  
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.size() <= 2) return s.size();
	int begin = 0, end = 0, diff_char_num = 0, max_len = 0;
	int table[128] = {0};
	while (end < s.size()) {
		++table[s[end]];
		if (table[s[end]] == 1) ++diff_char_num;
		while (diff_char_num > 2) {
			--table[s[begin]];
			if (table[s[begin]] == 0) --diff_char_num;
			++begin;
		}
		max_len = max(max_len, end - begin + 1);
		++end;
	}
	return max_len;
    }
}；
