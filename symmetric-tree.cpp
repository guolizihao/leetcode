/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// recursively
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode *left_node, TreeNode *right_node) {
        if (!left_node && !right_node) return true;
        if (!left_node || !right_node) return false;
        if (left_node->val != right_node->val) return false;
        return isSymmetric(left_node->left, right_node->right) && isSymmetric(left_node->right, right_node->left);
    }
};

// iteratively
// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//         if (root == NULL) return true;
//         stack<TreeNode *> left_tree, right_tree;
//         left_tree.push(root->left);
//         right_tree.push(root->right);
        
//         while (left_tree.size() > 0 && right_tree.size() > 0) {
//             TreeNode *left_node = left_tree.top();
//             left_tree.pop();
//             TreeNode *right_node = right_tree.top();
//             right_tree.pop();
//             if (left_node == NULL && right_node == NULL) continue;
//             if (left_node == NULL || right_node == NULL) return false;
//             if (left_node->val == right_node->val) {
//                 left_tree.push(left_node->right);
//                 left_tree.push(left_node->left);
//                 right_tree.push(right_node->left);
//                 right_tree.push(right_node->right);
//             } else {
//                 return false;
//             }
//         }
//         return true;
//     }
// };
