class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size() - 1;
        int start = 0, end = 0;
        int min = INT_MAX;
        int sum = 0;
        while (start <= len && end <= len) {
            while (sum < s && end <= len) {
                sum += nums[end++];
            }
            while (sum >= s && start <= end) {
                min = (min > end - start ? end - start: min);
                sum -= nums[start++];
            }
        }
        return min == INT_MAX ? 0: min;
    }
};
