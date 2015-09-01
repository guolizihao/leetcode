// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        stack<TreeNode *> s1, s2;
        s1.push(root);
        vector<int> a;
        while (!s1.empty() || !s2.empty()) {
            while (!s1.empty()) {
                TreeNode *node = s1.top(); s1.pop();
                a.push_back(node->val);
                if (node->left) s2.push(node->left);
                if (node->right) s2.push(node->right);
            }
            if (a.size()) res.push_back(a);
            a.clear();
            while (!s2.empty()) {
                TreeNode *node = s2.top(); s2.pop();
                a.push_back(node->val);
                if (node->right) s1.push(node->right);
                if (node->left) s1.push(node->left);
            }
            if (a.size()) res.push_back(a);
            a.clear();
        }
        return res;
    }
};
