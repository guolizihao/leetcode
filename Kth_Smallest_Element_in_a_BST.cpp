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
    int kthSmallest(TreeNode* root, int k) {
        int left_depth = depth(root->left);
        if (left_depth + 1 == k) {
            return root->val;
        } else if (left_depth + 1 < k) {
            return kthSmallest(root->right, k - left_depth -1);
        } else {
            return kthSmallest(root->left, k);
        }
    }
    
    int depth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        return depth(root->left) + depth(root->right) + 1;
    }
};



// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         stack<TreeNode *> stk;
//         TreeNode *node = root;
//         int count = 0;
//         while (node != NULL) {
//             stk.push(node);
//             node = node->left;
//         }
//         while (!stk.empty()) {
//             node = stk.top();
//             stk.pop();
//             count++;
//             if (count == k) return node->val;
//             node = node->right;
//             while (node != NULL) {
//                 stk.push(node);
//                 node = node->left;
//             }
//         }
//     }
// };
