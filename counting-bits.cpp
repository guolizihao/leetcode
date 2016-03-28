https://leetcode.com/problems/counting-bits/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        for (int i = 1; i < num + 1; ++i) {
            res[i] = res[i >> 1] + i % 2;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(1,0);
        int cnt = 0;
        while (cnt < num) {
            int sz = res.size();
            for (int i = 0; i < sz && cnt < num; ++cnt, ++i) {
                res.push_back(res[i] + 1);
            }
        }
        return res;
    }
};
