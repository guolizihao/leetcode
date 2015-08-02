class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        internalSolveSudoku(board);
    }
    bool internalSolveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (int k = 1; k <= 9; k++) {
                        board[i][j] = k + '0';
                        if (isVaildSudoku(board, i, j) && internalSolveSudoku(board)) {
                            return true;
                        }
                    }
                    board[i][j] = '.';  
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isVaildSudoku(vector<vector<char>> &board, int x, int y) {
        for (int row = 0; row < 9; row++) {
            if (row != x && board[row][y] == board[x][y]) return false;
        }
        for (int col = 0; col < 9; col++) {
            if (col != y && board[x][col] == board[x][y]) return false;
        }
        for (int row = x / 3 * 3; row < (x / 3 + 1) * 3; row++) {
            for (int col = y / 3 * 3; col < (y / 3 + 1) * 3; col++) {
                if (row != x && col != y && board[row][col] == board[x][y]) return false;
            }
        }
        return true;
    }
};

