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
        connect(root, NULL);
    }
    
    void connect(TreeLinkNode *root, TreeLinkNode *right){
        if (!root)
            return;
        root->next = right;
        if (root->left)
        {
            connect(root->left, root->right);
            if (right)
                connect(root->right, right->left);
            else
                connect(root->right, NULL);
        }

    }
};