# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of integers
    def inorderTraversal(self, root):
        result = []
        while root != None:
            if root.left == None:
                result.append(root.val)
                prev = root
                root = root.right
            else:
                prev = root.left
                while prev.right != None and prev.right != root:
                    prev = prev.right
                if prev.right == None:
                    prev.right = root
                    root = root.left
                elif prev.right == root:
                    prev.right = None
                    result.append(root.val)
                    root = root.right
        return result