//https://leetcode.com/problems/kth-smallest-element-in-a-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         int left_depth = depth(root->left);
//         if (1 + left_depth == k) return root->val;
//         else if (1 + left_depth < k) return kthSmallest(root->right, k - 1 - left_depth);
//         else return kthSmallest(root->left, k);
//     }
//     int depth(TreeNode* root) {
//         if (!root) return 0;
//         return 1 + depth(root->left) + depth(root->right);
//     }
// };

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack <TreeNode *> s;
        TreeNode *node = root;
        int count = 0;
        while (node || !s.empty()) {
            while (node) {
                s.push(node);
                node = node->left;
            }
            node = s.top(); s.pop();
            ++count;
            if (count == k) return node->val;
            node = node->right;
        }
    }
};
