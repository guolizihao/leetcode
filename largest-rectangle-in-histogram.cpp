// https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
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
