//https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0 ||matrix[0].size() == 0) return res;
        int m = matrix.size(), n = matrix[0].size();
        int c = m > n ? (n + 1) / 2 : (m + 1) / 2;
        int p = m, q = n;
        for (int i = 0; i < c; i++, p -= 2, q -= 2) {
            for (int col = i; col <= i + q - 1; col++) {
                res.push_back(matrix[i][col]);
            }
            for (int row = i + 1; row <= i + p - 1; row++) {
                res.push_back(matrix[row][i + q - 1]);
            }
            if (p == 1 || q == 1) break;
            for (int col = i + q - 2; col >= i; col--) {
                res.push_back(matrix[i + p - 1][col]);
            }
            for (int row = i + p - 2; row >= i + 1; row--) {
                res.push_back(matrix[row][i]);
            }
        }
        return res;
    }
};
