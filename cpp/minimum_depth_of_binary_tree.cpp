/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
        int depth;
        if (!root)
            depth = 0;
        else if (!root->left && !root->right)
            depth = 1;
        else if (root->left && !root->right)
            depth = minDepth(root->left) + 1;
        else if (root->right && !root->left)
            depth = minDepth(root->right) + 1;
        else
            depth = min(minDepth(root->left), minDepth(root->right)) + 1;
        return depth;
    }
};