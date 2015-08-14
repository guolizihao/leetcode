// https://leetcode.com/problems/n-queens/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> solution(n, string(n, '.'));
        DFS(0, solution, res);
        return res;
    }
    void DFS(int row, vector<string> &solution, vector<vector<string>> &res) {
        if (solution.size() == row) {
            res.push_back(solution);
            return;
        }
        for (int col = 0; col < solution.size(); ++col) {
            if (IsValid(solution, row, col)) {
                solution[row][col] = 'Q';
                DFS(row + 1, solution, res);
                solution[row][col] = '.';
                
            }
        }
    }
    
    bool IsValid(vector<string> &solution, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (solution[i][col] == 'Q') return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (solution[i][j] == 'Q') return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < solution.size(); --i, ++j) {
            if (solution[i][j] == 'Q') return false;
        }
        return true;
    }
};
