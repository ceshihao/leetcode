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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        stack<TreeNode *> node_stack;
        node_stack.push(q);
        node_stack.push(p);
        while (!node_stack.empty())
        {
            p = node_stack.top();
            node_stack.pop();
            q = node_stack.top();
            node_stack.pop();
            if (!p && !q)
                continue;
            else if (!p || !q)
                return false;
            else if (p->val != q->val)
                return false;
            else
            {
                node_stack.push(q->right);
                node_stack.push(p->right);
                node_stack.push(q->left);
                node_stack.push(p->left);
            }
        }
        return true;
    }
};