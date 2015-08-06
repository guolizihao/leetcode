//https://leetcode.com/problems/word-search-ii/

class Solution {
public:
    struct TrieNode {
        TrieNode *child[26];
        string str;
        TrieNode () {
            str = "";
            for (auto &a : child) {
                a = NULL;
            }
        }
    };
    
    struct Trie {
        TrieNode *root;
        Trie() {
            root = new TrieNode();
        }
        void Insert(string s) {
            TrieNode *p = root;
            for (auto &a : s) {
                int i = a -'a';
                if (p->child[i] == NULL) p->child[i] = new TrieNode();
                p = p->child[i];
            }
            p->str = s;
        }
    };
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (board.size() == 0 || board[0].size() == 0 || words.size() == 0) return res;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        Trie T;
        for (auto &a : words) T.Insert(a);
        for (int i = 0; i < board.size(); i++) {
            for (int j  = 0; j < board[i].size(); j++) {
                if (T.root->child[board[i][j] - 'a'] != NULL) {
                    Search(board, T.root->child[board[i][j] - 'a'], i, j, visited, res);
                }
            }
        }
        return res;
    }
    void Search(vector<vector<char>> &board, TrieNode *p, int i, int j, vector<vector<bool>> &visited, vector<string> &res) {
        if (p->str.size() != NULL) {
            res.push_back(p->str);
            p->str.clear();
        }
        visited[i][j] = true;
        int d[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto &a : d) {
            int nx = a[0] + i, ny = a[1] + j;
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && 
            visited[nx][ny] == NULL && p->child[board[nx][ny] - 'a'] != NULL) {
                Search(board, p->child[board[nx][ny] - 'a'], nx, ny, visited, res);
            }
        }
        // if (i - 1 >= 0 && i - 1 < board.size() && j >= 0 && j < board[0].size() 
        // && visited[i - 1][j] == false && p->child[board[i - 1][j] - 'a'] != NULL) {
        //     Search(board, p->child[board[i - 1][j] - 'a'], i - 1, j, visited, res);
        // }
        // if (i + 1 >= 0 && i + 1 < board.size() && j >= 0 && j < board[0].size() 
        // && visited[i + 1][j] == false && p->child[board[i + 1][j] - 'a'] != NULL) {
        //     Search(board, p->child[board[i + 1][j] - 'a'], i + 1, j, visited, res);
        // }
        // if (i >= 0 && i < board.size() && j - 1>= 0 && j - 1 < board[0].size() 
        // && visited[i][j - 1] == false && p->child[board[i][j - 1] - 'a'] != NULL) {
        //   Search(board, p->child[board[i][j - 1] - 'a'], i, j - 1, visited, res);
        // }
        // if (i >= 0 && i < board.size() && j + 1>= 0 && j + 1 < board[0].size() 
        // && visited[i][j + 1] == false && p->child[board[i][j + 1] - 'a'] != NULL) {
        //   Search(board, p->child[board[i][j + 1] - 'a'], i, j + 1, visited, res);
        // }
        visited[i][j] = false;
    }
    
};
