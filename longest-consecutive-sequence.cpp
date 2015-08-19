// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> table;
        for (int i = 0; i < nums.size(); ++i) {
            table[nums[i]] = 1;
        }
        for (int i = 0; i < nums.size(); ++i) {
            int d = nums[i];
            int len = 1;
            table.erase(d);
            while(table.find(++d) != table.end()) {
                ++len;
                table.erase(d);
            }
            d = nums[i];
            while(table.find(--d) != table.end()) {
                ++len;
                table.erase(d);
            }
            res = max(res,len);
        }
        return res;
    }
};
