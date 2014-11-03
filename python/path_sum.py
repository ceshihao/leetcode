# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @param sum, an integer
    # @return a boolean
    def hasPathSum(self, root, sum):
        if root == None:
            return False
        elif root.left == None and root.right == None:
            if root.val == sum:
                return True
            else:
                return False
        else:
            return self.hasPathSum(root.right, sum-root.val) or self.hasPathSum(root.left, sum-root.val)