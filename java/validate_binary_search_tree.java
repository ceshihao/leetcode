/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public boolean isValidBST(TreeNode root) {
        return isValidBST(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }
    public boolean isValidBST(TreeNode root, int lower, int upper) {
        if (root == null) return true;
        return root.val > lower && root.val < upper
            && isValidBST(root.left, lower, root.val)
            && isValidBST(root.right, root.val, upper);
    }
};