// https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> row_flag(m, vector<bool>(n, false));
        vector<vector<bool>> col_flag(m, vector<bool>(n, false));
        vector<vector<bool>> cell_flag(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] >= '1' && board[i][j] <= '9') {
                    int c = board[i][j] - '1';
                    if (row_flag[i][c] || col_flag[c][j] || cell_flag[3 * (i / 3) + j / 3][c]) return false;
                    row_flag[i][c] = true;
                    col_flag[c][j] = true;
                    cell_flag[3 * (i / 3) + j / 3][c] = true;
                }
            }
        }
        return true;
    }
};
