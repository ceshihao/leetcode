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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > result;
        if (!root) return result;
        vector<int> level;
        queue<TreeNode *> current, next;
        current.push(root);
        while (!current.empty())
        {
            while (!current.empty())
            {
                TreeNode * tmp = current.front();
                current.pop();
                level.push_back(tmp->val);
                if (tmp->left) next.push(tmp->left);
                if (tmp->right) next.push(tmp->right);
            }
            result.push_back(level);
            level.clear();
            swap(current, next);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};