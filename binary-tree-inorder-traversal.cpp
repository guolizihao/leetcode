// https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        TreeNode *node = root;
        stack<TreeNode *> s;
        while (!s.empty() || node) {
            while (node) {
                s.push(node);
                node = node->left;
            }
            node = s.top(); s.pop();
            res.push_back(node->val);
            node = node->right;
        }
        return res;
    }
};

// class Solution {
// public:
//     vector<int> ret;
//     vector<int> inorderTraversal(TreeNode* root) {
//         if (root == NULL) return ret;
//         inorderTraversal(root->left);
//         ret.push_back(root->val);
//         inorderTraversal(root->right);
//         return ret;
//     }
// };
