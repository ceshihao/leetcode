/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    return addTwoNumbersJinwei(l1, l2, 0)
}

func addTwoNumbersJinwei(l1 *ListNode, l2 *ListNode, jinwei int) *ListNode {
    if l1 == nil && l2 == nil && jinwei == 0 {
        return nil
    } else if l1 == nil && jinwei == 0 {
        return l2
    } else if l2 == nil && jinwei == 0 {
        return l1
    } else {
        var val1 int
        var l1Next *ListNode
        if l1 == nil {
            val1 = 0
            l1Next = nil
        } else {
            val1 = l1.Val
            l1Next = l1.Next
        }
        var val2 int
        var l2Next *ListNode
        if l2 == nil {
            val2 = 0
            l2Next = nil
        } else {
            val2 = l2.Val
            l2Next = l2.Next
        }
        val := val1 + val2 + jinwei
        if val >= 10 {
            val = val - 10
            jinwei = 1
        } else {
            jinwei = 0
        }
        return &ListNode{
            Val: val,
            Next: addTwoNumbersJinwei(l1Next, l2Next, jinwei),
        }
    }
}
