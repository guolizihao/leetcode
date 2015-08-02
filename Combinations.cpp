class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> solution;
        Comb(n, k, 1, solution);
        return res;
    }
    
    void Comb(int n, int k, int start, vector<int> &solution) {
        if (k == 0) {
            res.push_back(solution);
            return;
        }
        for (int i = start; i <= n; i++) {
            solution.push_back(i);
            Comb(n, k - 1, i + 1, solution);
            solution.pop_back();
        }
    }
};
