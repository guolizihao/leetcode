// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
    TreeNode *pre = NULL;
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode *last_right = root->right;
        if (pre) {
            pre->left = NULL;
            pre->right = root;
        }
        pre = root;
        flatten(root->left);
        flatten(last_right);
    }
};
