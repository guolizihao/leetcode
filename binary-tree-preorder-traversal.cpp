// https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        TreeNode *node;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            node = s.top(); s.pop();
            res.push_back(node->val);
            if (node->right) s.push(node->right);
            if (node->left) s.push(node->left);
        }
        return res;
    }
};


// class Solution {
// public:
//     vector<int> result;
//     vector<int> preorderTraversal(TreeNode* root) {
//         if (root == NULL) return result;
//         result.push_back(root->val);
//         preorderTraversal(root->left);
//         preorderTraversal(root->right);
//         return result;
//     }
// };

// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> res;
//         if (!root) return res;
//         DFS(root, res);
//         return res;
//     }
    
//     void DFS(TreeNode *root, vector<int> &res) {
//         if (!root) return;
//         res.push_back(root->val);
//         DFS(root->left, res);
//         DFS(root->right, res);
//     }
// }; 
