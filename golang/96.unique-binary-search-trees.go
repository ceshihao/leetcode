/*
 * @lc app=leetcode id=96 lang=golang
 *
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (44.91%)
 * Total Accepted:    188.6K
 * Total Submissions: 415.8K
 * Testcase Example:  '3'
 *
 * Given n, how many structurally unique BST's (binary search trees) that store
 * values 1 ... n?
 *
 * Example:
 *
 *
 * Input: 3
 * Output: 5
 * Explanation:
 * Given n = 3, there are a total of 5 unique BST's:
 *
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 *
 *
 */
var numTreesMap = make(map[int]int)

func numTrees(n int) int {
	if n < 2 {
		return 1
	}
	res := 0
	for i := 0; i < n; i++ {
		if _, ok := numTreesMap[i]; !ok {
			numTreesMap[i] = numTrees(i)
		}
		if _, ok := numTreesMap[n-1-i]; !ok {
			numTreesMap[n-1-i] = numTrees(n - 1 - i)
		}
		res += numTreesMap[i] * numTreesMap[n-1-i]
	}
	return res
}

