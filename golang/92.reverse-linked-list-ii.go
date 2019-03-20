/*
 * @lc app=leetcode id=92 lang=golang
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (33.90%)
 * Total Accepted:    182.3K
 * Total Submissions: 532.8K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Reverse a linked list from position m to n. Do it in one-pass.
 *
 * Note: 1 ≤ m ≤ n ≤ length of list.
 *
 * Example:
 *
 *
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
 *
 *
 */

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseBetween(head *ListNode, m int, n int) *ListNode {
	fakeHead := &ListNode{
		Next: head,
	}
	var mNode, nNode, newHead, temp *ListNode
	cur := fakeHead
	for i := 0; i <= n; i++ {
		if i == m-1 {
			mNode = cur
			nNode = cur.Next
		}
		if i >= m {
			temp = newHead
			newHead = cur
		}
		cur = cur.Next
		if i >= m {
			newHead.Next = temp
		}

	}
	mNode.Next = newHead
	nNode.Next = cur
	return fakeHead.Next
}

