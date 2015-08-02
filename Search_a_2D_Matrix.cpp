class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0, high = matrix.size() - 1;
        int mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (target == matrix[mid][0]) {
                return true;
            } else if (target < matrix[mid][0]) {
                high = mid - 1;
            } else {
                if (mid == matrix.size() - 1||target < matrix[mid + 1][0]) {
                    break;
                }
                low =  mid + 1;
            }
        }
        int level = mid;
        int left = 0, right = matrix[level].size() - 1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (target == matrix[level][mid]) {
                return true;
            } else if (target < matrix[level][mid]) {
                right = mid -1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
};
