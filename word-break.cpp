class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int len = s.size();
        vector<bool> res(len + 1, false);
        res[0] = true;
        for (int i = 1; i <= len; ++i) { 
            //res[i] 表示在从起始位置算长度为i的字符串（即索引为0到i-1）是否在字典里面
            //状态方程为f(i) = 存在j 使得f(j) && s[j+1,i]属于dict 
            for (int j = 0; j < i; ++j) {
                if (res[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    res[i] = true;
                    break;
                }
            }
        }
        return res[len];
    }
};
