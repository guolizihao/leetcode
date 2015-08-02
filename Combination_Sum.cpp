class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() == 0) return res;
        sort(candidates.begin(), candidates.end());
        vector<int> solution;
        Comb(candidates, 0, 0, target, solution);
        return res;
    }
    void Comb(vector<int> &candidates, int index, int sum, int target, vector<int> &solution) {
        if (sum > target) return;
        if (sum == target) {
            res.push_back(solution);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            solution.push_back(candidates[i]);
            Comb(candidates, i, sum + candidates[i], target, solution);
            solution.pop_back();
        }
    }
};
