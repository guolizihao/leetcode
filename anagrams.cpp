// https://leetcode.com/problems/anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if (strs.empty()) return res;
        sort(strs.begin(), strs.end());
        unordered_map<string, int> m;
        for (int i = 0; i < strs.size(); ++i) {
            string str = strs[i];
            sort(str.begin(), str.end());
            if (m.find(str) == m.end()) {
                m[str] = res.size();
                vector<string> vs{strs[i]};
                // vs.push_back(strs[i]);
                res.push_back(vs);
            } else{
                res[m[str]].push_back(strs[i]);
            }
        }
        return res;
    }
};
