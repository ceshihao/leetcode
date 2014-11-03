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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (!root) return result;
        vector<int> level;
        queue<TreeNode *> current, next;
        current.push(root);
        int flag = 1;
        while(!current.empty())
        {
            while(!current.empty())
            {
                TreeNode * tmp = current.front();
                current.pop();
                level.push_back(tmp->val);
                if (tmp->left) next.push(tmp->left);
                if (tmp->right) next.push(tmp->right);
            }
            if (flag == -1)
                reverse(level.begin(), level.end());
            result.push_back(level);
            level.clear();
            swap(current, next);
            flag *= -1;
        }
        return result;
    }
};