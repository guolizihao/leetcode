class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x = 0, y = matrix[0].size() - 1;
        while (x < matrix.size() && y >=0) {
            int elem = matrix[x][y];
            if (target == elem) return true;
            else if (target > elem) ++x;
            else --y;
        }
        return false;
    }
};
