class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> solution;
        Comb(k, n, 1, 0, solution);
        return res;
    }
    void Comb(int k, int target, int start, int sum, vector<int> &solution) {
        if (target == sum && k == 0) {
            res.push_back(solution);
            return;
        }
        if (target < sum || k == 0) return;
        for (int i = start; i <= 9; i++) {
            solution.push_back(i);
            Comb(k - 1, target, i + 1, sum + i, solution);
            solution.pop_back();
        }
    }
    
};
