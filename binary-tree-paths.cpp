//https://leetcode.com/problems/binary-tree-paths/

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == NULL) return res;
        string solution;
        DFS(res, solution, root);
        return res;
    }
    
    // void itoa(int val, char *str) {
    //     if (val == 0) {
    //         str[0] = '0';
    //         str[1] = '\0';
    //         return;
    //     }
    //     int i = 0;
    //     if (val < 0) {
    //         str[i++] = '-';
    //         val = -val;
    //     }
    //     int start = i;
    //     while (val > 0) {
    //         str[i++] = val % 10 + '0';
    //         val /= 10;
    //     }
    //     str[i] = '\0';
    //     reverse(str + start, str + i);
    //     return;
    // }
    
    void itoa(int val, string &str) {
        if (val == 0) {
            str.push_back('0');
            return;
        }
        int i = 0;
        if (val < 0) {
            str.push_back('-');
            val = -val;
            ++i;
        }
        int start = i;
        while (val > 0) {
            str.push_back(val % 10 + '0');
            val /= 10;
            ++i;
        }
        reverse(str.begin() + start, str.begin() + i);
        return;
    }
    
    void DFS(vector<string> &res, string solution, TreeNode *root) {
        if (root == NULL) {
            return;
        }
        //char str[30];
        string str;
        itoa(root->val, str);
        solution += str;
        if (root->left == NULL && root->right == NULL) {
            res.push_back(solution);
            return;
        }
        solution += "->";
        if (root->left != NULL) {
            DFS(res, solution, root->left);
        }
        if (root->right != NULL) {
            DFS(res, solution, root->right);
        }
    }
};
