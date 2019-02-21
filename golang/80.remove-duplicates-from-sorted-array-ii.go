/*
 * @lc app=leetcode id=80 lang=golang
 *
 * [80] Remove Duplicates from Sorted Array II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
 *
 * algorithms
 * Medium (39.39%)
 * Total Accepted:    186.9K
 * Total Submissions: 474.2K
 * Testcase Example:  '[1,1,1,2,2,3]'
 *
 * Given a sorted array nums, remove the duplicates in-place such that
 * duplicates appeared at most twice and return the new length.
 *
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 *
 * Example 1:
 *
 *
 * Given nums = [1,1,1,2,2,3],
 *
 * Your function should return length = 5, with the first five elements of nums
 * being 1, 1, 2, 2 and 3 respectively.
 *
 * It doesn't matter what you leave beyond the returned length.
 *
 * Example 2:
 *
 *
 * Given nums = [0,0,1,1,1,1,2,3,3],
 *
 * Your function should return length = 7, with the first seven elements of
 * nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.
 *
 * It doesn't matter what values are set beyond the returned length.
 *
 *
 * Clarification:
 *
 * Confused why the returned value is an integer but your answer is an array?
 *
 * Note that the input array is passed in by reference, which means
 * modification to the input array will be known to the caller as well.
 *
 * Internally you can think of this:
 *
 *
 * // nums is passed in by reference. (i.e., without making a copy)
 * int len = removeDuplicates(nums);
 *
 * // any modification to nums in your function would be known by the caller.
 * // using the length returned by your function, it prints the first len
 * elements.
 * for (int i = 0; i < len; i++) {
 * print(nums[i]);
 * }
 *
 *
 */
func removeDuplicates(nums []int) int {
	length := len(nums)
	if length == 0 {
		return 0
	}
	curNum := nums[0]
	repeat := false
	behindIndex := 1
	for headIndex := 1; headIndex < length; headIndex++ {
		if nums[headIndex] == curNum {
			if !repeat {
				repeat = true
				nums[behindIndex] = nums[headIndex]
				behindIndex++
			}
		} else {
			curNum = nums[headIndex]
			repeat = false
			nums[behindIndex] = nums[headIndex]
			behindIndex++
		}
	}
	return behindIndex
}
