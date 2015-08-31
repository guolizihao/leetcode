// https://leetcode.com/problems/minimum-depth-of-binary-tree/

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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        int left_len = minDepth(root->left);
        int right_len = minDepth(root->right);
        if (!root->left) return 1 + right_len;
        else if (!root->right) return 1 + left_len;
        else return 1 + min(left_len, right_len);
    }
};
