class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int mid;
        while (low < high && nums[low] >= nums[high]) {
            mid = (low + high) / 2;
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else if (nums[mid] < nums[high]) {
                high = mid;
            } else {
                low++;
            }
        }
        return nums[low];
    }
};
