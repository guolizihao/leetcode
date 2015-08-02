class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int> &s) {
        if (s.size() == 0) return res;
        sort(s.begin(), s.end());
        vector<int> temp;
        dfs(s, temp, s.size(), 0);
        return res;
    }
    
    void dfs(vector<int> &s, vector<int> &temp, int n, int depth) {
        res.push_back(temp);
        for (int i = depth; i < n; i++) {
            temp.push_back(s[i]);
            dfs(s, temp, n, i + 1);
            temp.pop_back();
        }
    }
};

// class Solution {
// public:
//     vector<vector<int>> result;
//     vector<vector<int>> subsets(vector<int>& nums) {
//         if (nums.size() == 0) return result;
//         sort(nums.begin(),nums.end());
//         vector<int> temp;
//         BuildTree(nums, temp, 0);
//         return result;
//     }
    
//     void BuildTree(vector<int> &nums, vector<int> temp, int level) {
//         if (level == nums.size()) {
//             result.push_back(temp);
//             return;
//         } else {
//             BuildTree(nums, temp, level + 1);
//             temp.push_back(nums[level]);
//             BuildTree(nums, temp, level + 1);
//         }
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> result;
//         if (nums.size() == 0) return result;
//         int max = 1 << nums.size();
//         sort(nums.begin(),nums.end());
//         for (int i = 0; i < max; i++) {
//             vector<int> temp;
//             int j = i;
//             int idx = 0;
//             while (j >0) {
//                 if (j & 1) {
//                     temp.push_back(nums[idx]);
//                 }
//                 idx++;
//                 j >>= 1;
//             }
//             result.push_back(temp);
//         }
//         return result;
//     }
// };
