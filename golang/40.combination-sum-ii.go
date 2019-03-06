/*
 * @lc app=leetcode id=40 lang=golang
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (39.97%)
 * Total Accepted:    202.1K
 * Total Submissions: 502.4K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 *
 * Each number in candidates may only be used once in the combination.
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
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 *
 *
 */import (
	"fmt"
	"sort"
)

func combinationSum2(candidates []int, target int) [][]int {
	var res [][]int
	existMap := make(map[string]bool)
	sort.Ints(candidates)
	doCombinationSum2(&res, &existMap, candidates, []int{}, target, 0, 0)
	return res
}

func doCombinationSum2(res *[][]int, existMap *map[string]bool, candidates []int, currentCandidates []int, target, currentSum, index int) {
	if currentSum == target {
		if _, ok := (*existMap)[fmt.Sprint(currentCandidates)]; !ok {
			*res = append(*res, currentCandidates)
			(*existMap)[fmt.Sprint(currentCandidates)] = true
		}
		return
	}
	if currentSum > target {
		return
	}

	for i := index; i < len(candidates); i++ {
		newCandidates := make([]int, len(currentCandidates)+1)
		copy(newCandidates[:len(currentCandidates)], currentCandidates)
		newCandidates[len(newCandidates)-1] = candidates[i]

		doCombinationSum2(res, existMap, candidates, newCandidates, target, currentSum+candidates[i], i+1)
	}
}
