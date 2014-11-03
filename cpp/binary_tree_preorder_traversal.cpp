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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode*> node_stack;
        TreeNode *tmp;
        if (root)
        {
            node_stack.push(root);
            while (!node_stack.empty())
            {
                tmp = node_stack.top();
                node_stack.pop();
                result.push_back(tmp->val);
                if (tmp->right)
                    node_stack.push(tmp->right);
                if (tmp->left)
                    node_stack.push(tmp->left);
            }
        }
        return result;
    }
};