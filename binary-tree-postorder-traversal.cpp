// https://leetcode.com/problems/binary-tree-postorder-traversal/

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        TreeNode *pre = NULL;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *curr = s.top();
            if ((!curr->left && !curr->right) // curr为叶子节点
                || (pre && (curr->left == pre || curr->right ==pre))) {//curr的子节点都已经访问
                s.pop();
                res.push_back(curr->val);
                pre = curr;
            } else {
                if (curr->right) s.push(curr->right);
                if (curr->left) s.push(curr->left);
            }
        }
        return res;
    }
};
