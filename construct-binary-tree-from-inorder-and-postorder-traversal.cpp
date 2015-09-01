// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    TreeNode *buildTree(vector<int> &inorder, int in_start, int in_end, 
                        vector<int> &postorder, int post_start, int post_end) {
        if (post_start > post_end || in_start > in_end) return NULL;
        TreeNode *root = new TreeNode(postorder[post_end]);
        int i;
        for (i = 0; i < in_end; i++) {
            if(inorder[in_end - i] == root->val) break;
        }
        root->left = buildTree(inorder, in_start, in_end - i - 1, postorder, post_start, post_end - i - 1);
        root->right = buildTree(inorder, in_end - i + 1, in_end, postorder, post_end - i, post_end - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.empty() || inorder.empty() || postorder.size() != inorder.size()) return NULL;
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};
