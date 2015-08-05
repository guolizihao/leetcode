//https://leetcode.com/problems/word-search/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || board[0].size() == 0) return false;
        if (word.size() == 0) return true;
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (IsStringExist(board, word, 0, i, j, visited)) return true;
            }
        }
        return false;
    }
    
    bool IsStringExist(vector<vector<char>> &board, string word, int count, int i, int j, vector<vector<int>> &visited) {
        if (count == word.size()) return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || visited[i][j] == true || board[i][j] != word[count]) {
            return false;
        }
        visited[i][j] = true;
        bool res = IsStringExist(board, word, count + 1, i - 1, j, visited) || 
                   IsStringExist(board, word, count + 1, i + 1, j, visited) ||     
                   IsStringExist(board, word, count + 1, i, j - 1, visited) ||
                   IsStringExist(board, word, count + 1, i, j + 1, visited);
        visited[i][j] = false;
        return res;
    }
};
