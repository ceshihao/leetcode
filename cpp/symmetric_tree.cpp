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
    bool isSymmetric(TreeNode *root) {
        if (!root)
            return true;
        stack<TreeNode *> node_stack;
        TreeNode *left, *right;
        node_stack.push(root->left);
        node_stack.push(root->right);
        while (!node_stack.empty())
        {
            right = node_stack.top();
            node_stack.pop();
            left = node_stack.top();
            node_stack.pop();
            if (!left && !right)
                continue;
            else if (!left || !right)
                return false;
            else if (left->val != right->val)
                return false;
            else
            {
                node_stack.push(left->left);
                node_stack.push(right->right);
                node_stack.push(left->right);
                node_stack.push(right->left);
            }
        }
        return true;
    }
};