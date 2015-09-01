// https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        int num = 0, sum = 0;
        sumNumbers(root, sum, num);
        return sum;
    }
    
    void sumNumbers(TreeNode *root, int &sum, int num) {
        if (!root) return;
        num = num * 10 + root->val;
        if (!root->left && !root->right) {
            sum += num;
            return;
        }
        sumNumbers(root->left, sum, num);
        sumNumbers(root->right, sum, num);
    }
};
