// https://leetcode.com/problems/validate-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // Non-recursion with stack
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if (!root) return true;
        stack<TreeNode*> s;
        TreeNode *p = root;
        TreeNode *pre = NULL;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            if (pre) {
                if (p->val <= pre->val) return false;
            }
            pre = p;
            p = p->right;
        }
        return true;
    }
};
 
 
// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
//         return isValidBST(root, LONG_MIN, LONG_MAX);
//     }
//     bool isValidBST(TreeNode *root, long min_num, long max_num) {
//         if (!root) return true;
//         if (root->val <= min_num || root->val >= max_num) return false;
//         return isValidBST(root->left, min_num, root->val) && isValidBST(root->right, root->val, max_num);
//     }
// };

// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
//         if (!root) return true;
//         vector<int> array;
//         inOrderVisit(root, array);
//         for (int i = 0; i < array.size() - 1; ++i) {
//             if(array[i] >= array[i + 1]) return false;
//         }
//         return true;
//     }
    
//     void inOrderVisit(TreeNode *root, vector<int> &array) {
//         if (!root) return;
//         inOrderVisit(root->left, array);
//         array.push_back(root->val);
//         inOrderVisit(root->right, array);
//     }
// };
