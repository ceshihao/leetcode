/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func detectCycle(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	fast := head
	slow := head
	for {
		if fast.Next == nil || fast.Next.Next == nil {
			return nil
		}
		fast = fast.Next.Next
		slow = slow.Next
		if fast == slow {
			fast = head
			for {
				if slow == fast {
					return slow
				}
				slow = slow.Next
				fast = fast.Next
			}
		}
	}

}