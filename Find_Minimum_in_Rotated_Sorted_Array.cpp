class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int mid;
        while (low < high && nums[low] > nums[high]) { //在无重复元素时，中间元素与首元素相等，表示一共只有两个元素，low与high各指向一个。
            mid = (high + low) / 2;
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return nums[low];
    }
};
