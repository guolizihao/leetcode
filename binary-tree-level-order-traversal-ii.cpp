// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        levelOrderDFS(root, 0, res);
        reverse(res.begin(), res.end());
        return res;
    }
    
    void levelOrderDFS(TreeNode *root, int depth, vector<vector<int>> &res) {
        if (!root) return;
        if (res.size() > depth) {
            res[depth].push_back(root->val);
        } else {
            vector<int> a;
            a.push_back(root->val);
            res.push_back(a);
        }
        levelOrderDFS(root->left, depth + 1, res);
        levelOrderDFS(root->right, depth + 1, res);
    }
};
