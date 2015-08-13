// https://leetcode.com/problems/unique-binary-search-trees-ii/

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
    vector<TreeNode*> createTrees(int start, int end) {
        vector<TreeNode *> results;
        if (start > end) {
            results.push_back(NULL);
        }
        for (int k = start; k <= end; k++) {
            vector<TreeNode *> left = createTrees(start, k - 1);
            vector<TreeNode *> right = createTrees(k + 1, end);
            
            for (int i = 0; i < left.size(); i++) {
                for (int j = 0; j < right.size(); j++) {
                    TreeNode * root = new TreeNode(k);
                    root->left = left[i];
                    root->right = right[j];
                    results.push_back(root);
                }
            }
        }
        return results;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return createTrees(1, n);
    }
};
