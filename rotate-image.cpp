//https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        if (len == 0 || matrix[0].size() == 0) return; 
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
