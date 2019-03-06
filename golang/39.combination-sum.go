/*
 * @lc app=leetcode id=39 lang=golang
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (46.48%)
 * Total Accepted:    306.6K
 * Total Submissions: 656.1K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 *
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 *
 * Note:
 *
 *
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 *
 *
 * Example 1:
 *
 *
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 *
 *
 */import "sort"

func combinationSum(candidates []int, target int) [][]int {
	var res [][]int
	sort.Ints(candidates)
	doCombinationSum(&res, candidates, []int{}, target, 0, 0)
	return res
}

func doCombinationSum(res *[][]int, candidates []int, currentCandidates []int, target, currentSum, index int) {
	if currentSum == target {
		*res = append(*res, currentCandidates)
		return
	}
	if currentSum > target {
		return
	}

	for i := index; i < len(candidates); i++ {
		newCandidates := make([]int, len(currentCandidates)+1)
		copy(newCandidates[:len(currentCandidates)], currentCandidates)
		newCandidates[len(newCandidates)-1] = candidates[i]

		doCombinationSum(res, candidates, newCandidates, target, currentSum+candidates[i], i)
	}
}
