/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode prev = dummy, cur = head;
        int num = dummy.val;
        while (cur != null)
        {
            if (cur.val == num)
                prev.next = cur.next;
            else
            {
                num = cur.val;
                prev = prev.next;
            }
            cur = cur.next;
        }
        return head;
    }
}