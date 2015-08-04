//https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int p = n, val = 1;
        for (int i  = 0; i < n / 2; i++, p -=2) {
            for (int col = i; col <= i + p - 1; ++col) {
                res[i][col] = val++;
            }
            for (int row = i + 1; row <= i + p -1; ++row) {
                res[row][i + p - 1] = val++;
            }
            for (int col = i + p - 2; col >= i; --col) {
                res[i + p -1][col] = val++;
            }
            for (int row = i + p - 2; row >= i + 1; --row) {
                res[row][i] = val++;
            }
        }
        if (n % 2 != 0) res[n / 2][n / 2] =val;
        return res;
    }
};
