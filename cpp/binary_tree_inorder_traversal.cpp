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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        TreeNode *prev;
        while (root != NULL)
        {
            if (root->left == NULL)
            {
                result.push_back(root->val);
                root = root->right;
            }
            else
            {
                prev = root->left;
                while (prev->right != NULL && prev->right != root)
                    prev = prev->right;
                if (prev->right == NULL)
                {
                    prev->right = root;
                    root = root->left;
                }
                else if (prev->right == root)
                {
                    result.push_back(root->val);
                    prev->right = NULL;
                    prev = root;
                    root = root->right;
                }
            }
        }
        return result;
    }
};