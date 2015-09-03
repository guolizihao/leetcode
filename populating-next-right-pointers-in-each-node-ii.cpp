// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        while(root) {
            TreeLinkNode *next = NULL, *pre = NULL;
            //prev记录当前层的前一节点
            //next记录下一层的开始节点
            while (root) {
                if (!next) next = root->left ? root->left : root->right;
                if (root->left) {
                    if (pre) pre->next = root->left;
                    pre = root->left;
                }
                if (root->right) {
                    if (pre) pre->next = root->right;
                    pre = root->right;
                }
                root = root->next;
            }
            root = next;
        }
    }
};

// class Solution {
// public:
//     void connect(TreeLinkNode *root) {
//         if (!root) return;
//         TreeLinkNode *p = root->next;
//         while(p) {
//             if (p->left) {
//                 p = p->left;
//                 break;
//             }
//             if (p->right) {
//                 p = p->right;
//                 break;
//             }
//             p = p->next;
//         }
//         if (root->right) root->right->next = p;
//         if (root->left) root->left->next = root->right ? root->right : p;
//         connect(root->right);
//         connect(root->left);
//     }
// };

// class Solution {
// public:
//     void connect(TreeLinkNode *root) {
//         if (!root) return;
//         queue <TreeLinkNode *> q;
//         q.push(root);
//         q.push(NULL);
//         while (true) {
//             TreeLinkNode *cur = q.front(); q.pop();
//             if (cur) {
//                 cur->next = q.front();
//                 if (cur->left) q.push(cur->left);
//                 if (cur->right) q.push(cur->right);
//             } else {
//                 if (q.empty() || !q.front()) return;
//                 q.push(NULL);
//             }
//         }
//     }
// };
