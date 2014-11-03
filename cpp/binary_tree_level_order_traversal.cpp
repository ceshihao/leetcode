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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (!root) return result;
        queue<TreeNode *> current, next;
        vector<int> level;
        
        current.push(root);
        while (!current.empty())
        {
            while (!current.empty())
            {
                TreeNode * tmp = current.front();
                level.push_back(tmp->val);
                current.pop();
                if (tmp->left) next.push(tmp->left);
                if (tmp->right) next.push(tmp->right);
            }
            result.push_back(level);
            level.clear();
            swap(current, next);
        }
        return result;
    }
};