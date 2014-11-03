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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode*> node_stack;
        TreeNode *tmp, *tmp_left, *tmp_right;
        if (root)
        {
            node_stack.push(root);
            while (!node_stack.empty())
            {
                tmp = node_stack.top();
                node_stack.pop();
                if (!tmp->right && !tmp->left)
                    result.push_back(tmp->val);
                else
                {
                    tmp_left = tmp->left;
                    tmp_right = tmp->right;
                    tmp->left = NULL;
                    tmp->right = NULL;
                    node_stack.push(tmp);
                    if (tmp_right)
                        node_stack.push(tmp_right);
                    if (tmp_left)
                        node_stack.push(tmp_left);
                }
            }
        }
        return result;
    }
};