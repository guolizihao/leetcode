class Solution {
public:
    // 镜面排列 
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        for(int i = 0; i < n; i++) {
            int highbit = 1 << i;
            int len = res.size();
            for (int j = len - 1; j >=0; --j) {
                res.push_back(highbit + res[j]);
            }
        }
        return res;
    }
};

// class Solution {
// public:
//     vector<int> grayCode(int n) {
//         vector<int> res;
//         int end = pow(2,n);
//         for (int i = 0; i < end; i++) {
//             res.push_back((i >> 1) ^ i);
//         }
//         return res;
//     }
// };
