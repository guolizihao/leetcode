// https://leetcode.com/problems/maximal-rectangle/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() < 1) return 0;
        vector<int> height;
        int res = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            height.resize(matrix[i].size());
            for (int j = 0; j < matrix[i].size(); ++j) {
                height[j] = matrix[i][j] == '0' ? 0 : 1 + height[j];
            }
            res = max(res, largestRectangleArea(height));
        }
        return res;
    }
    
    int largestRectangleArea(vector<int>& height) {
        height.push_back(0);
        stack<int> s;
        int res = 0, i = 0;
        while (i < height.size()) {
            if (s.empty() ||(height[i] > height[s.top()])) {
                s.push(i);
                ++i;
            } else {
                int idx = s.top(); s.pop();
                res = max(res, height[idx] * (s.empty() ? i : i - 1 - s.top()));
            }
        }
        return res;
    }
};
