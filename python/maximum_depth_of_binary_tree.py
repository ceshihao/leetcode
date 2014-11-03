# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return an integer
    def maxDepth(self, root):
        if root == None:
            depth = 0
        else:
            depth = max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1
        return depth