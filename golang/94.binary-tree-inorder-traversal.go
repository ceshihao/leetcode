/*
 * @lc app=leetcode id=94 lang=golang
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (54.80%)
 * Total Accepted:    423.3K
 * Total Submissions: 763.3K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * Example:
 *
 *
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 *
 * Output: [1,3,2]
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 *
 */

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func inorderTraversal(root *TreeNode) []int {
	if root == nil {
		return []int{}
	}
	res := make([]int, 0)
	stack := make([]*TreeNode, 0)
	stack = push(stack, root)

	var node *TreeNode
	for len(stack) != 0 {
		stack, node = pop(stack)
		if node.Left == nil {
			res = append(res, node.Val)
		}
		if node.Right != nil {
			stack = push(stack, node.Right)
			node.Right = nil
		}

		if node.Left != nil {
			stack = push(stack, node)
			stack = push(stack, node.Left)
			node.Left = nil
		}
	}
	return res
}

func push(stack []*TreeNode, ele *TreeNode) []*TreeNode {
	return append(stack, ele)
}

func pop(stack []*TreeNode) ([]*TreeNode, *TreeNode) {
	length := len(stack)
	if length == 0 {
		return []*TreeNode{}, nil
	}
	return stack[:len(stack)-1], stack[len(stack)-1]
}
