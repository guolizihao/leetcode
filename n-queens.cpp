// https://leetcode.com/problems/n-queens/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> pos(n, -1);
        DFS(res, pos, 0);
        return res;
    }
    
    void DFS(vector<vector<string>> &res, vector<int> &pos, int row) {
        int n = pos.size();
        if (n == row) {
            vector<string> vs(n, string(n, '.'));
            for (int i = 0; i < n; ++i) {
                vs[i][pos[i]] = 'Q';
            }
            res.push_back(vs);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (isValid(pos, row, col)) {
                pos[row] = col;
                DFS(res, pos, row + 1);
                pos[row] = -1;
            }
        }
    }
    
    bool isValid(vector<int> &pos, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (pos[i] == col || (abs(i - row) == abs(pos[i] - col))) return false;
        }
        return true;
    }
};

// class Solution {
// public:
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> res;
//         vector<string> solution(n, string(n, '.'));
//         DFS(0, solution, res);
//         return res;
//     }
//     void DFS(int row, vector<string> &solution, vector<vector<string>> &res) {
//         if (solution.size() == row) {
//             res.push_back(solution);
//             return;
//         }
//         for (int col = 0; col < solution.size(); ++col) {
//             if (IsValid(solution, row, col)) {
//                 solution[row][col] = 'Q';
//                 DFS(row + 1, solution, res);
//                 solution[row][col] = '.';
//             }
//         }
//     }
    
//     bool IsValid(vector<string> &solution, int row, int col) {
//         for (int i = 0; i < row; ++i) {
//             if (solution[i][col] == 'Q') return false;
//         }
//         for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
//             if (solution[i][j] == 'Q') return false;
//         }
//         for (int i = row - 1, j = col + 1; i >= 0 && j < solution.size(); --i, ++j) {
//             if (solution[i][j] == 'Q') return false;
//         }
//         return true;
//     }
// };

