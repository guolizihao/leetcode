// https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() == 0 || s.size() < t.size()) return "";
        int need_find[256] = {0}, has_found[256] = {0};
        for (int i = 0; i < t.size(); i++) {
            need_find[t[i]]++; //skip those not in T
        }
        int begin = 0, end  = 0;
        int min_begin = 0, min_end = s.size() - 1, min_win_len = INT_MAX;
        for (int count = 0; end < s.size(); end++) {
            if (need_find[s[end]] == 0) continue;
            has_found[s[end]]++;
            //update the total number of characters found(aaa only counts 2 for aa in T)  
            if (has_found[s[end]] <= need_find[s[end]]) count++; 
            //a window exists from begin to end  
            if (count == t.size()) {
                //move begin pointer to find the minimum window  
                while (begin < end) {
                    if (need_find[s[begin]] == 0) {
                        begin++;
                        continue;
                    }
                    if (has_found[s[begin]] > need_find[s[begin]]) {
                        has_found[s[begin]]--;
                        begin++;
                        continue;
                    } else {
                        break;
                    }
                }
                int temp_win_len = end - begin + 1;
                if (min_win_len > temp_win_len) {
                    min_win_len = temp_win_len;
                    min_begin = begin;
                    min_end = end;
                }
            }
        }
        return min_win_len == INT_MAX ? "": s.substr(min_begin,min_win_len);
    }
};
