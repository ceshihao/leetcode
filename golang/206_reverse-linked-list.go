/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
    return reverseListHelp(head, nil)
}

func reverseListHelp(head, end *ListNode) *ListNode {
    if head == nil {
        return end
    }
    tmp := head.Next
    head.Next = end
    return reverseListHelp(tmp, head)
}
