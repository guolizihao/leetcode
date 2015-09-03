// /**
//  * Definition for binary tree with next pointer.
//  * struct TreeLinkNode {
//  *  int val;
//  *  TreeLinkNode *left, *right, *next;
//  *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     void connect(TreeLinkNode *root) {
//         if (!root || !root->left) return;
//         root->left->next = root->right;
//         if (root->next) 
//             root->right->next = root->next->left;
//         connect(root->left);
//         connect(root->right);
//     }
// };

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue <TreeLinkNode *> q;
        q.push(root);
        q.push(NULL);
        while (true) {
            TreeLinkNode *cur = q.front(); q.pop();
            if (cur) {
                cur->next = q.front();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            } else {
                if (q.empty() || !q.front()) return;
                q.push(NULL);
            }
        }
    }
};
