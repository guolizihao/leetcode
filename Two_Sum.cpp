class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if (nums.size() == 0) return res;
        unordered_map<int,int> table;
        for (int i = 0; i < nums.size(); i++) {
            if (table.find(target - nums[i]) == table.end()) {
                table[nums[i]] = i; 
            } else {
                res[0] = table[target- nums[i]] + 1;
                res[1] = i + 1;
                break;
            }
        }
        return res;
    }
};
