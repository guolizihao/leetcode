class Solution {
public:
    vector<vector<int>> res;
    vector<int> solution;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> visited(nums.size(), 0);
        Comb(nums, 0, visited);
        return res;
    }
    void Comb(vector<int> &nums, int level, vector<int> &visited) {
        if (level == nums.size()) {
            res.push_back(solution);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
                solution.push_back(nums[i]);
                Comb(nums, level + 1, visited);
                solution.pop_back();
                visited[i] = 0;
            }
        }
    }
};


// class Solution {
// public:
//     vector<vector<int>> res;
//     vector<vector<int>> permute(vector<int>& nums) {
//         Comb(nums, 0);
//         return res;
//     }
//     void Comb(vector<int> &nums, int start) {
//         if (start == nums.size()) {
//             res.push_back(nums);
//             return;
//         }
//         for (int i = start; i < nums.size(); i++) {
//             swap(nums[start], nums[i]);
//             Comb(nums, start + 1);
//             swap(nums[start], nums[i]);
//         }
//     }
// };
