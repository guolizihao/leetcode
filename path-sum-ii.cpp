// https://leetcode.com/problems/path-sum-ii/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<int> out;
        DFS(root, sum, res, out);
        return res;
    }
    void DFS(TreeNode *root, int sum, vector<vector<int>> &res, vector<int> &out) {
        out.push_back(root->val);
        if (sum == root->val && !root->left && !root->right) {
            res.push_back(out);
            return;
        }
        if(root->left) {
            DFS(root->left, sum - root->val, res, out);
            out.pop_back();
        }
        if(root->right) {
            DFS(root->right, sum - root->val, res, out);
            out.pop_back();
        }
    }
};
