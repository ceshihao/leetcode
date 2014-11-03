# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return an integer
    def minDepth(self, root):
        if root == None:
            depth = 0
        elif root.left == None and root.right == None:
            depth = 1
        elif root.left == None and root.right != None:
            depth = self.minDepth(root.right) + 1
        elif root.right == None and root.left != None:
            depth = self.minDepth(root.left) + 1
        else:
            depth = min(self.minDepth(root.left), self.minDepth(root.right)) + 1
        return depth