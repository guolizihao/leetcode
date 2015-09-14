// https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0, m = grid.size();
        for (int i = 0; i < m; ++i) {
            int n = grid[i].size();
            for (int j = 0; j < n; ++j) {
                if (DFS(grid, i, j)) ++res;
            }
        }
     return res;   
    }
    
    bool DFS(vector<vector<char>> &grid, int i, int j) {
        if (i >= 0 && i < grid.size() && j >= 0 && j <grid[i].size() && grid[i][j] == '1') {
            grid[i][j] = '5';
            DFS(grid, i - 1, j);
            DFS(grid, i + 1, j);
            DFS(grid, i, j - 1);
            DFS(grid, i, j + 1);
            return true;
        }
        return false;
    }
};
