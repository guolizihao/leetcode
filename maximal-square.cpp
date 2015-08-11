// https://leetcode.com/problems/maximal-square/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int res = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            vector<int> height(matrix[i].size(),0);
            for (int j = i; j < matrix.size(); ++j) {
                for (int k = 0; k < matrix[j].size(); ++k) {
                    if (matrix[j][k] == '1') ++height[k];
                }
                res = max(res, CalculateArea(height, j - i + 1));
            }
        }
        return res;
    }
    int CalculateArea(vector<int> height, int k) {
        int counter = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (height[i] != k) counter = 0;
            else counter++;
            if (counter == k) return k * k;
        }
        return 0;
    }
};
