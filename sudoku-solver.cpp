// https://leetcode.com/problems/sudoku-solver/

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if (board.empty() || board.size() != 9 || board[0].size() != 9) return;
        internalSolveSudoku(board);
    }
    bool internalSolveSudoku(vector<vector<char>> &board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (int k = 1; k <= 9; ++k) {
                        board[i][j] = k + '0';
                        if (isValidSudoku(board, i, j) && internalSolveSudoku(board)) return true;
                    }
                    board[i][j] = '.';
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>> &board, int x, int y) {
        for (int row = 0; row < 9; ++row) {
            if (row != x && board[x][y] == board[row][y]) return false;
        }
        for (int col = 0; col < 9; ++col) {
            if (col != y && board[x][y] == board[x][col]) return false;
        }
        for (int row = x / 3 * 3; row < x / 3 * 3 + 3; ++row) {
            for (int col = y / 3 * 3; col < y / 3 * 3 + 3; ++col) {
                if((col != y || row != x) && board[x][y] == board[row][col]) return false;
            }
        }
        return true;
    }
};
