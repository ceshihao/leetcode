/*
 * @lc app=leetcode id=993 lang=golang
 *
 * [993] Cousins in Binary Tree
 *
 * https://leetcode.com/problems/cousins-in-binary-tree/description/
 *
 * algorithms
 * Easy (54.18%)
 * Total Accepted:    6.5K
 * Total Submissions: 12K
 * Testcase Example:  '[1,2,3,4]\n4\n3'
 *
 * In a binary tree, the root node is at depth 0, and children of each depth k
 * node are at depth k+1.
 *
 * Two nodes of a binary tree are cousins if they have the same depth, but have
 * different parents.
 *
 * We are given the root of a binary tree with unique values, and the values x
 * and y of two different nodes in the tree.
 *
 * Return true if and only if the nodes corresponding to the values x and y are
 * cousins.
 *
 *
 *
 * Example 1:
 *
 *
 *
 * Input: root = [1,2,3,4], x = 4, y = 3
 * Output: false
 *
 *
 *
 * Example 2:
 *
 *
 *
 * Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
 * Output: true
 *
 *
 *
 * Example 3:
 *
 *
 *
 *
 * Input: root = [1,2,3,null,4], x = 2, y = 3
 * Output: false
 *
 *
 *
 *
 *
 * Note:
 *
 *
 * The number of nodes in the tree will be between 2 and 100.
 * Each node has a unique integer value from 1 to 100.
 *
 *
 *
 *
 *
 *
 *
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
func isCousins(root *TreeNode, x int, y int) bool {
	nodeSlice := []*TreeNode{root}
	return isCousinsNodeSlice(nodeSlice, x, y)
}

func isCousinsNodeSlice(nodeSlice []*TreeNode, x, y int) bool {
	newNodeSlice := make([]*TreeNode, 0)
	valExist := false
	indexExist := -1
	for index, node := range nodeSlice {
		if node != nil {
			if node.Val == x || node.Val == y {
				if valExist {
					if index%2 == 1 && index == indexExist+1 {
						return false
					}
					return true
				}
				valExist = true
				indexExist = index
			}
			newNodeSlice = append(newNodeSlice, node.Left, node.Right)
		}
	}
	if valExist {
		return false
	}
	return isCousinsNodeSlice(newNodeSlice, x, y)
}
