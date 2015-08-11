// https://leetcode.com/problems/maximal-square/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> table(m, vector<int>(n, 0));
        int max_len = table[0][0];
        for (int i = 0; i < m; ++i) {
            table[i][0] = matrix[i][0] - '0';
            max_len = max(max_len, table[i][0]);
        }
        for (int i = 0; i < n; ++i) {
            table[0][i] = matrix[0][i] - '0';
            max_len = max(max_len, table[0][i]);
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    table[i][j] = min(table[i - 1][j], min(table[i][j - 1], table[i - 1][j - 1])) + 1;
                    max_len = max(max_len, table[i][j]);
                } else {
                    table[i][j] = 0;
                }
            }
        }
        return max_len * max_len;
    }
};

// class Solution {
// public:
//     int maximalSquare(vector<vector<char>>& matrix) {
//         if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
//         int res = 0;
//         for (int i = 0; i < matrix.size(); ++i) {
//             vector<int> height(matrix[i].size(),0);
//             for (int j = i; j < matrix.size(); ++j) {
//                 for (int k = 0; k < matrix[j].size(); ++k) {
//                     if (matrix[j][k] == '1') ++height[k];
//                 }
//                 res = max(res, CalculateArea(height, j - i + 1));
//             }
//         }
//         return res;
//     }
//     int CalculateArea(vector<int> height, int k) {
//         int counter = 0;
//         for (int i = 0; i < height.size(); ++i) {
//             if (height[i] != k) counter = 0;
//             else counter++;
//             if (counter == k) return k * k;
//         }
//         return 0;
//     }
// };
