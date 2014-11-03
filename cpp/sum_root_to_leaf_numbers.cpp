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
    int sumNumbers(TreeNode *root) {
        int result = 0;
        if (!root) 
            return result;
        stack<TreeNode *> node_stack;
        node_stack.push(root);
        while (!node_stack.empty())
        {
            TreeNode * tmp = node_stack.top();
            node_stack.pop();
            if (!tmp->left && !tmp->right)
                result += tmp->val;
            else
            {
                if (tmp->right)
                {
                    tmp->right->val += tmp->val * 10;
                    node_stack.push(tmp->right);
                }
                if (tmp->left)
                {
                    tmp->left->val += tmp->val * 10;
                    node_stack.push(tmp->left);
                }
            }
        }
        return result;
    }
};