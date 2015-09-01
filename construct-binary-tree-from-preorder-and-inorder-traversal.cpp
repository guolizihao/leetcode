// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size()) return NULL;
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    
    TreeNode* buildTree(vector<int> &preorder, int pre_start, int pre_end, 
                        vector<int> &inorder, int in_start, int in_end) {
        if (pre_start > pre_end || in_start > in_end) return NULL;
        TreeNode *root = new TreeNode(preorder[pre_start]);
        int i;
        for (i = 0; i < in_end; ++i) {
            if (preorder[pre_start] == inorder[in_start + i]) break;
        }
        root->left = buildTree(preorder, pre_start + 1, pre_start + i, inorder, in_start, in_start + i - 1);
        root->right = buildTree(preorder, pre_start + i + 1, pre_end, inorder, in_start + i + 1, in_end);
        return root;
    }
};
