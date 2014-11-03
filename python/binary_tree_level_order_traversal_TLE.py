# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of lists of integers
    def levelOrder(self, root):
        result = []
        if root == None:
            return result
        row = []
        stack = []
        stack.append(root)
        while len(stack) > 0:
            tmp = []
            for item in stack:
                row.append(item.val)
                if item.left != None:
                    tmp.append(item.left)
                if item.right != None:
                    tmp.append(item.right)
            stack = tmp
            result.append(row)
        return result