class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.size() == 0) return res;
        sort(candidates.begin(), candidates.end());
        vector<int> solution;
        Comb(candidates, 0, 0, target, solution);
        return res;
    }
    void Comb(vector<int> &candidates, int start, int sum, int target, vector<int> &solution) {
        if (sum > target) return;
        if (sum == target) {
            res.push_back(solution);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            solution.push_back(candidates[i]);
            Comb(candidates, i + 1, sum + candidates[i], target, solution);
            solution.pop_back();
        }
    }
};
