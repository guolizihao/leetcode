class Solution {
public:
    vector<vector<int>> res;
    vector<int> solution;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
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
                if (i > 0  && nums[i] == nums[i - 1] && visited[i - 1] == 0) continue; 
                //visited[i - 1] == 0 表示i-1已经放过了
                visited[i] = 1;
                solution.push_back(nums[i]);
                Comb(nums, level + 1, visited);
                solution.pop_back();
                visited[i] = 0;
            }
        }
    }
};
