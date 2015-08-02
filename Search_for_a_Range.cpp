class Solution {
public:
    vector<int> result;
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() <= 0) return result;
        int left_range = searchLeft(nums, target);
        int right_range = searchRight(nums, target);
        
        result.push_back(left_range);
        result.push_back(right_range);
        return result;
    }
    int searchLeft (vector<int> &nums, int target) {
        int low = 0, high = nums.size() - 1;
        int mid;
        while (low <= high) {
            mid = (low + high) >> 1;
            if (nums[mid] < target) {
                low  = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (nums[low] != target) {
            return -1;
        }
        return low;
    }
    
    int searchRight (vector<int> &nums, int target) {
        int low = 0, high = nums.size() - 1;
        int mid;
        while (low <= high) {
            mid = (low + high) >> 1;
            if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low  = mid + 1;
            }
        }
        if (nums[high] != target) {
            return -1;
        }
        return high;
    }
    
};
