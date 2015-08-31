// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        levelOrderDFS(root, 0, res);
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

// iteratively

// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> res;
//         if (!root) return res;
//         int count = 1;
//         queue <TreeNode *> q;
//         q.push(root);
//         while (!q.empty()) {
//             vector<int> a;
//             int temp_count = 0;
//             while (count > 0) {
//                 TreeNode *node = q.front();
//                 q.pop();
//                 a.push_back(node->val);
//                 if (node->left) {
//                     q.push(node->left);
//                     ++temp_count;
//                 }
//                 if (node->right) {
//                     q.push(node->right);
//                     ++temp_count;
//                 }
//                 --count;
//             }
//             res.push_back(a);
//             count = temp_count;
//         }
//         return res;
//     }
// };
